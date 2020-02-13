//Massimo Giordano
//Funzioni Bumper

void bumper()
{
  byte UltimoStato1 = LOW;
  byte StatoBump1 = digitalRead(bumpSx);

  if(StatoBump1 != UltimoStato1 && StatoBump1 == HIGH)
  {
    indietro();
    destra();
    delay(600);
    avanti();
  }
  UltimoStato1 = StatoBump1;
  /////////////////////////

  byte UltimoStato2 = LOW;
  byte StatoBump2 = digitalRead(bumpDx);
  
  if(StatoBump2 != UltimoStato2 && StatoBump2 == HIGH)
  {
    indietro();
    sinistra();
    delay(600);
    avanti();
    delay(400);
  }
  UltimoStato2 = StatoBump2;
  /////////////////////////
}
