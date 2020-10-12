/**
 * mors_joints.hpp
 */

#pragma once

#include <Arduino.h>

class MorsJoint
{
	/**
	 * variabili per il controllo del singolo motore:
	 * 	-> i 3 pin necessari
	 * 	-> la variabile per la velocità e per la direzione di rotazione
	 */
	uint8_t pin_a;
	uint8_t pin_b;
	uint8_t pin_pwm;

	uint8_t speed;
	uint8_t direzione;
public:
	MorsJoint(uint8_t t_pin_a, uint8_t t_pin_b, uint8_t t_pin_pwm); //costruttore

	void setSpeed(int16_t t_speed); //funzione per calcolare la velocita
	void handle(); //funzione per far girare i motori
};
