#include "mors_globals.h"
#include "mors_joints.h"
#include "mors_drive.h"
#include "mors_params.h"
#include "mors_compass.h"
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

void setup()	{

  Serial.begin(9600);

  for(int i = 0; i < NUM_JOINTS; i++) {
    PhoenixJoints_init(&joints[i]);
  }

  PhoenixDrive_init(&drive);

  PhoenixImu_init();

}

void loop()	{

  PhoenixImu_read();

  PhoenixDrive_setSpeed(&drive, 0, 200, read_imu);

}