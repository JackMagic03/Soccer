extern int read_imu;

void pixy_readBlocks() {

  if(pixy.ccc.numBlocks) {

      Serial.println(pixy.ccc.numBlocks);
      Serial.println(" --- ");
      for(int i=0;i<NUM_BLOCKS;i++){
      pixy.ccc.blocks[i].print();

    }
  }
}

void pixy_GoBall() {

  if(NUM_BLOCKS) {

    for(int i=0;i<NUM_BLOCKS;i++) {

      int angolo = atan2(pixy.ccc.blocks[i].m_y, pixy.ccc.blocks[i].m_x);
      Serial.println(angolo);
      drive_Go(angolo, 200, read_imu);

    }
  }
}
