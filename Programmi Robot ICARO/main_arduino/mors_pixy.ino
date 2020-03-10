/**
 * Libreria gestione camera
 *
 * Massimo Giordano, Diego de Martino
 */

uint8_t GET_BLOCKS;
uint8_t NUM_BLOCKS;
uint8_t TOT_BLOCKS = 3;

void pixy_test() {

  GET_BLOCKS = pixy.ccc.getBlocks();
  NUM_BLOCKS = pixy.ccc.numBlocks;

  if(NUM_BLOCKS) {

    Serial.println(NUM_BLOCKS);
    Serial.println(" --- ");

    for(int i=0; i<NUM_BLOCKS; i++){
      pixy.ccc.blocks[i].print();
    }
  }
}

int read_pixy() {

  uint8_t flg_pixy = 0;

  GET_BLOCKS = pixy.ccc.getBlocks();
  NUM_BLOCKS = pixy.ccc.numBlocks;

  if(NUM_BLOCKS) {

    flg_pixy = 1;
    return flg_pixy;

  } else {

    flg_pixy = 0;
    return flg_pixy;

  }
}

void test_flgPixy(uint8_t flg_pixy, int read_imu) {

  //uint8_t flg_pixyCtr = 0;

  if(flg_pixy) {

    for(int i=0; i<TOT_BLOCKS; i++) {

      switch (pixy.ccc.blocks[i].m_signature) {
        case 0: //Palla

          Serial.println("Palla");
          float pixyAngolo = atan2(pixy.ccc.blocks[i].m_y, pixy.ccc.blocks[i].m_x);
          PhoenixDrive_setSpeed(pixyAngolo, 200, read_imu);
          // flg_pixyCtr = 1;
          // return flg_pixyCtr;
          break;
        case 1: //Porta Gialla

          Serial.println("Porta Gialla");
          // flg_pixyCtr = 2;
          // return flg_pixyCtr;
          break;
        case 2: //Porta Blu

          Serial.println("Porta Blu");
          // flg_pixyCtr = 3;
          // return flg_pixyCtr;
          break;
      }
    }
  } else {

  }
}

// void pixyGo_flg(uint8_t flg_pixyCtr, int read_imu) {
//
//   switch (flg_pixyCtr) {
//     case 1:
//       Serial.println("Palla");
//       float pixyAngolo = atan2(pixy.ccc.blocks[i].m_y, pixy.ccc.blocks[i].m_x);
//       PhoenixDrive_setSpeed(pixyAngolo, 200, read_imu);
//     break;
//     case 2:
//       Serial.println("Porta Gialla");
//     break;
//     case 3:
//       Serial.println("Porta Blu");
//     break;
//   }
// }
