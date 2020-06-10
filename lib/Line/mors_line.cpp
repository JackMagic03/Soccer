/**
 * mors_line.cpp
 */
#include "mors_line.hpp"

MorsLine::MorsLine(uint8_t t_pin, uint16_t t_angle, uint16_t t_treshold)
{
	this-> pin = t_pin;
	this-> angle = t_angle;
	this-> treshold = t_treshold;

	this-> raw_data = 0;
	this-> data = 0;
}

void MorsLine::read()
{
	this-> raw_data = analogRead(this-> pin);

	if(this-> raw_data >= this-> treshold)
	{
		this-> data = HIGH;
	}
	else
	{
		this-> data = LOW;
	}
}
