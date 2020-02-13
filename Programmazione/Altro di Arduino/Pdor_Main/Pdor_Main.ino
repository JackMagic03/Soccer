/**
 * Massimo Giordano
 *
 * Programma Robot Esploratore Curricolare
 */

#define inA_1 8
#define inA_2 12
#define inB_1 11
#define inB_2 13
#define pwm_1 9
#define pwm_2 10

/////////////////////////Motori

#define lightDx A1
#define lightSx A2
#define lightCn A3

#define sogliaCn 665
#define sogliaDx 650
#define sogliaSx 690
/////////////////////////Luce

#define bumpSx 2
#define bumpDx 3

byte StatoBump1;
byte StatoBump2;
/////////////////////////Bumper

#define Red 4
#define Green 5
#define Blue 6
/////////////////////////Led

void setup() {

  Serial.begin(9600);

  initMot();
  initBump();

}

void loop() {

  avanti();

  bumper();

}
