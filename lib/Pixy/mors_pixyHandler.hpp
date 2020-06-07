/**
 * mors_pixyHandler.hpp
 */
#pragma once

#include "mors_pixy.hpp"

class MorsPixyHandler
{
	MorsPixy* pixy_ptr;

	uint8_t heading_x;
	uint8_t heading_y;

	uint8_t bit;
public:
	MorsPixyHandler();

	void test();
	void handle();
};
