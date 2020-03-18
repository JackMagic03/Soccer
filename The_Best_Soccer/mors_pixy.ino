/**
 * Libreria gestione camera
 *
 * Massimo Giordano, Diego de Martino
 */

void pixy_test() {

  pixy.ccc.getBlocks();

  if(pixy.ccc.numBlocks) {

    Serial.println(pixy.ccc.numBlocks);
    Serial.println(" --- ");

    for(int i=0; i<pixy.ccc.numBlocks; i++){
      pixy.ccc.blocks[i].print();
    }
  }
}

int read_pixy(uint8_t *GET_BLOCKS, uint8_t *NUM_BLOCKS) {

  uint8_t flg_pixy = 0;

  *GET_BLOCKS = pixy.ccc.getBlocks();
  *NUM_BLOCKS = pixy.ccc.numBlocks;

  if(*GET_BLOCKS > 0) {

    if(*NUM_BLOCKS) {

      flg_pixy = 1;

    } else {

      flg_pixy = 0;

    }
  } else {

  }
  return flg_pixy;
}

int test_flgPixy(uint8_t flg_pixy, uint8_t NUM_BLOCKS, int* t_x, int* t_y, uint8_t *bit_ctr) {

  /**
   * Il puntatore bit_ctr serve, analogamente a quella dei sensori di linea, per salvare le varie
   * letture che esegue la pixy.
   *
   * Salveremo nei singoli bit della variabile "bit_ctr" i vari blocchi che ci interessano:
   *
   *  => La palla la salviamo nel bit 0;
   *
   *  => La porta davanti al robot la salviamo nel bit 1;
   *
   *  => La porta dietro la salviamo nel bit 2;
   *
   * Nel momento in cui dobbiamo controllare quali blocchi sono stati rilevati, facciamo
   * un semplice controllo sul valore della variabile, dato che, dall'algebra binaria,
   * quando vede solo la palla sarà uguale a 1, mentre se vede tutto quanto sarà uguale a 7;
   */

  if(flg_pixy) {

    for(int i=0; i<NUM_BLOCKS; i++) {

      if(pixy.ccc.blocks[i].m_signature == 0) {
        *t_x = pixy.ccc.blocks[i].m_x;
        *t_y = pixy.ccc.blocks[i].m_y;
        /**
         * Impostiamo il bit 0 della variabile bit_ctr ad 1;
         */
      } else {
        
      }
      if(pixy.ccc.blocks[i].m_signature == 1) {
        /**
         * Impostiamo il bit 1 della variabile bit_ctr ad 1;
         */
      } else {

      }
      if(pixy.ccc.blocks[i].m_signature == 2) {
        /**
         * Impostiamo il bit 2 della variabile bit_ctr ad 1;
         */
      } else {

      }
    }
  }
}

void pixyGo_flg(uint8_t flg_pixyCtr, int read_imu, int block_x, int block_y) {

  switch (flg_pixyCtr) {
    case 0:
      Serial.println("Palla");
      float pixyAngolo = atan2(block_y, block_x);
      PhoenixDrive_setSpeed(pixyAngolo, 200, read_imu);
    break;
    case 1:
      Serial.println("Porta Gialla");
    break;
    case 2:
      Serial.println("Porta Blu");
    break;
  }
}
