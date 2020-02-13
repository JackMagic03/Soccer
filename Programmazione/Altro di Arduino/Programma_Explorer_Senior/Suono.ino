//Massimo Giordano
//Funzioni Sensore di Suono

boolean sound()
{
  #define sogliaSound 460
  int readSound = analogRead(Sound);
  if(readSound >= sogliaSound)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}