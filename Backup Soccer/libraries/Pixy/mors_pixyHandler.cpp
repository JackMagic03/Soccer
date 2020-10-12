/**
 * mors_pixyHandler.cpp
 */
#include "mors_pixyHandler.hpp"

MorsPixyHandler::MorsPixyHandler(Pixy2* t_pixy_ptr)
{
	this-> pixy_ptr = t_pixy_ptr;

	this-> get_blocks = 0;
	this-> num_blocks = 0;
	this-> heading_x = 0;
	this-> heading_y = 0;

	this-> flg = 0;
	this-> bit = 0;
}

void MorsPixyHandler::read()
{
	this-> get_blocks = this-> pixy_ptr-> ccc.getBlocks();
	this-> num_blocks = this-> pixy_ptr-> ccc.numBlocks;

	if(this-> get_blocks > 0)
	{
		if(this-> num_blocks)
		{
		this-> flg = HIGH;
		}
		else
		{
		this-> flg = 0;
		}
	}
}

void MorsPixyHandler::test()
{
	if(this-> flg)
	{
		for(int i = 0; i < this-> num_blocks; i++)
		{
			if(this-> pixy_ptr-> ccc.blocks[i].m_signature == 0)
			{
				heading_x = this-> pixy_ptr-> ccc.blocks[i].m_x;
				heading_y = this-> pixy_ptr-> ccc.blocks[i].m_y;

				bitSet(bit, 0);
			}
			if(this-> pixy_ptr-> ccc.blocks[i].m_signature == 1)
			{
				bitSet(bit, 1);
			}
			if(this-> pixy_ptr-> ccc.blocks[i].m_signature == 2)
			{
				bitSet(bit, 2);
			}
		}
	}
}

void MorsPixyHandler::handle()
{
	MorsPixyHandler::read();
	MorsPixyHandler::test();
	/**
	 * Fa robe
	 */
}

/**
 * creare una funzione di reset
 */
