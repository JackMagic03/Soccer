/**
 * main.cpp
**/
#include "Arduino.h"

void setup() {
  Serial.begin(115200);
}

void loop() {
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500);
  Serial.print("Hello World\n");
}
