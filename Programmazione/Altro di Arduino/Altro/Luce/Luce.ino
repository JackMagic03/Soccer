int luce = A0;
void setup() {
  Serial.begin(9600);
  pinMode(luce,INPUT);
}

void loop() {
  int sensore=analogRead(A0);
  Serial.println(sensore);
  delay(20);
}
