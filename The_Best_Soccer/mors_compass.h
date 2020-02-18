#pragma once

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

extern int read_imu;
extern Adafruit_BNO055 bno;

void PhoenixImu_init();
void PhoenixImu_read();
void PhoenixImu_test();
