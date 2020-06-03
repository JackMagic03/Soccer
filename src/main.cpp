/**
 * main.cpp
 * @author Massimo Giordano
 */
#include <Arduino.h>

#include "components_handler.hpp"

void setup()
{
	Serial.begin(9600);

	bno.begin();
	pixy.init();
}

void loop()
{

}
