/**
 * Libreria gestione camera
 *
 * Massimo Giordano, Diego de Martino
 */

void pixy_readBlocks() {

  GET_BLOCKS;

  if(NUM_BLOCKS) {

    Serial.println(NUM_BLOCKS);
    Serial.println(" --- ");

    for(int i=0; i<TOT_BLOCKS; i++){
      pixy.ccc.blocks[i].print();
    }
  }
}

void pixy_goBall() {

  if(NUM_BLOCKS) {

    for(int i=0; i<TOT_BLOCKS; i++) {

      int pixyAngolo = atan2(pixy.ccc.blocks[i].m_y, pixy.ccc.blocks[i].m_x);
      Serial.println(pixyAngolo);
      drive_Go(pixyAngolo, 200, read_imu);

    }
  }
}
