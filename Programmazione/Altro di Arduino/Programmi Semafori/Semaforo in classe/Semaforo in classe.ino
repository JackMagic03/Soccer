// Semaforo pedonale
//Massimo Giordano -> 28/11/2019
#include <Arduino.h>

#define ledRosso = 3;  //Il pin a cui si attacca il led Rosso
#define ledGiallo = 4; //Il pin a cui si attacca il led Giallo
#define ledVerde = 5;  //Il pin a cui si attacca il led Verde
#define pulsante = 6;  //Il pin a cui si attacca il pulsante

byte statoPulsante = 0;   //È la variabile che se il pulsante è premuto o meno

void setup()
{
    pinMode(ledRosso, OUTPUT);
    pinMode(ledGiallo, OUTPUT);
    pinMode(ledVerde, OUTPUT);
    pinMode(pulsante, INPUT);
}

void loop()
{

    /*
    Bisogna decidere se si vuole fare un semaforo esclusivamente
    pedonale oppure se farlo anche per le macchine.
    */

    //Semaforo SOLO pedonale

    digitalWrite(ledRosso, HIGH);
    /*
    Il rosso pedonale è attivo quindi è attivo
    il verde pre le macchine
    */

    statoPulsante = digitalRead(pulsante);

    if(statoPulsante == HIGH)
    {
        digitalWrite(ledVerde, HIGH);
        delay(4000);
        digitalwrite(ledVerde, LOW);
        digitalWrite(ledGiallo, HIGH);
        delay(1000);
        digitalWrite(ledGiallo, LOW);
    }
}
