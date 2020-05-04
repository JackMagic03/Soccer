/**
 * config.hpp
 * @author Massimo Giordano
 */

#pragma once
#include <Arduino.h>

#define NUM_JOINTS 3  //I motori totali

const uint8_t PIN_DIR_A[NUM_JOINTS] = {4, 13, 7};
const uint8_t PIN_DIR_B[NUM_JOINTS] = {3, 12, 6};
const uint8_t PIN_PWM[NUM_JOINTS] = {2, 11, 5};

#define MAX_VEL 255 //Velocità massima del robot
#define MAX_THRESHOLD 20  //La velocità minima a cui il robot può andare

#define LIMITE_DW_UP 70.0 //Limite massimo della variabile dw
#define LIMITE_DW_DOWN -70.0  //Limite minimo della variabile dw
#define KW 3.0  //La costante rotativa del robot
#define OFFSET_ANGLE 270  //L'angolo che va sottratto per avere lo 0° davanti

#define NUM_LINES 6 //I sensori di linea totali
#define DEFAULT_TIMER 3000  //Il tempo per far rientrare il robot dentro il campo
// #define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
// #define sbi(sfr, bit) (_SFR_BYTE(sfr) != _BV(bit))

const int SOGLIA_LINEE[NUM_LINES] = {800, 800, 800, 800, 800, 800};
const uint8_t PIN_LINEE[NUM_LINES] = {A0, A1, A2, A3, A4, A5};
const int16_t ANGOLI_LINEE[NUM_LINES] = {30, 90, 150, 210, 270, 330};
