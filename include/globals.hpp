/**
 * globals.hpp
 * @author Massimo Giordano
 */

#pragma once
#include "joints.hpp"
#include "drive.hpp"
#include "lineHandler.hpp"
#include "PID_controller.hpp"
#include "config.hpp"

extern Drive drive_handler;
extern LineHandler line_handler;
extern Imu_PID imu_handler;

extern Adafruit_BNO055 bno;
