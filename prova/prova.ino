<<<<<<< 5959a9e17b3489e5aef1395a13f21964189fb597:prova/prova.ino
<<<<<<< 5959a9e17b3489e5aef1395a13f21964189fb597:prova/prova.ino
#define SOGLIA_LINEE {800, 800, 800, 800, 800, 800}
#define PIN_LINEE {A0, A1, A2, A3, A4, A5}
#define ANGOLI_LINEE {30, 90, 150, 210, 270, 330}
=======
=======
/**
 * main.ino
 * @author Massimo Giordano
 */

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

>>>>>>> Ciao:main/main.ino
#define NUM_JOINTS 3          //Sono i motori che abbiamo
typedef struct {
 uint8_t dir_a[NUM_JOINTS];
 uint8_t dir_b[NUM_JOINTS];
 uint8_t pwm[NUM_JOINTS];

<<<<<<< 5959a9e17b3489e5aef1395a13f21964189fb597:prova/prova.ino
 uint8_t direzione[NUM_JOINTS];
 uint8_t velocita[NUM_JOINTS];
=======
  uint8_t direzione[NUM_JOINTS];
  uint8_t vel[NUM_JOINTS];
>>>>>>> Ciao:main/main.ino
} MorsJoints;
MorsJoints joints_handler;
//typedef struct MorsJoints MorsJoints;

typedef struct {
  double matrix [NUM_JOINTS][NUM_JOINTS] =
  {
    {0.87, 0.50, 1}, //sin T1, cos T1, 1
    {0, -1, 1},     //sin T2, cos T2, 1
    {-0.87, 0.5, 1} //sin T3, cos T3, 1
  };
  float vel[NUM_JOINTS]; //Le velocità che andranno passate ai motori

  float v_x;       //Componente velocità del'asse X
  float v_y;       //Componente velocità dell'asse Y
  float d_w;       //Velocità angolare
  float r_w;       //Il terzo componente del calcolo della matrice. Usato per la correzione della direzione;
} MorsDrive;
MorsDrive drive_handler;

#define NUM_LINES 6           //Sono i sensori di linea che abbiamo.
typedef struct {
  uint8_t pin[NUM_LINES];
  int16_t angoli[NUM_LINES];
  int raw_data[NUM_LINES];
  uint8_t data[NUM_LINES];
  /**
   * Le due variabili raw_data e data sono gli array che salvano i valori che leggono i sensori;
   *
   * raw_data salva le letture grezze dei sensori, data ha solo valori 0 o 1, se sono state rilevare linee o meno
   */
  uint8_t mask[NUM_LINES];
  /**
   * L'array mask serve per l'ulteriore controllo quando si parla delle letture dei sensori,
   * perché le sue variabili vengono messe da 1 solo quando il sensore non ha mai letto prima
   */
  int soglia[NUM_LINES];

  uint8_t flg;
  int timer;
  int tot_angle;      //La somma degli angoli dei sensori che hanno rilevato qualcosa
  uint8_t num_angle;  //Il numero degli angoli che hanno trovato quancosa
  int escape_angle;   //La traiettoria calcolata dalla media dei vettori dagli angoli dei sensori
} MorsLines;
MorsLines line_handler;

const uint8_t PIN_DIR_A[NUM_JOINTS] = {4, 13, 7};
const uint8_t PIN_DIR_B[NUM_JOINTS] = {3, 12, 6};
const uint8_t PIN_PWM[NUM_JOINTS] = {2, 11, 5};
/**
 *  Ho levato i #define perché dava un problema di conversione da #define a uint8_t* e
 *  tutto il resto dei parametri
 */
// #define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
// #define sbi(sfr, bit) (_SFR_BYTE(sfr) != _BV(bit))
const int SOGLIA_LINEE[NUM_LINES] = {800, 800, 800, 800, 800, 800};
const uint8_t PIN_LINEE[NUM_LINES] = {A0, A1, A2, A3, A4, A5};
const int ANGOLI_LINEE[NUM_LINES] = {30, 90, 150, 210, 270, 330};
>>>>>>> Correzione di tutti gli errori:main/main.ino

<<<<<<< 5959a9e17b3489e5aef1395a13f21964189fb597:prova/prova.ino
=======
MorsDrive drive_handler;
MorsJoints joints_handler;
>>>>>>> Ciao:main/main.ino
MorsLines line_handler;

void setup() {

  morslines_init(&line_handler, PIN_LINEE, ANGOLI_LINEE, SOGLIA_LINEE);

  morsimu_init();
}

void loop() {

<<<<<<< 5959a9e17b3489e5aef1395a13f21964189fb597:prova/prova.ino
<<<<<<< 5959a9e17b3489e5aef1395a13f21964189fb597:prova/prova.ino
  morslines_read(&line_handler);

<<<<<<< 5959a9e17b3489e5aef1395a13f21964189fb597:prova/prova.ino
<<<<<<< 5959a9e17b3489e5aef1395a13f21964189fb597:prova/prova.ino
  morslines_handle(&line_handler);
=======
  // morsdrive_setspeed(&drive_handler, 0, 200, read_imu);
  // morsdrive_handle(&drive_handler);

  for(int i = 0; i < 3; i++) {
    morsjoints_setspeed(&joints_handler, i, 200);
  }
  morsjoints_handle(&joints_handler, 0);
<<<<<<< 5959a9e17b3489e5aef1395a13f21964189fb597:prova/prova.ino
>>>>>>> Ciao:main/main.ino

=======
>>>>>>> ciao:main/main.ino
=======
  morsdrive_setspeed(&drive_handler, 0, 200, read_imu);
  morsdrive_handle(&drive_handler);

  // for(int i = 0; i < 3; i++) {
  //   morsjoints_setspeed(&joints_handler, i, 200);
  // }
  // morsjoints_handle(&joints_handler, 0);
>>>>>>> Ciao:main/main.ino
=======
  // int read_imu = morsimu_read();
  //
  // morsdrive_setspeed(&drive_handler, 0, 200, read_imu);
  // morsdrive_handle(&drive_handler);

  morsjoints_setspeed(&joints_handler, 0, 200);
  morsjoints_handle(&joints_handler, 0);
  morsjoints_setspeed(&joints_handler, 0, 0);

  morsjoints_setspeed(&joints_handler, 1, 200);
  morsjoints_handle(&joints_handler, 0);
  morsjoints_setspeed(&joints_handler, 1, 0);

  morsjoints_setspeed(&joints_handler, 2, 200);
  morsjoints_handle(&joints_handler, 0);
  morsjoints_setspeed(&joints_handler, 2, 0);
>>>>>>> ciao:main/main.ino
=======
  int read_imu = morsimu_read();
  Serial.println(read_imu);
  //
  // morsdrive_handle(&drive_handler, 0, 200, read_imu);

>>>>>>> Ciao:main/main.ino
}
