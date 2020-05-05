/**
 * imu.cpp
 * @author Massimo Giordano
 */

#include "imu.hpp"

Imu::Imu() {

}

void Imu::init(Adafruit_BNO055* t_imu_ptr) {
  this-> imu_ptr = t_imu_ptr;
  this-> imu_ptr-> begin(this-> imu_ptr-> OPERATION_MODE_IMUPLUS);

  heading = 0;
}

void Imu::read() {
  imu::Vector<3> euler = this-> imu_ptr-> getVector(Adafruit_BNO055::VECTOR_EULER);
  heading = euler.x();  //Lettura dell'asse x

  if(heading > 180) {
    heading -= 360;
  }
  /**
   * Questo passagio serve per portare la lettura della bussola
   * da 0 % 360 a -180 % +180
   */
}
