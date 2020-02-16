#include "mors_joints.h"

PhoenixJoints joints[NUM_JOINTS] = {
  { //Joint 1
    pin_dirA  : 4,  //Filo Giallo
    pin_dirB  : 3,  //Filo Rosso
    pin_Pwm   : 2,  //Filo Bianco

    direzione : 0,
    velocita  : 0,
  },
  { //Joint 2
    pin_dirA  : 13,  //Filo Giallo
    pin_dirB  : 12,  //Filo Rosso
    pin_Pwm   : 11,  //Filo Bianco

    direzione : 0,
    velocita  : 0,
  },
  { //Joint 3
    pin_dirA  : 7,  //Filo Giallo
    pin_dirB  : 6,  //Filo Rosso
    pin_Pwm   : 5,  //Filo Bianco

    direzione : 0,
    velocita  : 0,
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

void PhoenixJoints_setSpeed(byte N_Mot, int velocita) {

  if (velocita >= 0)  {
    j -> velocita = velocita;
    j -> direzione = 0;

    digitalWrite(joints[N_Mot].pin_dirA, j -> direzione);
    digitalWrite(joints[N_Mot].pin_dirB, !j -> direzione);
    if(j -> velocita > 255) j -> velocita = 255;
    analogWrite(joints[N_Mot].pin_Pwm, j -> velocita);
  }

  else {
    j -> velocita = -velocita;
    j -> direzione = 1;

    digitalWrite(joints[N_Mot].pin_dirA, j -> direzione);
    digitalWrite(joints[N_Mot].pin_dirB, !j -> direzione);
    if(j -> velocita > 255) j -> velocita = 255;
    analogWrite(joints[N_Mot].pin_Pwm, j -> velocita);
  }

}
