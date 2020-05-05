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
public:
  Adafruit_BNO055* imu_ptr;
  int heading;

  Imu();
  void init(Adafruit_BNO055* t_imu_ptr);
  void read();
};
