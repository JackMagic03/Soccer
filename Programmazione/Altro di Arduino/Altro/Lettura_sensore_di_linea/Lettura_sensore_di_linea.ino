#define ricevitore A1

void setup() {

  Serial.begin(9600);

}

void loop() {

  int lettura = analogRead(ricevitore);
  Serial.println(lettura);

}
