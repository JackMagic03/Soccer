#define NUM_LINES 6

typedef struct{

  int pin[NUM_LINES];
  int raw_data[NUM_LINES];
  uint8_t data[NUM_LINES];

  int soglia;

} MorsLinee;

void morslinee_init(MorsLinee* l, int t_pin[], int t_soglia) {

  for(int i = 0; i < NUM_LINES; i++) {
    l -> pin[i] = t_pin[i];
  }
  l-> soglia = t_soglia;
}

void morslinee_read(MorsLinee* l) {

  for(int i = 0; i < NUM_LINES; i++) {

    l-> raw_data[i] = analogRead(l-> pin[i]);

    if(l-> raw_data[i] >= l-> soglia) {

      l-> data[i] = HIGH;

    } else {

      l-> data[i] = LOW;

    }
  }
}
