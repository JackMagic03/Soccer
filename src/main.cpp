/**
 * main.cpp
 * @author Massimo Giordano
 */

#include <Arduino.h>
#include "globals.hpp"

void setup() {
  Serial.begin(9600);
}

void loop() {

  //line_handler.handle();

  //drive_handler.handle(200, line_handler.getEscapeAngle(), imu_handler.getOutput());

  //drive_handler.joint_component[0].handle(200);

  imu_handler.imu_component.read();
  Serial.println(imu_handler.imu_component.getHeading());
}
