/**
 * Massimo Giordano
 *
 * Funzioni led RGB
 */

 void ledRosso()
 {
 digitalWrite(Red, LOW);
 digitalWrite(Green, HIGH);
 digitalWrite(Blue, HIGH);
 delay(3000);
 digitalWrite(Red, HIGH);
 }
 /////////////////////////

 void ledVerde()
 {
 digitalWrite(Red, HIGH);
 digitalWrite(Green, LOW);
 digitalWrite(Blue, HIGH);
 delay(3000);
 digitalWrite(Green, HIGH);
 }
 /////////////////////////

 void ledGiallo()
 {
 digitalWrite(Red, LOW);
 analogWrite(Green, 100);
 digitalWrite(Blue, HIGH);
 delay(3000);
 digitalWrite(Red, HIGH);
 digitalWrite(Green, HIGH);
 }
 /////////////////////////
