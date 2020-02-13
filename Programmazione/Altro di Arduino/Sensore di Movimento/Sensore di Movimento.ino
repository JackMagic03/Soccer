#define pinMoove 7

#define pinBuz 13

uint8_t readMoove = LOW;

void setup() {

  pinMode(pinMoove, INPUT);
  pinMode(pinBuz, OUTPUT);

  digitalWrite(pinBuz, LOW);

}

void loop() {

  readMoove = digitalRead(pinMoove);

  if(readMoove == HIGH) {

    buzPlay(10, 5);
    delay(500);

  } else {

    digitalWrite(pinBuz, LOW);

  }

  readMoove = LOW;

}

void buzPlay(uint8_t max, uint8_t del) {

  for(int rep = 0; rep < max; rep ++) {

    digitalWrite(pinBuz, HIGH);
    delay(del);

    digitalWrite(pinBuz, LOW);
    delay(del);

  }

}
