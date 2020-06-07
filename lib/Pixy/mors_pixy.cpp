/**
 * mors_pixy.cpp
 */
#include "mors_pixy.hpp"

MorsPixy::MorsPixy(Pixy2* t_pixy_ptr)
{
	this-> pixy_ptr = t_pixy_ptr;
	this-> get_blocks = 0;
	this-> num_blocks = 0;

	this-> flg = 0;
}

void MorsPixy::read()
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

uint8_t MorsPixy::getGetBlocks()
{
  return get_blocks;
}

uint8_t MorsPixy::getNumBlocks()
{
  return num_blocks;
}

uint8_t MorsPixy::getSignature(uint8_t t_i)
{
	return pixy_ptr-> ccc.blocks[t_i].m_signature;
}

uint8_t MorsPixy::getm_x(uint8_t t_i)
{
	return pixy_ptr-> ccc.blocks[t_i].m_x;
}

uint8_t MorsPixy::getm_y(uint8_t t_i)
{
	return pixy_ptr-> ccc.blocks[t_i].m_y;
}

uint8_t MorsPixy::getFlg()
{
  return flg;
}
