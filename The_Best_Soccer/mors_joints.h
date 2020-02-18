#pragma once

#include <Arduino.h>
#include "mors_params.h"

typedef struct {

  uint8_t pin_dirA;
  uint8_t pin_dirB;
  uint8_t pin_Pwm;

  uint8_t direzione;
  uint16_t velocita;  //Arriva fino a 255, ma potrebbe essere maggiore dopo i calcoli

} PhoenixJoints;

extern PhoenixJoints* j;
extern PhoenixJoints joints[NUM_JOINTS];

void PhoenixJoints_init();
void PhoenixJoints_setSpeed(byte N_Mot, int velocita);
