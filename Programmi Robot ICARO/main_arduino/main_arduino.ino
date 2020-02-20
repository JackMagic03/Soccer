/*
 * Gestione motori
 *
 * De Martino, Giordano
 */

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
//#include <Pixy2.h>
#include <Math.h>

#define NUM_JOINTS 3

uint8_t pinA[NUM_JOINTS]   = {4, 13, 7};   //giallo
uint8_t pinB[NUM_JOINTS]   = {3, 12, 6};   //rosso
uint8_t pinPwm[NUM_JOINTS] = {2, 11, 5};   //bianco
/*
Il motore di destra è il motore 1;
quello di dietro è il motore 2;
quello di sinistra è il motore 3.
 */

uint16_t velocita;

#define angoloMot_1 60.0
#define angoloMot_2 180.0
#define angoloMot_3 300.0

#define limiteDw_Up 70.0
#define limiteDw_Down -70.0
#define KW 3.0

#define scl_imu 21
#define sda_imu 20
int read_imu;
Adafruit_BNO055 bno = Adafruit_BNO055(55);

//Pixy2 pixy;
//int NUM_BLOCKS = pixy.ccc.getBlocks();

void setup() {

  Serial.begin(9600);

  init_joints();

  init_compass();

  drive_init();

  //  pixy.init();

}

void loop() {

  read_compass();

  drive_Go(0,200,read_imu);

/*  for(int i = 0; i<360; i++) {

      drive_Go(i, 200, read_imu);
      delay(5);

    }
*/

}
