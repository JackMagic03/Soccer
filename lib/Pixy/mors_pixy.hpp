/**
 * mors_pixy.hpp
 */
#pragma once

#include <Pixy2.h>
#include <Arduino.h>

class MorsPixy
{
	Pixy2* pixy_ptr;

	uint8_t get_blocks;
	uint8_t num_blocks;
	uint8_t flg;

public:
	MorsPixy(Pixy2* t_pixy_ptr); //costruttore

	void read(); //lettura
	uint8_t getGetBlocks(); //ritorno blocchi di lettura
	uint8_t getNumBlocks(); //ritorno numero blocchi di lettura
	uint8_t getSignature(uint8_t t_i); //ritorno signature del blocco
	uint8_t getm_x(uint8_t t_i); //ritorno della coordinata x
	uint8_t getm_y(uint8_t t_i); //ritorno della coordinata y
	uint8_t getFlg(); //ritorno della flg
};
