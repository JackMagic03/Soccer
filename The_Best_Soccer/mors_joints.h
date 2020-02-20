#pragma once

#include <Arduino.h>

typedef struct {

  uint8_t pin_dirA;
  uint8_t pin_dirB;
  uint8_t pin_Pwm;

  uint16_t velocita;
  uint8_t direzione;

} PhoenixJoints;

void PhoenixJoints_init(PhoenixJoints* j);
void PhoenixJoints_setSpeed(PhoenixJoints* j, int vel);
