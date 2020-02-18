#include "mors_drive.h"
//#include "mors_params.h"

#define angoloMot_0 60.0
#define angoloMot_1 180.0
#define angoloMot_2 300.0

#define limiteDw_Up 70.0
#define limiteDw_Down -70.0
#define KW 3.0

PhoenixDrive* d;
PhoenixDrive drive;

static double drive_Matrix [NUM_JOINTS][NUM_JOINTS] =
{
  {0.87, 0.50, 1}, // -sin T1, cos T1, 1
  {0, -1, 1},      // -sin T2, cos T2, 1
  {-0.87, 0.5, 1}  // -sin T3, cos T3, 1
};

// Convertire i Radianti in Gradi
float drive_radianti(float gradi) { return ( gradi * PI / 180.0 ); }  //PI è una funzione integrata in arduino per il valore di P Greco

//Convertire i Gradi in Radianti
float drive_gradi(float radianti) { return ( radianti * 180.0 / PI ); }

void PhoenixDrive_init() {

  d -> vel_motore_0 = 0;
  d -> vel_motore_1 = 0;
  d -> vel_motore_2 = 0;

  d -> vx = 0;
  d -> vy = 0;
  d -> Rw = 0;
  d -> Dw = 0;

}

void PhoenixDrive_setSpeed(int angolo, int velocita, int my_bussola) {

  d -> vx = velocita * sin(angolo); //Calcolo la vx
  d -> vy = velocita * cos(angolo); //Calcolo la vy

  d -> Dw = d -> Rw * KW;  //Dw è il terzo termine della Matrice

  if(d -> Dw > limiteDw_Up)   d -> Dw = limiteDw_Up;
  if(d -> Dw < limiteDw_Down) d -> Dw = limiteDw_Down;

  d -> vel_motore_0 = drive_Matrix [0][0] * d -> vx + drive_Matrix [0][1] * d -> vy + drive_Matrix [0][2] * d -> Dw;
  d -> vel_motore_1 = drive_Matrix [1][0] * d -> vx + drive_Matrix [1][1] * d -> vy + drive_Matrix [1][2] * d -> Dw;
  d -> vel_motore_2 = drive_Matrix [2][0] * d -> vx + drive_Matrix [2][1] * d -> vy + drive_Matrix [2][2] * d -> Dw;

  PhoenixJoints_setSpeed(0, d -> vel_motore_0);
  PhoenixJoints_setSpeed(1, d -> vel_motore_1);
  PhoenixJoints_setSpeed(2, d -> vel_motore_2);

}
