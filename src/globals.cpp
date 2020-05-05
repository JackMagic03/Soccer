/**
 * globals.cpp
 * @author Massimo Giordano
 */

#include "globals.hpp"

Drive drive_handler;
LineHandler line_handler;
Imu_PID imu_handler(K_P, K_I, K_D, D_T, ID_T);

Adafruit_BNO055 bno = Adafruit_BNO055(55);
