//Massimo Giordano
//Funzioni Motori

void sinistra()
{
  digitalWrite(dirB, HIGH);
  digitalWrite(dirA, LOW);
  analogWrite(pwmA, 100);
  analogWrite(pwmB, 100);
}
////////////////////////

void destra()
{
  digitalWrite(dirB, LOW);
  digitalWrite(dirA, HIGH);
  analogWrite(pwmA, 100);
  analogWrite(pwmB, 100);
}
////////////////////////

void avanti()
{
  digitalWrite(dirB, LOW);
  digitalWrite(dirA, LOW);
  analogWrite(pwmA, 235);
  analogWrite(pwmB, 200);
}
////////////////////////

void indietro()
{
  digitalWrite(dirB, HIGH);
  digitalWrite(dirA, HIGH);
  analogWrite(pwmA, 140);
  analogWrite(pwmB, 150);
  delay(200);
}
////////////////////////

void fermo()
{
  analogWrite(pwmA, 0);
  analogWrite(pwmB, 0);
}