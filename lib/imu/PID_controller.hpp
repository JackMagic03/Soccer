/**
 * PID_controller.hpp
 * @author Massimo Giordano
 */

#pragma once
#include "imu.hpp"
#include "config.hpp"

class Imu_PID {
  Imu imu_component;
  
  float set_point, input, output;

  float k_p, k_i, k_d;  //Le componenti della correzione PID
  float error, prev_error, tot_error;

  float d_t, id_t;
  //    0.01, 100
public:
  Imu_PID(float t_k_p, float t_k_i, float t_k_d, float t_d_t, float t_id_t);

  void handle();
  float getOutput();
};
