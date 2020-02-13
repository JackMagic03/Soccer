//Massimo Giordano
//Programma Fade led
#include <Arduino.h>
int Led = 11;
//Definita la variabile Led al pin 13 che ha già una resistenza integrata

int Incremento;
//Definita la velocità di cambiamento della luminosità

int Lucentezza = 0;
//Indicata la variabile "Lucentezza"

void setup()
{
  pinMode(Led, OUTPUT);
  //La variabile è di OUTPUT

}
//Il setup è concluso

void loop()
{
  analogWrite(Led, Lucentezza);
  //Invia alla porta 9 la tensione di (5/255) *Lucentezza

  if(Lucentezza == 255)
  {
    Incremento = -5;
  }

  if(Lucentezza == 0)
  {
    Incremento = 5;
  }

  Lucentezza += Incremento;

  delay(50);
  //Impostiamo un ritardo di 50 millisecondi nella ripetizione del loop
}
