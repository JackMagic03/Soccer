#include "mors_globals.h"
#include "mors_joints.h"
#include "mors_drive.h"
#include "mors_params.h"
#include "mors_compass.h"

void setup()	{

  Serial.begin(9600);

  PhoenixJoints_init(&joints);

  PhoenixDrive_init(&drive);

  PhoenixImu_init();

}

void loop()	{

  PhoenixImu_read();

  PhoenixDrive_setSpeed(&drive, 0, 200, read_imu);

}
