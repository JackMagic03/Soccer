/**
 * mors_lineHandler.hpp
 */
#pragma once
#include "mors_line.hpp"
#include "params.hpp"

class MorsLineHandler
{
	MorsLine* line_vect; //puntatore a MorsLine

	uint8_t mask[NUM_LINES]; //array di controllo per le letture dei sensori
	uint8_t flg; //flg di controllo
	int16_t timer; //timer per il rientro del robot in campo

	uint8_t num_angle; //Il numero degli angoli che hanno trovato quancosa
	int16_t tot_angle; //La somma degli angoli dei sensori che hanno rilevato qualcosa
	int16_t escape_angle;  //La traiettoria calcolata dalla media dei vettori dagli angoli dei sensori

public:
	MorsLineHandler(); //costruttore

	void reset(); //funzione di reset delle variabili di controllo
	void handle(); //funzione di gestione generale
	uint8_t getFlg(); //ritorno della flg
	int16_t getEscapeAngle(); //funzione di ritorno dell'angolo di uscita
};
