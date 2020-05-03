/**
 * pixy.ino => Gestire le letture della telecamera per trovare gli oggetti
 * @author Massimo Giordano
 */

void morspixy_init(MorsPixy* p, Pixy2* t_pixy_ptr) {

  p-> get_blocks = 0;
  p-> num_blocks = 0;

  p-> flg = 0;
  p-> bit = 0;

  p-> pixy_ptr = t_pixy_ptr;
}

void morspixy_read(MorsPixy* p) {

  p-> get_blocks = p-> pixy_ptr-> ccc.getBlocks();
  p-> num_blocks = p-> pixy_ptr-> ccc.numBlocks;

  if(p-> get_blocks > 0) {

    if(p-> num_blocks) {

      p-> flg = 1;

    } else {

      p-> flg = 0;

    }
  }
}

void morspixy_test(MorsPixy* p) {

  if(p-> flg) {

    for(int i = 0; i < p-> num_blocks; i++) {

      if(p-> pixy_ptr-> ccc.blocks[i].m_signature == 0) {

        p-> heading_x = p-> pixy_ptr-> ccc.blocks[i].m_x;
        p-> heading_y = p-> pixy_ptr-> ccc.blocks[i].m_y;

        bitSet(p-> bit, 0);
      }
      if(p-> pixy_ptr-> ccc.blocks[i].m_signature == 1) {

        bitSet(p-> bit, 1);
      }
      if(p-> pixy_ptr-> ccc.blocks[i].m_signature == 2) {

        bitSet(p-> bit, 2);
      }
    }
  }
}

void morspixy_handle(MorsPixy* p) {

  morspixy_read(p);
  morspixy_test(p);
  /**
   * Fa robe
   */
}

/**
 * creare una funzione di reset
 */
