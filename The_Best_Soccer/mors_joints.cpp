#include "mors_joints.h"
#include "mors_params.h"

PhoenixJoints* j;

PhoenixJoints joints[3] = {
  { //Joint 1
    pin_dirA  : 4,  //Filo Giallo
    pin_dirB  : 3,  //Filo Rosso
    pin_Pwm   : 2,  //Filo Bianco
  },
  { //Joint 2
    pin_dirA  : 13,  //Filo Giallo
    pin_dirB  : 12,  //Filo Rosso
    pin_Pwm   : 11,  //Filo Bianco
  },
  { //Joint 3
    pin_dirA  : 7,  //Filo Giallo
    pin_dirB  : 6,  //Filo Rosso
    pin_Pwm   : 5,  //Filo Bianco
  }
}; //Fine della struct

void PhoenixJoints_init() {
  pinMode(j -> pin_dirA, OUTPUT);
  digitalWrite(j -> pin_dirA, LOW);

  pinMode(j -> pin_dirB, OUTPUT);
  digitalWrite(j -> pin_dirB, LOW);

  pinMode(j -> pin_Pwm, OUTPUT);
  digitalWrite(j -> pin_Pwm, LOW);
}

void PhoenixJoints_setSpeed(byte N_Mot, int vel) {
  switch (N_Mot) {
    case 1:
      if(vel >= 0) {
        digitalWrite(joints[0].pin_dirA, LOW);
        digitalWrite(joints[0].pin_dirB, HIGH);
        if(vel > 255) vel = 255;
        analogWrite(joints[0].pin_Pwm, vel);
      } else {
        digitalWrite(joints[0].pin_dirA, HIGH);
        digitalWrite(joints[0].pin_dirB, LOW);
        if(vel < -255) vel = -255;
        analogWrite(joints[0].pin_Pwm, -vel);
      } break;

    case 2:
      if(vel >= 0) {
        digitalWrite(joints[1].pin_dirA, LOW);
        digitalWrite(joints[1].pin_dirB, HIGH);
        if(vel > 255) vel = 255;
        analogWrite(joints[1].pin_Pwm, vel);
      } else {
        digitalWrite(joints[1].pin_dirA, HIGH);
        digitalWrite(joints[1].pin_dirB, LOW);
        if(vel < -255) vel = -255;
        analogWrite(joints[1].pin_Pwm, -vel);
      } break;

    case 3:
      if(vel >= 0) {
        digitalWrite(joints[2].pin_dirA, LOW);
        digitalWrite(joints[2].pin_dirB, HIGH);
        if(vel > 255) vel = 255;
        analogWrite(joints[2].pin_Pwm, vel);
      } else {
        digitalWrite(joints[2].pin_dirA, HIGH);
        digitalWrite(joints[2].pin_dirB, LOW);
        if(vel < -255) vel = -255;
        analogWrite(joints[2].pin_Pwm, -vel);
      } break;
  }
}
