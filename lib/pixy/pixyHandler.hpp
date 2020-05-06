/**
 * pixyHandler.hpp
 * #author Massimo Giordano
 */

#pragma once

#include "pixy.hpp"

class PixyHandler {
  Pixy pixy_component;

  uint8_t heading_x;
  uint8_t heading_y;

  uint8_t bit;

public:
  PixyHandler();

  void test();
  void handle();
  void reset();

  uint8_t getBit();
  uint8_t getHeading_x();
  uint8_t getHeading_y();
};
