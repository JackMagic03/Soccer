/**
 * Libreria gestione sensori di linea
 *
 * Massimo Giordano, Diego de Martino
 */

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

  uint8_t flg_lines = 0;

  for(int i = 0; i < 6; i++) {

    analogReadLines[i] = analogRead(pinLines[i]);

    if(analogReadLines[i] >= sogliaBianco) {

        flg_lines = 1;    //Stiamo trovando un colore molto chiaro
        return flg_lines; //Impostiamo 1 come valore del bianco

    } else {

    }
  }
  flg_lines = 0;
  return flg_lines;
}

int test_flgLines(uint8_t flg_lines, unsigned long time_lines) {

  uint8_t flg_linesCtr = 0;

  if(flg_lines == 1) {

    unsigned long current_millis = millis();

    if(current_millis - time_lines <= 200) {

      flg_linesCtr = 1;
      return flg_linesCtr;

    } else if((current_millis - time_lines > 200) && (current_millis - time_lines <= 500)) {

      flg_linesCtr = 2;
      return flg_linesCtr;

    } else {
      flg_lines = 0;
      flg_linesCtr = 0;
      return flg_linesCtr;
    }

  } else {
    //Qualcosa
  }
}

void linesGo_flg(uint8_t flg_linesCtr) {

  if(flg_linesCtr == 1) {
    drive_stop();
  } else if(flg_linesCtr == 2) {
    //Torno in campo nn so come
  } else {

  }

}

int get_lines(int param) {
  return analogReadLines[param];
}
