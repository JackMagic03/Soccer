/**
 * mors_pixyHandler.cpp
 */
#include "mors_pixyHandler.hpp"

MorsPixyHandler::MorsPixyHandler()
{
	this-> heading_x = 0;
	this-> heading_y = 0;

	this-> bit = 0;
}

void MorsPixyHandler::test()
{
	if(this-> pixy_ptr-> getFlg())
	{
		for(int i = 0; i < this-> pixy_ptr-> getNumBlocks(); i++)
		{
			if(this-> pixy_ptr-> getSignature(i) == 0)
			{
				heading_x = this-> pixy_ptr-> getm_x(i);
				heading_y = this-> pixy_ptr-> getm_x(i);

				bitSet(bit, 0);
			}
			if(this-> pixy_ptr-> getSignature(i) == 1)
			{
				bitSet(bit, 1);
			}
			if(this-> pixy_ptr-> getSignature(i) == 2)
			{
				bitSet(bit, 2);
			}
		}
	}
}

void MorsPixyHandler::handle()
{
	pixy_ptr-> read();
	MorsPixyHandler::test();
	/**
	 * Fa robe
	 */
}

/**
 * creare una funzione di reset
 */
