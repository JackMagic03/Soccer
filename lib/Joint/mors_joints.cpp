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

	speed = 0;
	direzione = LOW;
}

void MorsJoint::setSpeed(float t_speed)
{
	Serial.println("Inizio setSpeed");
	if(t_speed >= 0)
	{
		this-> speed = t_speed;
		direzione = LOW;
	}
	else
	{
		this-> speed = -t_speed;
		direzione = HIGH;
	}
	if(t_speed >= 0)
	{
		this-> speed = t_speed;
		direzione = LOW;
	}
	else
	{
		this-> speed = -t_speed;
		direzione = HIGH;
	}
}

void MorsJoint::handle()//float t_speed)
{
	// if(t_speed >= 0)
	// {
	// 	this-> speed = t_speed;
	// 	direzione = LOW;
	// }
	// else
	// {
	// 	this-> speed = -t_speed;
	// 	direzione = HIGH;
	// }

	digitalWrite(pin_a, direzione);
	digitalWrite(pin_b, !direzione);
	analogWrite(pin_pwm, speed);
}
