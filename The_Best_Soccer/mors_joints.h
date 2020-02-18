#pragma once

#include <Arduino.h>
#include "mors_params.h"

typedef struct {

  uint8_t pin_dirA;
  uint8_t pin_dirB;
  uint8_t pin_Pwm;

} PhoenixJoints;

extern PhoenixJoints* j;
extern PhoenixJoints joints[3];

void PhoenixJoints_init();
void PhoenixJoints_setSpeed(byte N_Mot, int velocita);
