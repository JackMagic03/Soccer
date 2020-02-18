#include "mors_libras.h"
#include "mors_compass.h"

void setup()	{

  PhoenixJoints_init();

  PhoenixDrive_init();

  PhoenixImu_init();

}

void loop()	{

  PhoenixImu_read();

  PhoenixDrive_setSpeed(0, 200, read_imu);

}
