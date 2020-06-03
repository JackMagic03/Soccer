/**
 * pixy_handler.cpp
 */
#include "pixy_handler.hpp"

PixyHandler::PixyHandler()
{
	pixy_ptr = &pixy_component;
	heading_x = 0;
	heading_y = 0;

	bit = 0;
}

void PixyHandler::test()
{
	if(pixy_component.getFlg())
	{
		for(int i = 0; i < pixy_component.getNumBlocks(); i++)
		{
			if(pixy.ccc.blocks[i].m_signature == 0)
			{
				heading_x = pixy.ccc.blocks[i].m_x;
				heading_y = pixy.ccc.blocks[i].m_y;

				bitSet(bit, 0);
			}
			if(pixy.ccc.blocks[i].m_signature == 1)
			{
				bitSet(bit, 1);
			}
			if(pixy.ccc.blocks[i].m_signature == 2)
			{
				bitSet(bit, 2);
			}
		}
	}
}

void PixyHandler::handle()
{
	pixy_component.read();
	PixyHandler::test();
	/**
	 * Fa robe
	 */
}

/**
 * creare una funzione di reset
 */
