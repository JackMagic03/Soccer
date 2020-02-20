/*
Libreria gestione rotazione e velocità dei singoli motori
 */

/*
Matrici per il controllo olonomico dei motori con lo 0° davanti;
Usiamo la stessa logica della bussola Bno055
 */
static double drive_Matrix [NUM_JOINTS][NUM_JOINTS] =
{
  {0.87, 0.50, 1}, //sin T1, cos T1, 1
  {0, -1, 1},     //sin T2, cos T2, 1
  {-0.87, 0.5, 1} //sin T3, cos T3, 1
};

float vel_1, vel_2, vel_3; //Settare le veocità del motore

float vx;       //Componente velocità del'asse X
float vy;       //Componente velocità dell'asse Y
float Rw;       //Velocità angolare
float Dw;       //L'Rw della matrice di Holon

// Convertire i Radianti in Gradi
float drive_radianti(float gradi) { return ( gradi * PI / 180.0 ); }  //PI è una funzione integrata in arduino per il valore di P Greco

//Convertire i Gradi in Radianti
float drive_gradi(float radianti) { return ( radianti * 180.0 / PI ); }

//Inizializzare la Matrice di valori
void drive_init() {
  vx = 0;
  vy = 0;
  Rw = 0;
  Dw = 0;     //Azzero tutti i valori delle variabili di calcolo
  vel_1 = 0;
  vel_2 = 0;
  vel_3 = 0;
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

  Serial.print(vel_1);
  Serial.print(" -- ");
  Serial.print(vel_2);
  Serial.print(" -- ");
  Serial.println(vel_3);

  joints(0, vel_1);
  joints(1, vel_2);
  joints(2, vel_3);

}

void drive_stop() {   //Il robot "Inchioda"
  for(int i = 0; i < 3; i++) {
    digitalWrite(pinA[i], HIGH);
    digitalWrite(pinB[i], HIGH);
    digitalWrite(pinPwm[i], HIGH);
  }
}

void drive_fermo() {  //Il robot rallenta velocemente
  joints(0, 0);
  joints(1, 0);
  joints(2, 0);
}

void drive_spin(int val) {  //Il robot ruota su se stesso
  joints(0, val);
  joints(1, val);
  joints(2, val);
}