/**
 * main.cpp
 */
#include "globals.hpp"
#include <Arduino.h>

void setup()
{
	Serial.begin(9600);

	bno.begin(); //init della imu

	pixy.init(); //init della pixy

	planner = &attack_planner; //all'inizio, tutti e due i robot saranno attaccanti
}

void loop()
{
	// for(int i = 0; i < NUM_JOINTS; ++i)
	// {
	// 	joint_vect[i].setSpeed(15);
	// }
	//
	// for(int i = 0; i < NUM_JOINTS; ++i)
	// {
	// 	joint_vect[i].handle();
	// }

	drive_handler.handle(0, 150, 0);
	delay(2000);
}
