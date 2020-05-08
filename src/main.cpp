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

  Serial.println("Ciaoo");
  //Serial.println(imu_handler.imu_component.getHeading());
}
