/**
 * Libreria gestione camera
 *
 * Massimo Giordano, Diego de Martino
 */

/*void pixy_test() {

  GET_BLOCKS = pixy.ccc.getBlocks();
  NUM_BLOCKS = pixy.ccc.numBlocks;

  if(NUM_BLOCKS) {

    Serial.println(NUM_BLOCKS);
    Serial.println(" --- ");

    for(int i=0; i<NUM_BLOCKS; i++){
      pixy.ccc.blocks[i].print();
    }
  }
}*/

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

int test_flgPixy(uint8_t flg_pixy, uint8_t NUM_BLOCKS, int* t_x, int* t_y) {

  uint8_t flg_pixyCtr = 0;

  if(flg_pixy) {

    for(int i=0; i<NUM_BLOCKS; i++) {

      if(pixy.ccc.blocks[i].m_signature == 0) {
        *t_x = pixy.ccc.blocks[i].m_x;
        *t_y = pixy.ccc.blocks[i].m_y;
        flg_pixyCtr = 1;
      }
      else if(pixy.ccc.blocks[i].m_signature == 1) {
        flg_pixyCtr = 2;
      }
      else if(pixy.ccc.blocks[i].m_signature == 2) {
        flg_pixyCtr = 3;
      } else {

      }
    }
  }
  return flg_pixyCtr;
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
