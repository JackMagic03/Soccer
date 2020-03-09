/**
 * Libreria gestione camera
 *
 * Massimo Giordano, Diego de Martino
 */

void pixy_test() {

  uint8_t GET_BLOCKS = pixy.ccc.getBlocks();
  uint8_t NUM_BLOCKS = pixy.ccc.numBlocks;

  if(NUM_BLOCKS) {

    Serial.println(NUM_BLOCKS);
    Serial.println(" --- ");

    for(int i=0; i<NUM_BLOCKS; i++){
      pixy.ccc.blocks[i].print();
    }
  }
}

void pixy_goBall() {

  uint8_t GET_BLOCKS = pixy.ccc.getBlocks();
  uint8_t NUM_BLOCKS = pixy.ccc.numBlocks;
  int read_imu = PhoenixImu_read();

/**
 * Per la palla devo usare "uint16_t m_signature"
 * Mi da il numero identificativo del blocco riconosciuto
 */

  if(NUM_BLOCKS) {

    for(int i=0; i<NUM_BLOCKS; i++) {

      switch (pixy.ccc.blocks[i].m_signature) {
        case 0:
          Serial.println("Palla");
          float pixyAngolo = atan2(pixy.ccc.blocks[i].m_y, pixy.ccc.blocks[i].m_x);
          PhoenixDrive_setSpeed(pixyAngolo, 200, read_imu);
          break;
        case 1:
          Serial.println("Porta Gialla");
          break;
        case 2:
          Serial.println("Porta Blu");
          break;
      }
      // if      (pixy.ccc.blocks[i].m_signature == 0) Serial.println("Hai trovato la Palla");
      // else if (pixy.ccc.blocks[i].m_signature == 1) Serial.println("Hai trovato la Porta Gialla");
      // else if (pixy.ccc.blocks[i].m_signature == 2) Serial.println("Hai trovato la Porta Blu");
    }
  }
}
