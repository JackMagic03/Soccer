/**
 * components_obj.cpp
 */

#include "components_obj.hpp"
#include <Arduino.h>

Joints joint_1(&PIN_DIR_A[0], &PIN_DIR_B[0], &PIN_PWM[0]);
Joints joint_2(&PIN_DIR_A[1], &PIN_DIR_B[1], &PIN_PWM[1]);
Joints joint_3(&PIN_DIR_A[2], &PIN_DIR_B[2], &PIN_PWM[2]);

Line line_vect[NUM_LINES];

for(int i = 0; i < NUM_LINES; i++)
{
  /**
   * inizializzazione array di oggetti linee
   */

	line_vect.init(&PIN_LINEE[i], &ANGOLI_LINEE[i], &SOGLIS_LINEE[i]);
}

Imu imu_component;
Pixy pixy_component;
