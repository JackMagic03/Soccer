/*
    Semaforo a tempo
    Dragone, Giordano e Miccoli; 3Ant;
*/

#include <Arduino.h>

/*
    Sono i pin a cui sono agganciati i componenti elettrici
*/
const byte pin_ledRosso = 3;
const byte pin_ledGiallo = 4;
const byte pin_ledVerde = 5;
const byte pin_pulsante = 6;

/*
    Variabile di controllo
*/
unsigned long tempo;

void setup()
{
    pinMode(pin_ledRosso, OUTPUT);
    pinMode(pin_ledGiallo, OUTPUT);
    pinMode(pin_ledVerde, OUTPUT);
    pinMode(pin_pulsante, INPUT);
    /////////////////////////////////

    digitalWrite(pin_ledRosso, LOW);
    digitalWrite(pin_ledGiallo, LOW);
    digitalWrite(pin_ledVerde, LOW);
    digitalWrite(pin_pulsante, LOW);
    /////////////////////////////////

    tempo = millis();
}

void loop()
{

    while ((millis() - tempo) <= 4999)
    {
        digitalWrite(pin_ledRosso, LOW);
        digitalWrite(pin_ledGiallo, LOW);
        digitalWrite(pin_ledVerde, HIGH);
    }

    while(5000 <= (millis() - tempo) && (millis() - tempo) <= 5999)
    {
        digitalWrite(pin_ledRosso, LOW);
        digitalWrite(pin_ledGiallo, HIGH);
        digitalWrite(pin_ledVerde, HIGH);
    }

    while((6000 <= (millis() - tempo) && (millis() - tempo) <= 8999) && digitalRead(6) == LOW)
    {
        digitalWrite(pin_ledRosso, HIGH);
        digitalWrite(pin_ledGiallo, LOW);
        digitalWrite(pin_ledVerde, LOW);
    }

    digitalWrite(pin_ledRosso, HIGH);
    delay(3000);

    tempo = millis();
}
