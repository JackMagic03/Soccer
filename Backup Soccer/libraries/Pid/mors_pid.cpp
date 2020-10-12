/**
 * mors_pid.cpp
 */
#include "mors_pid.hpp"
#include "Params/params.hpp"

MorsPid::MorsPid()
{
	/**
	 * inizializzazione di tutte le variabili:
	 * quelle di controllo a 0 e quelle di supporto con le costanti
	 */
	this-> set_point = 0;
	this-> input = 0;
	this-> output = 0;

	this-> k_p = K_P;
	this-> k_i = K_I;
	this-> k_d = K_D;

	this-> error = 0;
	this-> prev_error = 0;
	this-> tot_error = 0;

	this-> d_t = D_T;
	this-> id_t = ID_T;
}

void MorsPid::handle(int16_t t_input) //come parametro verra messa la lettura del sensore
{
	this-> input = t_input; //assegnazione del valore della lettura

	/**
	 * Calcolo dell'errore
	 */
	this-> error = this-> set_point - this-> input;

	/**
	 * parte integrale
	 */
	this-> tot_error += this-> error * this-> d_t * this-> k_i;

	/**
	 * parte derivata
	 */
	float error_d = this-> k_d * ((this-> error - this-> prev_error) * this-> d_t);

	/**
	 * parte proporzionale
	 */
	this-> output = this-> tot_error + error_d + (this-> k_p * this-> error);

	/**
	 * controllo dell'output
	 */
	if(output > MAX_OUTPUT)
	{
		this-> output = MAX_OUTPUT;
	}
	if(output < MIN_OUTPUT) 
	{
		this-> output = MIN_OUTPUT;
	}
}

int16_t MorsPid::getOutput()
{
	return output;
}