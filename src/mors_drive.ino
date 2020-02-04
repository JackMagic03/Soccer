/*
Libreria gestione rotazione e velocità dei singoli motori
 */

float vel_1, vel_2, vel_3; //Settare le veocità del motore

/*
Matrici per il controllo olonomico dei motori con lo 0° a destra
{
  {-0.5, 1, -0.5},  //I valori di -sin T1, T2 e T3
  {0.86, 0, -0.86}, //I valori di cos T1, T2 e T3
  {1, 1, 1}         //Chiedere al prof se è lo stesso di KW
};
static double drive_iMatrix [N_Mot][N_Mot] =  //La matrice inversa
{
  {-0.33, 0.58, 0.33},
  {0.66, 0, 0.33},
  {-0.33, -0.58, 0.33}
};
*/

/*
Matrici per il controllo olonomico dei motori con lo 0° davanti;
Usiamo la stessa logica della bussola Bno055
 */
static double drive_Matrix [N_Mot][N_Mot] =
{
  {0.87, 0.50, 1}, //sin T1, cos T1, 1
  {0, -1, 1},     //sin T2, cos T2, 1
  {-0.87, 0.5, 1} //sin T3, cos T3, 1
};

float angolo_1, angolo_2, angolo_3;

// Convertire i Radianti in Gradi
float drive_radianti(float gradi) { return ( gradi * PI / 180.0 ); }  //PI è una funzione integrata in arduino per il valore di P Greco

//Convertire i Gradi in Radianti
float drive_gradi(float radianti) { return ( radianti * 180.0 / PI ); }

//Inizializzare la Matrice di valori
void drive_init() {

  angolo_1 = drive_radianti(angoloMot_1);
  angolo_2 = drive_radianti(angoloMot_2);
  angolo_3 = drive_radianti(angoloMot_3);

  vx = 0;
  vy = 0;
  Rw = 0;
  Dw = 0;     //Azzero tutti i valori delle variabili di calcolo
  vel_1 = 0;
  vel_2 = 0;
  vel_3 = 0;

  // drive_Matrix [0] [0] = sin(angolo_1);
  // drive_Matrix [1] [0] = sin(angolo_2);
  // drive_Matrix [2] [0] = sin(angolo_3);

  // drive_Matrix [0] [1] = cos(angolo_1);
  // drive_Matrix [1] [1] = cos(angolo_2);
  // drive_Matrix [2] [1] = cos(angolo_3);

  // drive_Matrix [0] [2] = 1;
  // drive_Matrix [1] [2] = 1;
  // drive_Matrix [2] [2] = 1;

  // Serial.print(drive_Matrix [0] [0]);
  // Serial.print(" - ");
  // Serial.print(drive_Matrix [0] [1]);
  // Serial.print(" - ");
  // Serial.println(drive_Matrix [0] [2]);
  // Serial.print(drive_Matrix [1] [0]);
  // Serial.print(" - ");
  // Serial.print(drive_Matrix [1] [1]);
  // Serial.print(" - ");
  // Serial.println(drive_Matrix [1] [2]);
  // Serial.print(drive_Matrix [2] [0]);
  // Serial.print(" - ");
  // Serial.print(drive_Matrix [2] [1]);
  // Serial.print(" - ");
  // Serial.println(drive_Matrix [2] [2]);

}

//Funzione che gestisce tutte le direzioni dei motori
void drive_Go( int angolo, int velocita, int my_bussola) {

  vx = velocita * sin ( drive_radianti (angolo - 270) ); //Sarebbe 360 - angolo, ma così facendo
  vy = velocita * cos ( drive_radianti (angolo - 270) ); //il robot va avanti a 0° e a sinistra a 90°

  //Portare la bussola da 0 - 360 a -180 - +180
  if(my_bussola <= 180) Rw = my_bussola;
  else                  Rw = my_bussola - 360;

  Dw = Rw * KW; //Dw è il terzo termine della matrice, Wr è la velocità di rotazione e KW è una costante che va regolata

  if(Dw > limiteDw_Up)   Dw = limiteDw_Up;
  if(Dw < limiteDw_Down) Dw = limiteDw_Down;

  vel_1 = drive_Matrix [0][0] * vx + drive_Matrix [0][1] * vy + drive_Matrix [0][2] * Dw;
  vel_2 = drive_Matrix [1][0] * vx + drive_Matrix [1][1] * vy + drive_Matrix [1][2] * Dw;
  vel_3 = drive_Matrix [2][0] * vx + drive_Matrix [2][1] * vy + drive_Matrix [2][2] * Dw;
  
  /*
  I calcoli per sapere le velocità e le direzioni dei singoli motori tramite le
  moltiplicazioni "riga * colonna"
   */

  if ( vel_1 > 255 )  vel_1 = 255;
  if ( vel_2 > 255 )  vel_2 = 255;
  if ( vel_3 > 255 )  vel_3 = 255;
  if ( vel_1 < - 255 ) vel_1 = -255;
  if ( vel_2 < - 255 ) vel_2 = -255;
  if ( vel_3 < - 255 ) vel_3 = -255;

  joints(1, vel_1);
  joints(2, vel_2);
  joints(3, vel_3);

}

void drive_stop() {   //Il robot "Inchioda"

  digitalWrite(pinA[0], HIGH);
  digitalWrite(pinA[1], HIGH);
  digitalWrite(pinA[2], HIGH);

  digitalWrite(pinB[0], HIGH);
  digitalWrite(pinB[1], HIGH);
  digitalWrite(pinB[2], HIGH);

  digitalWrite(pinPwm[0], HIGH);
  digitalWrite(pinPwm[1], HIGH);
  digitalWrite(pinPwm[2], HIGH);

}

void drive_fermo() {  //Il robot rallenta velocemente

  joints(1, 0);
  joints(2, 0);
  joints(3, 0);

}

void drive_spin(int val) {  //Il robot ruota su se stesso

  joints(1, val);
  joints(2, val);
  joints(3, val);

}
