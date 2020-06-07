/**
 * mors_joints.cpp
 */
#include "mors_joints.hpp"
#include "params.hpp"

MorsJoint::MorsJoint(uint8_t t_pin_a, uint8_t t_pin_b, uint8_t t_pin_pwm)
{
	this-> pin_a = t_pin_a;
	this-> pin_b = t_pin_b;
	this-> pin_pwm = t_pin_pwm;

	pinMode(pin_a, OUTPUT);
	pinMode(pin_b, OUTPUT);
	pinMode(pin_pwm, OUTPUT);

	velocita = 0;
	direzione = LOW;
}

void MorsJoint::setSpeed(int16_t t_velocita)
{
	if(t_velocita >= 0)
	{
		velocita = t_velocita;
		direzione = LOW;
	}
	else
	{
		velocita = -t_velocita;
		direzione = HIGH;
	}

	if(velocita > MAX_VEL)
	{
		velocita = MAX_VEL;
	}
	if(velocita < MIN_VEL)
	{
		velocita = MIN_VEL;
	}
}

void MorsJoint::handle()
{
	digitalWrite(pin_a, direzione);
	digitalWrite(pin_b, !direzione);
	analogWrite(pin_pwm, velocita);
}
