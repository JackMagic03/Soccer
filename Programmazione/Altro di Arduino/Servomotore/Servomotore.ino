#include "Servo.h"

#define pinServo1 9
#define pinServo2 10

Servo Servo1;

#define pinSwitch 6

#define pinTrigger 7
#define pinEcho 8

void setup() {

  Servo1.attach(9);

  pinMode(pinSwitch, INPUT);

  pinMode(pinTrigger, OUTPUT);
  pinMode(pinEcho, INPUT);
  digitalWrite(pinEcho, LOW);

}

void loop() {

  for (int i = 0; i <= 179; i ++) {

    Servo1.write(i);

    delay(20);

  }

  for (int i = 179; i >= 0; i --) {

    Servo1.write(i);

    delay(20);

  }

}
