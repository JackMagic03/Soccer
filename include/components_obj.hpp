/**
 * components_obj.hpp
 */

#ifndef COMPONENTS_OBJ_HPP
#define COMPONENTS_OBJ_HPP

#include "joints.hpp"
#include "line.hpp"
#include "imu.hpp"
#include "pixy.hpp"

extern Joints joint_1;
extern Joints joint_2;
extern Joints joint_3;

extern Line line_vect[NUM_LINES];

extern Imu imu_component;
extern Pixy pixy_component;

#endif
