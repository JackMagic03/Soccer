/**
 * mors_lineHandler.cpp
 */
#include "mors_lineHandler.hpp"

MorsLineHandler::MorsLineHandler()
{
	/**
	 * inizializzazione variabili e puntatori a classi
	 */
	for(int i = 0; i < NUM_LINES; ++i)
	{
		this-> mask[i] = 0;
	}
	this-> flg = 0;
	this-> timer = 0;

	this-> num_angle = 0;
	this-> tot_angle = 0;
	this-> escape_angle = 0;
}

void MorsLineHandler::reset()
{
	/**
	 * reset variabili di controllo
	 */
	for(int i = 0; i < NUM_LINES; ++i)
	{
		this-> mask[i] = 0;
	}
	this-> flg = 0;
	this-> timer = 0;
}

void MorsLineHandler::handle()
{
	/**
	 * funzione di gestione delle letture dei sensori e calcolo dell'angolo di uscita del robot
	 */
	for(int i = 0; i < NUM_LINES; ++i)
	{
		this-> line_vect[i].read(); //lettura dei sensori
	}
	for(int i = 0; i < NUM_LINES; ++i)
	{
		if(this-> mask[i] == LOW) //se la mask è bassa vuol dire che quel sensore non ha mai rilevato alcuna linea in questo ciclo
		{
			if(this-> line_vect[i].data == HIGH) //se la linea è stata vista
			{
				this-> mask[i] = HIGH; //cambiamo la mask
		        this-> tot_angle = this-> tot_angle + this-> line_vect[i].angle; //incremento dell'angolo totale
		        this-> flg = HIGH; //accesa la flg
		        this-> timer = DEFAULT_TIMER; //impostato il timer
		        this-> num_angle ++; //incremento numero dei sensori che hanno visto la linea

		        this-> escape_angle = ((this-> tot_angle / this-> num_angle)+ 180)% 360; //calcolo dell'angolo di uscita
      		}
    	}
  	}
	if(this-> flg == HIGH) //se la flg è accesa non è ancora scaduto il tempo
	{
		this-> timer --; //decremento del timer
	}
	if(this-> timer == 0)
	{
		MorsLineHandler::reset(); //reset di mask, flg e timer
	}
}

uint8_t MorsLineHandler::getFlg()
{
	return flg;
}

int16_t MorsLineHandler::getEscapeAngle()
{
	return escape_angle;
}
