/**
 * main.cpp
 * @author Massimo Giordano
 */

#include <Arduino.h>
#include "globals.hpp"

void setup() {
  Serial.begin(9600);

  imu_handler.imu_component.init(&bno);
}

void loop() {

}
