/**
 * mors_imu.hpp
 */
#pragma once
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include <Wire.h>

class MorsImu
{
	Adafruit_BNO055* bno_ptr; //puntatore alla bussola

	int16_t heading; //variabile dove salviamo la lettura
public:
	MorsImu(Adafruit_BNO055* t_bno_ptr); //costruttore

	void read(); //lettura della bussola
	int16_t getHeading(); //ritorno della lettura
};