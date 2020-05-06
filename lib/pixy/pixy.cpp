/**
 * pixy.cpp
 * @author Massimo Giordano
 */

#include "pixy.hpp"

Pixy::Pixy() {
  pixy.init();

  get_blocks = 0;
  num_blocks = 0;

  flg = 0;
}

void Pixy::read() {

  get_blocks = pixy.ccc.getBlocks();
  num_blocks = pixy.ccc.numBlocks;

  if(get_blocks > 0) {
    if(num_blocks) {
      flg = HIGH;
    }
    else {
      flg = 0;
    }
  }
}

uint8_t Pixy::getGetBlocks() {
  return get_blocks;
}

uint8_t Pixy::getNumBlocks() {
  return num_blocks;
}

uint8_t Pixy::getFlg() {
  return flg;
}
