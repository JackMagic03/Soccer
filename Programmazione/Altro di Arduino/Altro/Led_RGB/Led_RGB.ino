//Massimo Giordano
//Programma led RGB
#include <Arduino.h>

int Red = 3;
int Green = 5;
int Blu = 6;
//Definiti i pin del led RGB
int pul1 = 8;
int pul2 = 9;
int pul3 = 10;
int let1 = 0;
int let2 = 0;
int let3 = 0;

void setup() 
{
  Serial.begin(9600);
  //Seriale inizializzata

  
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  //I pin del led sono di uscita
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  //I pin del led sono di uscita
}


void loop() {
  let1 = digitalRead(pul1);
  let2 = digitalRead(pul2);
  let3 = digitalRead(pul3);
  if(let1 == 1)
  {
  analogWrite(Red, 255);
  delay(3000);
  analogWrite(Red, 0); 
  }
  
  if(let2 == 1)
  {
  analogWrite(Green, 255);
  delay(3000);
  analogWrite(Green, 0);
  }
  
  if(let3 == 1)
  {
  analogWrite(Blu, 255);
  delay(3000);
  analogWrite(Blu, 0);
  }
  
  }
  
