//Massimo Giordano
//Funzioni Led

void ledRosso()
{
digitalWrite(Red, LOW);
digitalWrite(Green, HIGH);
digitalWrite(Blu, HIGH);
delay(3000);
digitalWrite(Red, HIGH);
}
/////////////////////////
  
void ledVerde()
{
digitalWrite(Red, HIGH);
digitalWrite(Green, LOW);
digitalWrite(Blu, HIGH);
delay(3000);
digitalWrite(Green, HIGH);
}
/////////////////////////
  
void ledGiallo()
{
digitalWrite(Red, LOW);
analogWrite(Green, 100);
digitalWrite(Blu, HIGH);
delay(3000);
digitalWrite(Red, HIGH);
digitalWrite(Green, HIGH);
}
/////////////////////////
