/**
 * Main
 *
 * Massimo Giordano, Diego de Martino
 */

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include <Pixy2.h>
#include <Math.h>

#define NUM_JOINTS 3
#define angoloMot_1 60.0
#define angoloMot_2 180.0
#define angoloMot_3 300.0
#define limiteDw_Up 70.0
#define limiteDw_Down -70.0
#define KW 3.0
uint8_t pinA[NUM_JOINTS]   = {4, 13, 7};   //giallo
uint8_t pinB[NUM_JOINTS]   = {3, 12, 6};   //rosso
uint8_t pinPwm[NUM_JOINTS] = {2, 11, 5};   //bianco

#define scl_imu 21
#define sda_imu 20
int read_imu;
Adafruit_BNO055 bno = Adafruit_BNO055(55);

uint16_t analogReadLines[6] {0};  // L'array che contiene i valori letti dai sensori
uint16_t pinLines[6] = { A0, A1, A2, A3, A4, A5 };  // i 6 pin analogici dei sensori

Pixy2 pixy;
int NUM_BLOCKS = pixy.ccc.numBlocks;
int GET_BLOCKS = pixy.ccc.getBlocks();
int TOT_BLOCKS = 3;   //Il totale dei clocchi che la pixy ha memorizzati

void setup() {

  Serial.begin(9600);

  init_joints();

  init_compass();

  drive_init();

  pixy.init();

}

void loop() {

  read_compass();

  drive_Go(0, 0, read_imu);

/*
for(int i = 0; i<360; i++) {
  drive_Go(i, 200, read_imu);
  delay(5);
}
*/

}
