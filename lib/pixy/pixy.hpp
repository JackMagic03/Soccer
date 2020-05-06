/**
 * pixy.hpp
 * @author Massimo Giordano
 */
#pragma once

#include <Pixy2.h>
#include <Wire.h>
extern Pixy2 pixy;
class Pixy {
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
