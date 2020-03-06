/**
 * Libreria gestione sensori di linea
 *
 * Massimo Giordano, Diego de Martino
 */

int sogliaVerde;
int sogliaBianco;

void test_lines() {

  for(int i = 0; i < 6; i++) {

    analogReadLines[i] = analogRead(pinLines[i]);
    Serial.print("Leggo il pin ");
    Serial.print(i);
    Serial.print("   ");
    Serial.println(analogReadLines[i]);
    delay(50);

  }
}

void read_lines() {

  uint8_t flg_lines;

  for(int i = 0; i < 6; i++) {

    analogReadLines[i] = analogRead(pinLines[i]);
    if(analogReadLines[i] >= sogliaBianco) flg_lines = 1;

  }

  if(flg_lines == 1) {

    unsigned long time_lines = millis();
    while((millis() - time_lines) <= 200) Serial.println("Sto FERMOOO");

    time_lines = millis();
    while((millis() - time_lines) <= 500) Serial.println("Torno in Campo");

  } else {

    //Qualcosa

  }
}
