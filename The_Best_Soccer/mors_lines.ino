/**
 * Libreria gestione sensori di linea
 *
 * Massimo Giordano, Diego de Martino
 */

// typedef struct{
//
//   int sogliaBianco;
//   int readingLines[6];
//
//   uint8_t flg_lines;
//   uint8_t old_flgLines;
//   uint8_t flg_linesCtr;
//   unsigned long time_lines;
//   uint8_t bit_lines;
//
// }PhoenixLine;

int sogliaBianco;
/**
 * La soglia va impostata sperimentalmente, provando con diverse illuminazioni
 * e angolazioni i valori che restituisce e se ne fa una media.
 */

int readingLines[6];
/**
 * L'array dedicato alla lettura dei sensori di linea ha dimensione 6;
 * quando andiamo ad aggiungerlo nella funzione di lettura, dobbiamo inserire dei
 * controlli ulteriori, per fare in modo che i sensori diventno 4: N, S, E, W.
 *
 * Successivamente dobbiamo salvare le letture in una variabile e dobbiamo assegnare
 * una lettura per ogni bit della variabile. Per farlo dobbiamo usare le funzioni della
 * libreria di arduino bit.
 *
 * Per settare il singolo bit si usa la funzione bitSet(variabile, bit);
 * Per resettare la variabile si usa bitClear(variabile, bit);
 * Per leggere il valore di un singolo bit si usa bitRead(variabile, bit);
 */

void init_lines() {

  for(int i = 0; i < 6; i++) {
    pinMode(pinLines[i], INPUT);
    readingLines[i] = 0;
  }
  // sbi(ADCSRA, ADPS2);
  // cbi(ACDSRA, ADPS1);
  // cbi(ACDSRA, ADPS0);

}
void test_lines() {

  for(int i = 0; i < 6; i++) {

    readingLines[i] = analogRead(pinLines[i]);
    Serial.print("Leggo il pin ");
    Serial.print(i + 1);
    Serial.print("   ");
    Serial.println(readingLines[i]);
    delay(50);

  }
}

int read_lines(uint8_t *bit_ctr) {
  /**
   * Ho passato il puntatore con lo stesso metodo per cui ho passato lel coordinate
   * della palla alle bariabili "block_x" e "block_y", dichiarate nel loop;
   */

  uint8_t flg_lines = 0;

  *bit_ctr = 0;
  /**
   * La variabile bit_ctr serve per tenere conto di quanti e quali sensori hanno
   * rilevato la presenza della linea bianca.
   *
   * Ragioniamo cosi:
   *
   *  => Se il bit 0 assume il valore alto, i due sensori anteriori hanno rilevato il bianco;
   *
   *  => Se il bit 1 assume il valore alto, il sensore di destra ha rilevato il bianco;
   *
   *  => Se il bit 2 assume il valore alto, i due sensori posteriori hanno rilevato il bianco;
   *
   *  => Se il bit 3 assume il valore alto, il sensore di sinistra ha trovato il bianco.
   */

   for(int i = 0; i < 6; i++) {

     readingLines[i] = analogRead(pinLines[i]);

   }

  if(readingLines[0] >= sogliaBianco || readingLines[1] >= sogliaBianco) {
    /**
     * Impostare il bit 0 della variabile "bit_ctr" al valore 1;
     */
    flg_lines = 1;

  } else {

  }
  if (readingLines[2] >= sogliaBianco) {
    /**
     * Impostare il bit 1 della variabile "bit_ctr" al valore 1;
     */
    flg_lines = 1;

  } else {

  }
  if (readingLines[3] >= sogliaBianco || readingLines[4] >= sogliaBianco) {
    /**
     * Impostare il bit 2 della variabile "bit_ctr" al valore 1;
     */
    flg_lines = 1;

  } else {

  }
  if (readingLines[5] >= sogliaBianco) {
    /**
     * Impostare il bit 3 della variabile "bit_ctr" al valore 1;
     */
    flg_lines = 1;

  } else {

  }
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
  return readingLines[param];
}
