#include "mors_globals.h"

PhoenixJoints joints[NUM_JOINTS] = {
  { //Joint 1
    pin_dirA  : 4,  //Filo Giallo
    pin_dirB  : 3,  //Filo Rosso
    pin_Pwm   : 2,  //Filo Bianco

    velocita  : 0,
    direzione : 0,
  },
  { //Joint 2
    pin_dirA  : 13,  //Filo Giallo
    pin_dirB  : 12,  //Filo Rosso
    pin_Pwm   : 11,  //Filo Bianco

    velocita  : 0,
    direzione : 0,
  },
  { //Joint 3
    pin_dirA  : 7,  //Filo Giallo
    pin_dirB  : 6,  //Filo Rosso
    pin_Pwm   : 5,  //Filo Bianco

    velocita  : 0,
    direzione : 0,
  }
}; //Fine della struct

PhoenixDrive drive;
