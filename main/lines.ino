/**
 * lines.ino => Gestione delle letture dei sensori di linea
 * @author Massimo Giordano
 */
#define DEFAULT_TIMER 3000

void morslines_init(MorsLines* l, uint8_t* t_pin, int* t_angle, int* t_soglia) {

  for(int i = 0; i < NUM_LINES; i++) {
    l-> pin[i] = t_pin[i];
    l-> angoli[i] = t_angle[i];
    l-> soglia[i] = t_soglia[i];
  }
  l-> tot_angle = LOW;
  l-> num_angle = LOW;
  l-> escape_angle = LOW;
  l-> flg = LOW;
}

void morslines_reset(MorsLines* l) {
  l-> timer = LOW;
  l-> flg = LOW;

  for(int i = 0; i < NUM_LINES; i++) {
    l-> mask[i] = 0;
  }
}

void morslines_read(MorsLines* l) {

  for(int i = 0; i < NUM_LINES; i++) {

    l-> raw_data[i] = analogRead(l-> pin[i]);

    if(l-> raw_data[i] >= l-> soglia[i]) {

      l-> data[i] = HIGH;

    } else {

      l-> data[i] = LOW;
    }
  }
}

void morslines_handle(MorsLines* l) {

  for(int i = 0; i < NUM_LINES; i++) {

    if(l-> mask[i] == LOW) {

      if(l-> data[i] == HIGH) {

        l-> mask[i] = HIGH;
        l-> tot_angle = l-> tot_angle + l-> angoli[i];
        l-> flg = HIGH;
        l-> timer = DEFAULT_TIMER;
        l-> num_angle ++;

        l-> escape_angle = ((l-> tot_angle / l-> num_angle)+ 180)% 360;
      }
    }
  }
  if(l-> flg == HIGH) {
    l-> timer --;

    if(l-> timer == 0) {
      morslines_reset(&line_handler);
    }
  }
}
