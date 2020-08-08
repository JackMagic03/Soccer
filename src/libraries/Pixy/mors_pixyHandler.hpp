/**
 * mors_pixyHandler.hpp
 */
#pragma once

#include <Pixy2.h>
#include <Arduino.h>

class MorsPixyHandler
{
	Pixy2* pixy_ptr; //puntatore al componente

	uint8_t get_blocks; //variabile per il salvataggio di getBlocks()
	uint8_t num_blocks; //quanti blocchi sono stati letti
	uint8_t heading_x; //lettura dell'asse x del blocco
	uint8_t heading_y; //lettura dell'asse y del blocco

	uint8_t flg; //se i blocchi sono stati visti
	uint8_t bit; //quanti e quali blocchi sono stati visti
public:
	MorsPixyHandler(Pixy2* t_pixy_ptr); //costruttore

	void read(); //lettura
	void test(); //test per flg e bit
	void handle(); //vediamo se tenerla o meno la handle
};
