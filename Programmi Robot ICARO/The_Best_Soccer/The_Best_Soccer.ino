#include <Arduino.h>
#include "mors_globals.h"
#include "mors_joints.h"
#include "mors_drive.h"
#include "mors_params.h"

void setup()	{

  Serial.begin(9600);

  for(int i = 0; i < NUM_JOINTS; i++) {
    PhoenixJoints_init(&joints[i]);
  }

  PhoenixDrive_init(&drive);

}

void loop()	{

  for(int i = 0; i < 360; i++) {
    PhoenixDrive_setSpeed(&drive, i, 200);
    delay(5);
  }

}
