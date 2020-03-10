/**
 * Libreria gestione bussola
 *
 * Massimo Giordano, Diego de Martino
 */

void PhoenixImu_init() {

  bno.begin(bno.OPERATION_MODE_IMUPLUS);

  // if(!bno.begin())
  //  {
  //    /* There was a problem detecting the BNO055 ... check your connections */
  //    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
  //    while(1);
  //  }
  //
  //  delay(1000);

}

int imu_read() {

  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  int read_imu = euler.x();
  return read_imu;

}

void PhoenixImu_test() {

  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);

  Serial.print("X: ");
  Serial.println(euler.x());

}
