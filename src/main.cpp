/**
 * main.cpp
 * @author Massimo Giordano
 */

#include <Arduino.h>
#include "globals.hpp"

void setup() {
  Serial.begin(9600);

  //pinMode(13, OUTPUT);
}

void loop() {

  //line_handler.handle();

  //imu_handler.handle();

  //drive_handler.handle(200, 0, imu_handler.getOutput());

  // digitalWrite(13, HIGH);
  // delay(500);
  // digitalWrite(13, LOW);
  // delay(500);
  Serial.println("Ciao");
}
