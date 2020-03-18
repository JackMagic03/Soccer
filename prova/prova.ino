#define SOGLIA_LINEE 850
#define PIN_LINEE {A0, A1, A2, A3, A4, A5}

MorsLinee line_handler;

void setup() {

  morslinee_init(&line_handler, PIN_LINEE, SOGLIA_LINEE);
}

void loop() {

}
