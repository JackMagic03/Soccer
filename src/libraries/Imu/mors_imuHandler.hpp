/**
 * mors_imuHandler.hpp
 */
#pragma once
#include "mors_imu.hpp"
#include "mors_pid.hpp"

class MorsImuHandler
{
	MorsImu* imu_ptr;
	MorsPid* pid_ptr;

	int16_t heading;
public:
	MorsImuHandler();

	void handle();
	int16_t getOutput();
};