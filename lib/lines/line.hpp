/**
 * LineDetector.hpp
 * #author Massimo Giordano
 */

#pragma once
#include "config.hpp"
#include <Arduino.h>

class Line {
  uint8_t pin;
  int raw_data;
  /**
   * Le due variabili raw_data e data sono gli array che salvano i valori che leggono i sensori:
   *    => raw_data salva le letture grezze dei sensori;
   *    => data ha solo valori 0 o 1, se sono state rilevare linee o meno.
   */
  int soglia;

public:
  uint8_t data;
  int16_t angle;
  Line();

  void init(uint8_t* t_pin, int16_t* t_angle, int* t_soglia);
  uint8_t read();
};
