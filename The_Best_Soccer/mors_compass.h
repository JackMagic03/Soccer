#pragma once

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

//  #define scl_imu 21
//  #define sda_imu 20

extern int read_imu;
extern Adafruit_BNO055 bno;

void PhoenixImu_init();
void PhoenixImu_read();
void PhoenixImu_test();
