/*
 * Gestione motori
 *
 * De Martino, Giordano
 */

#include "globals.h"

Adafruit_BNO055 bno = Adafruit_BNO055(55);

Pixy2 pixy;
int NUM_BLOCKS = pixy.ccc.getBlocks();

void setup() {

  Serial.begin(9600);

  init_joints();

  init_compass();

  drive_init();

  pixy.init();

}

void loop() {

//  read_compass();

  //drive_Go(0, 200, read_imu);

  /*
  for(int i = 0; i<360; i++) {

    drive_Go(i, 200, read_imu);
    delay(5);

} */

}
