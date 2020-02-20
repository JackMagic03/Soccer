#include "mors_joints.h"

void PhoenixJoints_init(PhoenixJoints* j) {
  pinMode(j -> pin_dirA, OUTPUT);
  digitalWrite(j -> pin_dirA, LOW);

  pinMode(j -> pin_dirB, OUTPUT);
  digitalWrite(j -> pin_dirB, LOW);

  pinMode(j -> pin_Pwm, OUTPUT);
  digitalWrite(j -> pin_Pwm, LOW);
}

void PhoenixJoints_setSpeed(PhoenixJoints* j, int vel) {

  if(vel >= 0) {
    j -> velocita = vel;
    j -> direzione = 0;
  } else {
    j -> velocita = -vel;
    j -> direzione = 1;
  }

  if(j -> velocita > 255) j -> velocita = 255;

  if(j -> velocita < 50) j -> velocita = 0;

  digitalWrite(j -> pin_dirA, j -> direzione);
  digitalWrite(j -> pin_dirB, !j -> direzione);
  analogWrite(j -> pin_Pwm, j -> velocita);
  /*switch (N_Mot) {
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
  }*/
}
