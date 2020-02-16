#include "mors_libras.h"

void setup()	{

  PhoenixJoints_init();

  PhoenixDrive_init();

  PhoenixImu_init();

}

void loop()	{

  PhoenixImu_read();

  PhoenixDrive_setSpeed(0, 200, read_imu);

}
