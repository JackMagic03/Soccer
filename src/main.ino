/*
 * Gestione motori
 *
 * De Martino, Giordano
 */

 #include "Arduino.h"
 #include "Wire.h"
 #include "Adafruit_Sensor.h"
 #include "Adafruit_BNO055.h"
 #include "utility/imumaths.h"

uint8_t pinA[3]   = {4, 13, 7};   //giallo
uint8_t pinB[3]   = {3, 12, 6};   //rosso
uint8_t pinPwm[3] = {2, 11, 5};   //bianco

/*
Il motore di destra è il motore 1;
quello di dietro è il motore 2;
quello di sinistra è il motore 3.
 */
#define pot 150
#define N_Mot 3

float vx;       //Componente velocità del'asse X
float vy;       //Componente velocità dell'asse Y
float Rw;       //Velocità angolare
float Dw;       //L'Rw della matrice di Holon

#define angoloMot_1 60.0
#define angoloMot_2 180.0
#define angoloMot_3 300.0

#define limiteDw_Up 70.0
#define limiteDw_Down -70.0
#define KW 3.0

#define scl_compass 21
#define sda_compass 20

uint16_t pinLines[6] = { A0, A1, A2, A3, A4, A5  /* i 6 pin analogici dei sensori */};

Adafruit_BNO055 bno = Adafruit_BNO055(55);
int read_imu;

void setup() {

  Serial.begin(9600);

  init_joints();

  init_compass();

  drive_init();

  pixy.init();

}

void loop() {

  read_compass();

  drive_Go(0, 200, read_imu);

}
