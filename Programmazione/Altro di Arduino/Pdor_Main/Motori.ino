//Massimo Giordano
//Funzioni Motori

void initMot() {

  pinMode(inA_1, OUTPUT);
  pinMode(inA_2, OUTPUT);
  pinMode(inB_1, OUTPUT);
  pinMode(inB_2, OUTPUT);
  pinMode(pwm_1, OUTPUT);
  pinMode(pwm_2, OUTPUT);
  fermo();

}

void avanti()
{

  digitalWrite(inA_1, HIGH);
  digitalWrite(inB_1, LOW);
  analogWrite(pwm_1, 210);

  digitalWrite(inA_2, HIGH);
  digitalWrite(inB_2, LOW);
  analogWrite(pwm_2, 200);

}

void indietro() {

  digitalWrite(inA_1, LOW);
  digitalWrite(inB_1, HIGH);
  digitalWrite(pwm_1, HIGH);

  digitalWrite(inA_2, LOW);
  digitalWrite(inB_2, HIGH);
  digitalWrite(pwm_2, HIGH);

}

void sinistra() {

  digitalWrite(inA_1, LOW);
  digitalWrite(inB_1, HIGH);
  digitalWrite(pwm_1, HIGH);

  digitalWrite(inA_2, HIGH);
  digitalWrite(inB_2, LOW);
  digitalWrite(pwm_2, HIGH);

}

void destra() {

  digitalWrite(inA_1, HIGH);
  digitalWrite(inB_1, LOW);
  digitalWrite(pwm_1, HIGH);

  digitalWrite(inA_2, LOW);
  digitalWrite(inB_2, HIGH);
  digitalWrite(pwm_2, HIGH);

}

void fermo() {

  digitalWrite(pwm_1, LOW);
  digitalWrite(pwm_2, LOW);
}
