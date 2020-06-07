/**
 * mors_imu.cpp
 */
#include "mors_imu.hpp"
#include <Arduino.h>

MorsImu::MorsImu(Adafruit_BNO055* t_bno_ptr)
{
	/**
	 * inizializzazione puntatori e variabili
	 */
	this-> bno_ptr = t_bno_ptr; //non ho messo la * perché sono entrambi puntatori

	this-> heading = 0;
}

void MorsImu::read()
{
	imu::Vector<3> euler = this-> bno_ptr-> getVector(Adafruit_BNO055::VECTOR_EULER);

	this-> heading = euler.x();  //Lettura dell'asse x
}

int16_t MorsImu::getHeading()
{
	return heading;
}