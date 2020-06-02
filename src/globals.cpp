/**
 * globals.cpp
 * @author Massimo Giordano
 */

#include "globals.hpp"

Drive drive_handler;
LineHandler line_handler;
Imu_PID imu_handler(K_P, K_I, K_D, D_T, ID_T);
//Pixy2 pixy;
//PixyHandler pixy_handler;
