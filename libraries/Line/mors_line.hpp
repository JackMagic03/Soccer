/**
 * mors_line.hpp
 */
#pragma once
#include <Arduino.h>

class MorsLine //classe del singolo sensore di linea
{
	uint8_t pin; //pin del sensore
	int16_t treshold; //soglia del singolo sensore

	int16_t raw_data; //variabile per la lettura grezza

public:
	int16_t angle; //angolo del sensore
	uint8_t data; //varaibile per la lettura binaria

	MorsLine(uint8_t t_pin, uint16_t t_angle, uint16_t t_treshold); //costruttore

	void read(); //lettura del sensore
};
