/**
 * pixy_handler.hpp
 */
#ifndef PIXY_HANDLER_HPP
#define PIXY_HANDLER_HPP

#include "components_obj.hpp"

class PixyHandler
{
	uint8_t heading_x;
	uint8_t heading_y;

	uint8_t bit;
public:
	PixyHandler();

	void test();
	void handle();
};

#endif
