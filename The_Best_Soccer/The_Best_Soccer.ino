#include "mors_libras.h"

void setup()	{

  Serial.begin(9600);

  PhoenixJoints_init();

  PhoenixDrive_init();

  PhoenixImu_init();

}

void loop()	{

  PhoenixImu_read();

  PhoenixDrive_setSpeed(0, 200, read_imu);

}
