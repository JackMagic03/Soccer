#define PIN_MOTORE 3
#define PIN_BOTTONE 4
#define PIN_POTENZA A0
#define TEMPO_ACCENSIONE 400

void setup()
{
  pinMode(PIN_MOTORE, OUTPUT);
  pinMode(PIN_BOTTONE, INPUT);
}

void loop()
{
  bool Attivo = false;
  int UltimoStato = LOW;
  int StatoPulsante = digitalRead(PIN_BOTTONE);
  if(StatoPulsante != UltimoStato && StatoPulsante == HIGH)
  {
    if(!Attivo)
    {
      unsigned long StartTime = millis();
    }
    Attivo = !Attivo;
  }
  UltimoStato = StatoPulsante;

  if(Attivo)
  {
    if((millis()-StartTime) > TEMPO_ACCENSIONE)
    {
      int VelocitaMotore = map(analogRead(PIN_POTENZA), 0, 1023, 70, 255);
      analogWrite(PIN_POTENZA, VelocitaMotore);
    }
    else
    {
      analogWrite(PIN_MOTORE, 255);
    }
    
  }
  else
  {
    analogWrite(PIN_MOTORE, 0);
  }
  delay(50);
}