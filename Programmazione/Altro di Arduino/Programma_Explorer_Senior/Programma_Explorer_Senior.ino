
//Massimo Giordano
//Programma Explorer Senior

#define dirA 2
#define dirB 4
#define pwmA 3
#define pwmB 11
/////////////////////////Motori

#define lightDx A1
#define lightSx A2
#define lightCn A3
/////////////////////////Luce

#define bumpSx 7
#define bumpDx 8
/////////////////////////Bumper

#define Gas A4
/////////////////////////Gas

#define Sound A5
/////////////////////////Suono

#define Red 5
#define Green 6
#define Blu 9
/////////////////////////Led

void setup()
{
  Serial.begin(9600);   //Seriale Inizializzata

  pinMode(dirA, OUTPUT);
  pinMode(dirB, OUTPUT);
  pinMode(pwmA, OUTPUT);
  pinMode(pwmB, OUTPUT);
  //////////Motori

  pinMode(bumpSx, INPUT);
  pinMode(bumpDx, INPUT);
  //////////Bumper

  pinMode(lightCn, INPUT);
  pinMode(lightSx, INPUT);
  pinMode(lightDx, INPUT);
  //////////Light

  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Blu, OUTPUT);
  digitalWrite(Red, HIGH);
  digitalWrite(Green, HIGH);
  digitalWrite(Blu, HIGH);
  //////////Led
}

void loop()
{
  avanti();
  /////////

  LuceSx();

  if(LuceSx() == true)
  {
    fermo();
    ledVerde();
    indietro();
    destra();
    delay(600);
    avanti();
    delay(500);
    bumper();
    sound();
  }
  else
  {
    LuceDx();
  }

  if(LuceDx() == true)
  {
    fermo();
    ledVerde();
    indietro();
    sinistra();
    delay(600);
    avanti();
    delay(500);
    bumper();
    sound();
  }
  else
  {
    LuceCn();
  }

  if(LuceCn() == true)
  {
    fermo();
    ledVerde();
    indietro();
    sinistra();
    delay(600);
    avanti();
    delay(500);
    bumper();
    sound();
  }
  else
  {
    sound();
  }

  if(sound() == true)
  {
    fermo();
    ledGiallo();
    avanti();
    delay(1000);
    bumper();
    gas();
  }
  else
  {
    gas();
  }

  if(gas() == true)
  {
    fermo();
    ledRosso();
    avanti();
    delay(1000);
    bumper();
  }
  else
  {
    bumper();
  }
}
