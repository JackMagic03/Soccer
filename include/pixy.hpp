/**
 * pixy.hpp
 */
#ifndef PIXY_HPP
#define PIXY_HPP

#include "components.hpp"
#include <Arduino.h>

class Pixy 
{
  uint8_t get_blocks;
  uint8_t num_blocks;

  uint8_t flg;

public:
  Pixy();

  void read();
  uint8_t getGetBlocks();
  uint8_t getNumBlocks();
  uint8_t getFlg();
};

#endif
