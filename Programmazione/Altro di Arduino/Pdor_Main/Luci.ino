//Massimo Giordano
//Funzuini Fotoresistenze

void initLight() {

  pinMode(lightCn, INPUT);
  pinMode(lightSx, INPUT);
  pinMode(lightDx, INPUT);

}

void light()
{

  int readDx = analogRead(lightDx);
  
  if(readDx>=sogliaDx)
  {

    fermo();
    ledVerde();
    delay(3000);
    sinistra();
    delay(500);
    avanti();

  }

  int readCn = analogRead(lightCn);

  if(readCn>=sogliaCn)

  {
    fermo();
    ledVerde();
    delay(3000);
    indietro();
    delay(500);
    sinistra();
    delay(500);
    avanti();

  }

  int readSx = analogRead(lightSx);

  if(readSx >= sogliaSx) {

    fermo();
    ledVerde();
    delay(3000);
    destra();
    delay(500);
    avanti();

  }
}
