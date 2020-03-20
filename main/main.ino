#define PIN_DIR_A {4, 13, 7}
#define PIN_DIR_B {3, 12, 6}
#define PIN_PWM   {2, 11, 5}

#define SOGLIA_LINEE {800, 800, 800, 800, 800, 800}
#define PIN_LINEE {A0, A1, A2, A3, A4, A5}
#define ANGOLI_LINEE {30, 90, 150, 210, 270, 330}

MorsJoints joints_handler;
MorsLines line_handler;

void setup() {

  morsjoints_init(&joints_handler, PIN_DIR_A, PIN_DIR_A, PIN_PWM);

  morslines_init(&line_handler, PIN_LINEE, ANGOLI_LINEE, SOGLIA_LINEE);
}

void loop() {

  morslines_read(&line_handler);

  morslines_handle(&line_handler);

}
