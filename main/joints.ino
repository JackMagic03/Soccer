/**
 * libreria gestione motori/joints.
 *
 * @author Massimo Giordano
 */

#define NUM_JOINTS 3

typedef struct {

  uint8_t dir_a[NUM_JOINTS];
  uint8_t dir_b[NUM_JOINTS];
  uint8_t pwm[NUM_JOINTS];

  uint8_t direzione[NUM_JOINTS];
  uint8_t velocita[NUM_JOINTS];

} MorsJoints;

void morsjoints_init(MorsJoints* j, uint8_t t_dir_a[], uint8_t t_dir_b[], uint8_t t_pwm[]) {
  for(int i = 0; i < NUM_JOINTS; i++) {
    j-> dir_a[i] = t_dir_a[i];
    j-> dir_b[i] = t_dir_b[i];
    j-> pwm[i]   = t_pwm[i];
    j-> velocita[i] = 0;
    j-> direzione[i] = 0;

    pinMode(j-> dir_a[i], OUTPUT);
    pinMode(j-> dir_b[i], OUTPUT);
    pinMode(j-> pwm[i], OUTPUT);
  }
}

void morsjoints_setspeed(MorsJoints* j, uint8_t t_joints, int t_vel) {
  /**
   * La variabile joints quando richiamiamo la funzione assume i valori 1, 2 o 3.
   * Quando la passiamo agli array, sottraiamo 1 dato che la numerazione degli array inizia da 0
   */

  if(vel_joints >= 0) {
    j-> velocita[t_joints] = t_vel;
    j-> direzione[t_joints] = HIGH;
  } else {
    j-> velocita[t_joints] = !t_vel;
    j-> direzione[t_joints] = LOW;
  }
  if(j-> velocita[t_joints] > 255) {
    j-> velocita[t_joints] = 255;
  }
}

void morsjoints_handle(MorsJoints* j, uint8_t t_joints) {

  digitalWrite(j-> dir_a[t_joints], j-> direzione[t_joints]);
  digitalWrite(j-> dir_b[t_joints], j-> !direzione[t_joints]);
  analogWrite(j-> pwm[t_joints], j-> velocita[t_joints]);

}




/**
 * Libreria gestione motori/drive.
 *
 * @author Massimo Giordano
 */


#define ANGOLO_MOT_1 60.0
#define ANGOLO_MOT_2 180.0
#define ANGOLO_MOT_3 300.0

#define LIMITE_DW_UP 70.0
#define LIMITE_DW_DOWN -70.0

#define RW 3.0

typedef struct {

  MorsJoints *joints;

  double matrix [NUM_JOINTS][NUM_JOINTS] =
  {
    {0.87, 0.50, 1}, //sin T1, cos T1, 1
    {0, -1, 1},     //sin T2, cos T2, 1
    {-0.87, 0.5, 1} //sin T3, cos T3, 1
  };

  float vel[NUM_JOINTS]; //Le velocità che andranno passate ai motori

  float v_x;       //Componente velocità del'asse X
  float v_y;       //Componente velocità dell'asse Y
  float d_w;       //Velocità angolare
  float r_w;       //Il terzo componente del calcolo della matrice. Usato per la correzione della direzione;

} MorsDrive;

float morsdrive_radianti(float t_gradi) {
  /**
   * Ritorna i radianti di un angolo passato come parametro
   */
  return (t_gradi * PI / 180.0);
}

float morsdrive_gradi(float t_rad) {
  /**
   * Ritorna i gradi dei radianti passati come parametro
   */
  return (t_rad * 180.0 / PI);
}

void morsdrive_init(MorsDrive* d) {
  /**
   * Inizializzare i valori della matrice;
   */
  d-> v_x = 0;
  d-> v_y = 0;
  d-> d_w = 0;
  d-> r_w = 0;

  for(int i = 0; i < NUM_JOINTS; i++) {
    d-> vel[i] = 0;
  }
}

void morsdrive_setspeed(MorsDrive* d, float t_angle, int t_vel, int t_imu) {
  /**
   * Impostare la velocità per ogni singolo motore
   * dati angolo e velocità finale a cui il robot
   * dovrà andare e lettura della bussola.
   */
  /**
   * Ragioniamo senza la conversione da gradi in radianti
   * perché tutti i componenti elettronici del robot ragionano in radianti,
   * tranne la bussola ma in questo caso non importa.
   */
   d-> v_x = t_vel * sin(t_angle);
   d-> v_v = t_vel * cos(t_angle);

   /**
    * Questo passagio serve per portare la lettura della bussola
    * da 0 % 360 a -180 % +180
    */
   if(t_imu < 180) {
     d-> r_w = t_imu; //0 % 360
   } else {
     d-> r_w = t_imu - 360; //-180 % +180
   }

   /**
    * KW è la costante rotativa del robot. È un termine che va regolato
    * quando è stato definito. Più è alto come valore
    * più il robot ruota veloce.
    */
   d-> d_w = d-> r_w * KW;

   if(d-> d_w > LIMITE_DW_UP) {
     d-> d_w = LIMITE_DW_UP;
   }
   if(d-> d_w < LIMITE_DW_DOWN) {
     d-> d_w = LIMITE_DW_DOWN;
   }

   /**
    * Il vero e proprio calcolo delle velocità.
    * Si moltiplicano i termini delle matrici con v_x, v_y e d_w.
    */

    d-> vel[0] = d-> drive_Matrix [0][0] * d-> vx +
                 d-> drive_Matrix [0][1] * d-> vy +
                 d-> drive_Matrix [0][2] * d-> Dw;

    d-> vel[1] = d-> drive_Matrix [1][0] * d-> vx +
                 d-> drive_Matrix [1][1] * d-> vy +
                 d-> drive_Matrix [1][2] * d-> Dw;

    d-> vel[2] = d-> drive_Matrix [2][0] * d-> vx +
                 d-> drive_Matrix [2][1] * d-> vy +
                 d-> drive_Matrix [2][2] * d-> Dw;

   for (int i = 0; i < NUM_JOINTS; i++) {
     /**
      * Passo l'indirizzo del puntatore alla struttura MorsJoints.
      * È come quando passavo l'indisizzo dell'oggetto della struttura nel main.
      *
      * Prima richiamo la funzione setspeed, poi l'handle.
      */
     morsjoints_setspeed(d-> joints, i, d-> vel[i]);
   }
}

void morsdrive_handle(MorsDrive* d) {
  /**
   * Questa funzione serve per dare effettivamente il comando al rotob di muoversi.
   */
  morsjoints_handle(d-> joints, i);
}
