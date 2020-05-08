/**
 * main.cpp
 * @author Massimo Giordano
 */

#include "globals.hpp"

void setup() {
  Serial.begin(9600);
}

void loop() {

  //line_handler.handle();

  //imu_handler.handle();

  //drive_handler.handle(200, 0, imu_handler.getOutput());

  drive_handler.joint_component[1].handle(200);
  delay(500);
  drive_handler.joint_component[1].handle(-200);
  delay(500);
  //Serial.println(imu_handler.imu_component.getHeading());
}
