/**
 * mors_pid.hpp
 */
#pragma once
#include <Arduino.h>

class MorsPid
{
	float set_point, input, output;

	float k_p, k_i, k_d;  //Le componenti della correzione PID
	float error, prev_error, tot_error;

	float d_t, id_t;
	//	  0.01, 100
public:
	MorsPid();

	void handle(int16_t t_input); //funzione di calcolo dell'errore e correzione
	int16_t getOutput(); //ritorno dell'output
};