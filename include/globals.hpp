/**
 * globals.hpp
 */
#include <Arduino.h>

#define NUM_JOINTS 3          //Sono i motori che abbiamo
#define NUM_LINES 6           //Sono i sensori di linea che abbiamo.

const uint8_t PIN_DIR_A[NUM_JOINTS] = {4, 13, 7};
const uint8_t PIN_DIR_B[NUM_JOINTS] = {3, 12, 6};
const uint8_t PIN_PWM[NUM_JOINTS] = {2, 11, 5};
#define MAX_VEL 255
#define MAX_THRESHOLD 20
/**
 *  Ho levato i #define perché dava un problema di conversione da #define a uint8_t* e
 *  tutto il resto dei parametri
 */
// #define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
// #define sbi(sfr, bit) (_SFR_BYTE(sfr) != _BV(bit))
const int SOGLIA_LINEE[NUM_LINES] = {800, 800, 800, 800, 800, 800};
const uint8_t PIN_LINEE[NUM_LINES] = {A0, A1, A2, A3, A4, A5};
const int ANGOLI_LINEE[NUM_LINES] = {30, 90, 150, 210, 270, 330};

#define DEFAULT_TIMER 3000

const float K_P = 0;
const float K_I = 0;
const float K_D = 0;
const float D_T = 0.01;
const float ID_T = 100;

#define MAX_OUTPUT 255
#define MIN_OUTPUT -255
