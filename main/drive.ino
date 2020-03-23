/**
 * drive.ino => Gestione velocità dei motori in base alla direzione
 * @author Massimo Giordano
 */
#define ANGOLO_MOT_1 60.0
#define ANGOLO_MOT_2 180.0
#define ANGOLO_MOT_3 300.0

#define LIMITE_DW_UP 70.0
#define LIMITE_DW_DOWN -70.0

#define KW 3.0

struct MorsDrive{
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
};

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
   d-> v_y = t_vel * cos(t_angle);

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

    d-> vel[0] = d-> matrix [0][0] * d-> v_x +
                 d-> matrix [0][1] * d-> v_y +
                 d-> matrix [0][2] * d-> d_w;

    d-> vel[1] = d-> matrix [1][0] * d-> v_x +
                 d-> matrix [1][1] * d-> v_y +
                 d-> matrix [1][2] * d-> d_w;

    d-> vel[2] = d-> matrix [2][0] * d-> v_x +
                 d-> matrix [2][1] * d-> v_y +
                 d-> matrix [2][2] * d-> d_w;

   for (int i = 0; i < NUM_JOINTS; i++) {
     /**
      * Passo l'indirizzo del puntatore alla struttura MorsJoints.
      * È come quando passavo l'indisizzo dell'oggetto della struttura nel main.
      *
      * Prima richiamo la funzione setspeed, poi l'handle.
      */
     morsjoints_setspeed(&joints_handler, i, d-> vel[i]);
   }
}

void morsdrive_handle(MorsDrive* d) {
  /**
   * Questa funzione serve per dare effettivamente il comando al rotob di muoversi.
   */
  for(int i = 0; i < NUM_JOINTS; i++) {
    morsjoints_handle(&joints_handler, i);
  }
}
