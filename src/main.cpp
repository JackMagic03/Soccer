/**
 * main.cpp
 */


#include "Arduino.h"
#include "globals.hpp"
#include <mors_lineHandler.hpp>
#include <mors_drive.hpp>
#include <mors_imuHandler.hpp>
#include <mors_pixyHandler.hpp>
#include <mors_attackPlanner.hpp>
#include <mors_defensePlanner.hpp>

void setup()
{
  Serial.begin(115200);
  for (int i = 0; i < 3; ++i) {
    joint_vect[i].printInfo();
  }
}

void loop()
{
  Serial.print("Hello World!\n");
  joint_vect[0].setSpeed(10);
  delay(500);
  
  
}
