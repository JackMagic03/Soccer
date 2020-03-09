#include "mors_drive.h"
#include "mors_params.h"

#define angoloMot_0 60.0
#define angoloMot_1 180.0
#define angoloMot_2 300.0

#define limiteDw_Up 70.0
#define limiteDw_Down -70.0
#define KW 3.0

static double drive_Matrix [NUM_JOINTS][NUM_JOINTS] =
{
  {0.87, 0.50, 1}, // -sin T1, cos T1, 1
  {0, -1, 1},      // -sin T2, cos T2, 1
  {-0.87, 0.50, 1}  // -sin T3, cos T3, 1
};

// Convertire i Radianti in Gradi
float drive_radianti(float gradi) { return ( gradi * PI / 180.0 ); }  //PI è una funzione integrata in arduino per il valore di P Greco

//Convertire i Gradi in Radianti
float drive_gradi(float radianti) { return ( radianti * 180.0 / PI ); }

void PhoenixDrive_init(PhoenixDrive* d) {

  d -> vel_motore0 = 0;
  d -> vel_motore1 = 0;
  d -> vel_motore2 = 0;

  d -> vx = 0;
  d -> vy = 0;
  d -> Rw = 0;
  d -> Dw = 0;

}

void PhoenixDrive_setSpeed(PhoenixDrive* d, int angolo, int vel/*, int my_bussola*/) {

  d -> vx = vel * sin ( drive_radianti (angolo - 270) ); //Sarebbe 360 - angolo, ma così facendo
  d -> vy = vel * cos ( drive_radianti (angolo - 270) ); //il robot va avanti a 0° e a sinistra a 90°

  //Portare la bussola da 0 - 360 a -180 - +180
  // if(my_bussola <= 180) d -> Rw = my_bussola;
  // else                  d -> Rw = my_bussola - 360;

  d -> Dw = 0;  //d -> Rw * KW; //Dw è il terzo termine della matrice, Wr è la velocità di rotazione e KW è una costante che va regolata

  if(d -> Dw > limiteDw_Up)   d -> Dw = limiteDw_Up;
  if(d -> Dw < limiteDw_Down) d -> Dw = limiteDw_Down;

  d -> vel_motore0 = (drive_Matrix [0][0] * d -> vx) + (drive_Matrix [0][1] * d -> vy) + (drive_Matrix [0][2] * d -> Dw);
  d -> vel_motore1 = (drive_Matrix [1][0] * d -> vx) + (drive_Matrix [1][1] * d -> vy) + (drive_Matrix [1][2] * d -> Dw);
  d -> vel_motore2 = (drive_Matrix [2][0] * d -> vx) + (drive_Matrix [2][1] * d -> vy) + (drive_Matrix [2][2] * d -> Dw);

  /*
  I calcoli per sapere le velocità e le direzioni dei singoli motori tramite le
  moltiplicazioni "riga * colonna"
  */

  PhoenixJoints_setSpeed(&d -> joints[0], d -> vel_motore0);
  PhoenixJoints_setSpeed(&d -> joints[1], d -> vel_motore1);
  PhoenixJoints_setSpeed(&d -> joints[2], d -> vel_motore2);

}
