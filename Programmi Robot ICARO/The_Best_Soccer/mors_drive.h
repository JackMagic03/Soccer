#pragma once

#include <Arduino.h>
#include "mors_params.h"
#include "mors_joints.h"

typedef struct {

  PhoenixJoints* joints;

  float vel_motore0, vel_motore1, vel_motore2;

  float vx;            //Componente velocità del'asse X
  float vy;            //Componente velocità dell'asse Y
  float Rw;            //Velocità angolare
  float Dw;            //L'Rw della matrice di Holon

} PhoenixDrive;

float drive_radianti(float gradi);
float drive_gradi(float radianti);
void PhoenixDrive_init(PhoenixDrive* d);
void PhoenixDrive_setSpeed(PhoenixDrive* d, int angolo, int velocita/*, int my_bussola*/);
