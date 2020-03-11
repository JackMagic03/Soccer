/**
 * Main
 *
 * Massimo Giordano, Diego de Martino
 */

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include <Pixy2.h>
#include <Math.h>

#define NUM_JOINTS 3
#define angoloMot_1 60.0
#define angoloMot_2 180.0
#define angoloMot_3 300.0
#define limiteDw_Up 70.0
#define limiteDw_Down -70.0
#define KW 3.0
uint8_t pinA[NUM_JOINTS]   = {4, 13, 7};   //giallo
uint8_t pinB[NUM_JOINTS]   = {3, 12, 6};   //rosso
uint8_t pinPwm[NUM_JOINTS] = {2, 11, 5};   //bianco

#define scl_imu 21
#define sda_imu 20
Adafruit_BNO055 bno = Adafruit_BNO055(55);

uint16_t pinLines[6] = { A0, A1, A2, A3, A4, A5 };  // i 6 pin analogici dei sensori

Pixy2 pixy;
/**
 * I Blocchi che la pixy legge sono:
   *  Palla(Blocco 0);
   *  Porta Gialla(Blocco 1);
   *  Porta Blu(Blocco 2);
 */

void setup() {

  Serial.begin(9600);

  PhoenixJoints_init();

  PhoenixImu_init();

  PhoenixDrive_init();

  pixy.init();

}

void loop() {

  static uint8_t old_flgLines = 0;
  static unsigned long time_lines = 0;

  uint8_t flg_lines = read_lines();
  if(old_flgLines != flg_lines && flg_lines == 1) {
    time_lines = millis();
  }

  uint8_t flg_pixy = read_pixy();

  int read_imu = imu_read();

  uint8_t flg_linesCtr = test_flgLines(flg_lines, time_lines);

  int block_x, block_y;
  uint8_t flg_pixyCtr = test_flgPixy(flg_pixy, &block_x, &block_y);

  linesGo_flg(flg_linesCtr);

  pixyGo_flg(flg_pixyCtr, read_imu, block_x, block_y);

  /*
  for(int i = 0; i<360; i++) {
    PhoenixDrive_setSpeed(i, 200, read_imu);
    delay(5);
  }
  */
  old_flgLines = flg_lines;
  flg_pixy = 0;
  flg_pixyCtr = 0;
  flg_linesCtr = 0;
}
