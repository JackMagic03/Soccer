/**
 * imu.ino => Gestire la bussola e le correzioni che ne seguono
 * @author Massimo Giordano
 */

void morsimu_init() {

  bno.begin(bno.OPERATION_MODE_IMUPLUS);

}

int morsimu_read() {

  imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
  int read_imu = euler.x();
  return read_imu;

}
