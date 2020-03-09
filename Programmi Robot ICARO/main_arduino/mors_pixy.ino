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
  int read_imu = read_compass();

/**
 * Per la palla devo usare "uint16_t m_signature"
 *
 * Mi da il numero identificativo del blocco riconosciuto
 */

  if(NUM_BLOCKS) {

    for(int i=0; i<NUM_BLOCKS; i++) {

      int pixyAngolo = atan2(pixy.ccc.blocks[i].m_y, pixy.ccc.blocks[i].m_x);
      Serial.println(pixyAngolo);
      drive_Go(pixyAngolo, 200, read_imu);

    }
  }
}
