/**
 * Libreria gestione sensori di linea
 *
 * Massimo Giordano, Diego de Martino
 */

int sogliaVerde;
int sogliaBianco;
uint16_t analogReadLines[6] {0};  // L'array che contiene i valori letti dai sensori

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

int read_lines() {

  uint8_t flg_lines;

  for(int i = 0; i < 6; i++) {

    analogReadLines[i] = analogRead(pinLines[i]);

    if(analogReadLines[i] >= sogliaBianco) {
      flg_lines = 1;
      return flg_lines;
    }
  }
  return 0;
}

void test_flgLines(uint8_t flg_lines, unsigned long time_lines) {

  if(flg_lines == 1) {

    unsigned long current_millis = millis();

    if(current_millis - time_lines <= 200) {

      Serial.println("Sto FERMOOO");

    } else if((current_millis - time_lines > 200) && (current_millis - time_lines <= 500)) {

      Serial.println("Torno in Campo");

    } else {

      flg_lines = 0;

    }

  } else {
    //Qualcosa
  }
}

int get_lines(int param) {
  return analogReadLines[param];
}
