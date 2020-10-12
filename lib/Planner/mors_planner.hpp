/**
 * mors_planner.hpp
 */
#pragma once
#include <Arduino.h>
#include "mors_pixyHandler.hpp"
#include "mors_imuHandler.hpp"

class MorsPlanner
{
protected:
	MorsImuHandler* imu_ptr;
	MorsPixyHandler* pixy_ptr;

	float angle; //angolo della traiettoria del robot in radianti
	uint8_t speed; //velocita a cui il robot deve andare
				 //deve essere per forza >= 0
	uint16_t imu_angle; //dato che estrapoliamo dalla imu

	bool ready; //variabile per abilitare il planner
public:
	virtual void handle(); //funzione che verra sviluppata nel planner d'attacco e di difesa

	inline bool isReady() {return ready;}; //ritorno dello stato del planner
	inline float getAngle() {return angle;}; //ritorno dell'angolo
	inline uint8_t getSpeed() {return speed;}; //ritorno della velocita
	inline uint16_t getImuAngle() {return imu_angle;}; //ritorno del dato della bussola

	inline int16_t getOutput()
	{
		imu_ptr-> handle();

		return imu_ptr-> getOutput();
	}
};
/**
 * creiamo tutte funzioni inline per non avere il file .cpp
 */