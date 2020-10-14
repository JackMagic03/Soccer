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

	float speed;
	uint8_t direzione;
public:
	MorsJoint(uint8_t t_pin_a, uint8_t t_pin_b, uint8_t t_pin_pwm); //costruttore

	void setSpeed(float t_speed); //funzione per calcolare la velocita
	void handle(); //funzione per far girare i motori
  inline void printInfo() {
    char buf[256];
    sprintf(buf, "pin_a: %d\tpin_b: %d\tpin_pwm: %d\tspeed: %d\tdir: %d\n",
	    pin_a, pin_b, pin_pwm, speed, direzione);
    Serial.print(buf);
  };
};
