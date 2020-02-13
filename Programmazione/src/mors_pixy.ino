void pixy_readBlocks() {

  pixy.ccc.getBlocks();

  if(pixy.ccc.numBlocks) {

    Serial.println(pixy.ccc.numBlocks);
    Serial.println(" --- ");
    pixy.ccc.blocks[1].print();

  }

}
