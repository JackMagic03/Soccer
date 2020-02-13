//Massimo Giordano

#include <Arduino.h>

void setup()
{
    pinMode(5, OUTPUT);
    pinMode(6, INPUT);
}

void loop()
{
    if(digitalRead(6) == HIGH)
    {
    digitalWrite(5, HIGH);
    }
    else
    {
        digitalWrite(5, LOW);
    }
    
}