//Massimo Giordano
//Funzioni Bumper

void initBump() {

  pinMode(bumpSx, INPUT_PULLUP);
  pinMode(bumpDx, INPUT_PULLUP);

}

void bumper()
{

  StatoBump1 = digitalRead(bumpSx);
  StatoBump2 = digitalRead(bumpDx);

  if        (StatoBump1 == HIGH && StatoBump2 == HIGH) {

    avanti();
    delay(10);

  } else if (StatoBump1 == LOW && StatoBump2 == HIGH) {
    
    indietro();
    delay(200);
    destra();
    delay(250);
    avanti();
    
  } else if (StatoBump1 == HIGH && StatoBump2 == LOW) {

    indietro();
    delay(200);
    sinistra();
    delay(250);
    avanti();
    
  } else if (StatoBump1 == LOW && StatoBump2 == LOW) {

    indietro();
    delay(200);
    sinistra();
    delay(250);
    avanti();
    
  }

  StatoBump1 = HIGH;
  StatoBump2 = HIGH;

}
