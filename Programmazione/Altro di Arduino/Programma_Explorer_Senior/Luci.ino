//Massimo Giordano
//Funzuini Fotoresistenze

void light()
{  
  #define sogliaCn 665
  #define sogliaDx 650
  #define sogliaSx 690
  ////////////////////

  int readDx = analogRead(lightDx);
  if(readDx>=sogliaDx)
  {
    fermo();
    ledVerde();
    sinistra();
    delay(600);
    avanti();
  }
  /////////////

  
  /////////////

  int readCn = analogRead(lightCn);
  if(readCn>=sogliaCn)
  {
    fermo();
    ledVerde();
    indietro();
    sinistra();
    delay(600);
    avanti();
  }
}

boolean LuceSx ()
{
  #define SogliaSx 700
  int readSx = analogRead(lightSx);
  
  if(readSx >= SogliaSx)
  {
    return 1;
  }
  else
  {
    return 0;
  } 
}

boolean LuceDx ()
{
  #define SogliaDx 700
  int readDx = analogRead(lightDx);
  
  if(readDx >= SogliaDx)
  {
    return 1;
  }
  else
  {
    return 0;
  } 
}

boolean LuceCn ()
{
  #define SogliaCn 700
  int readCn = analogRead(lightCn);
  
  if(readCn >= SogliaCn)
  {
    return 1;
  }
  else
  {
    return 0;
  } 
}
