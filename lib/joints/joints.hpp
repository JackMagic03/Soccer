/**
 * joints.hpp
 * @author Massimo Giordano
 */

#pragma once
#include <Arduino.h>


class Joints {
  uint8_t pin_a;
  uint8_t pin_b;
  uint8_t pin_pwm;

  uint8_t velocita;
  uint8_t direzione;

public:
  Joints();

  void init(uint8_t t_pin_a, uint8_t t_pin_b, uint8_t t_pin_pwm);
  void handle(int t_velocita);
};
