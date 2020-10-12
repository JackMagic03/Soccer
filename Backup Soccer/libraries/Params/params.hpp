/**
 * params.hpp
 */
#pragma once

#define NUM_LINES 6 //numero dei sensori
#define DEFAULT_TIMER 3000 //timer per il rientro del robot in campo

#define NUM_JOINTS 3 //numero dei giunti
#define MAX_VEL 255 //velocita massima
#define MIN_VEL 20 //velocita minima
#define OFFSET_ANGLE 270 //per la funzione handle del drive quando impostiamo gli angoli sessagesimali

const float K_P = 0;
const float K_I = 0;
const float K_D = 0;
const float D_T = 0.01;
const float ID_T = 100;

#define MAX_OUTPUT 255
#define MIN_OUTPUT -255
