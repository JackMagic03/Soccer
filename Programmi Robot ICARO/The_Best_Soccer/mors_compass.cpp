#include "mors_compass.h"

int read_imu;
Adafruit_BNO055 bno = Adafruit_BNO055(55);

void PhoenixImu_init() {

  bno.begin(bno.OPERATION_MODE_IMUPLUS);

}

void PhoenixImu_read() {

  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  read_imu = euler.x();

}

void PhoenixImu_test() {

  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  Serial.print("X: ");
  Serial.println(euler.x());

}
