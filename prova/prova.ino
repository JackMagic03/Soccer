#define SOGLIA_LINEE {800, 800, 800, 800, 800, 800}
#define PIN_LINEE {A0, A1, A2, A3, A4, A5}
#define ANGOLI_LINEE {30, 90, 150, 210, 270, 330}

<<<<<<< 5959a9e17b3489e5aef1395a13f21964189fb597:prova/prova.ino
=======
MorsDrive drive_handler;
MorsJoints joints_handler;
>>>>>>> Ciao:main/main.ino
MorsLines line_handler;

void setup() {

  morslines_init(&line_handler, PIN_LINEE, ANGOLI_LINEE, SOGLIA_LINEE);
}

void loop() {

  morslines_read(&line_handler);

  morslines_handle(&line_handler);

}
