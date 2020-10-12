/**
 * mors_imuHandler.cpp
 */
#include "mors_imuHandler.hpp"

MorsImuHandler::MorsImuHandler()
{}

void MorsImuHandler::handle()
{
	this-> imu_ptr-> read();

	this-> heading = this-> imu_ptr-> getHeading();

	this-> pid_ptr-> handle(this-> heading);
}

int16_t MorsImuHandler::getOutput()
{
	return (pid_ptr-> getOutput());
}
