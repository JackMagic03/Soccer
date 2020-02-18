#pragma once

#include <Arduino.h>
#include "mors_params.h"
#include "mors_joints.h"

typedef struct {

  float vel_motore_0;
  float vel_motore_1;
  float vel_motore_2; //Le 3 velocità dei motori

  float vx;            //Componente velocità del'asse X
  float vy;            //Componente velocità dell'asse Y
  float Rw;            //Velocità angolare
  float Dw;            //L'Rw della matrice di Holon

} PhoenixDrive;

extern PhoenixDrive* d;
extern PhoenixDrive drive;

float drive_radianti(float gradi);
float drive_gradi(float radianti);
void PhoenixDrive_init();
void PhoenixDrive_setSpeed(int angolo, int velocita, int my_bussola);
