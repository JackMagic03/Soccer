//Sensore_ultrasuoni_con_funzione
//Massimo_Giordano
#define echo=9;

#define trigger=10;

void setup() {

  Serial.begin(9600);

  pinMode(echo,INPUT);
  pinMode(trigger,OUTPUT);
  digitalWrite(echo,LOW);

}


void loop() {

  int distanza = DIST();

  Serial.print(distanza);
  Serial.println(" cm");

}

int DIST() {
  digitalWrite(trigger,LOW);
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);

  digitalWrite(trigger,LOW);

  long durata = pulseIn(echo,HIGH);
  long distanza = 0.034*durata/2;

  Serial.print("Distanza: ");

  if(distanza>3800) {

    Serial.print("Fuori portata");

  } else {

      return distanza;

    }

return 0;

}
