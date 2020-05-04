/**
 * LineDetector.cpp
 * #author Massimo Giordano
 */

#include "LineDetector.hpp"

LineDetector::LineDetector(uint8_t* t_pin, int16_t* t_angle, int* t_soglia) {
  pin = *t_pin;
  angle = *t_angle;
  soglia = *t_soglia;

  raw_data = 0;
  data = 0;
}

LineDetector::LineDetector() {
  pin = 0;
  angle = 0;
  soglia = 0;

  raw_data = 0;
  data = 0;
}

void LineDetector::init(uint8_t* t_pin, int16_t* t_angle, int* t_soglia) {
  pin = *t_pin;
  angle = *t_angle;
  soglia = *t_soglia;

  raw_data = 0;
  data = 0;
}

uint8_t LineDetector::read() {
  raw_data = analogRead(pin);

  if(raw_data >= soglia) {
    data = HIGH;
  }
  else {
    data = LOW;
  }
  return data;
}
