/**
 * imu.hpp
 * @author Massimo Giordano
 */

#pragma once
#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include <Math.h>

class Imu {
  Adafruit_BNO055 bno;
  int heading;
public:
  Imu();

  void read();
  int getHeading();
};
