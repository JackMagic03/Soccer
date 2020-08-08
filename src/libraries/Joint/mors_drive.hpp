/**
 * mors_drive.hpp
 */
#pragma once

#include "mors_joints.hpp"
#include "params.hpp"

class MorsDrive
{
	MorsJoint* joint;

	float speed[NUM_JOINTS]; //Le velocità che andranno passate ai motori

	float v_x; //Componente velocità del'asse X
	float v_y; //Componente velocità dell'asse Y
public:
	MorsDrive();

	static float gradi(float t_rad); //Funzione che restituisce i gradi
	static float radianti(float t_gradi); //Funzione che restituisce i radianti
	void handle(float t_angle, int t_speed, float t_imu); //La handle che dice ai singoli motori di muoversi
};
