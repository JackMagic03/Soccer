#define NUM_JOINTS 3

typedef struct {

  uint8_t dir_a[NUM_JOINTS];
  uint8_t dir_b[NUM_JOINTS];
  uint8_t pwm[NUM_JOINTS];

  uint8_t direzione;
  uint8_t velocita;

} MorsJoints;

void morsjoints_init(MorsJoints* j, uint8_t dir_a[], uint8_t dir_b[], uint8_t pwm[]) {
  for(int i = 0; i < NUM_JOINTS; i++) {
    j-> dir_a[i] = dir_a[i];
    j-> dir_b[i] = dir_b[i];
    j-> pwm[i]   = pwm[i];

    pinMode(j-> dir_a[i], OUTPUT);
    pinMode(j-> dir_b[i], OUTPUT);
    pinMode(j-> pwm[i], OUTPUT);
  }
  j-> direzione = 0;
  j-> velocita = 0;
}

void morsjoints_reset(MorsJoints* j) {

}

void morsjoints_setspeed(MorsJoints* j, uint8_t joints, int vel_joints) {
  /**
   * La variabile joints quando richiamiamo la funzione assume i valori 1, 2 o 3.
   * Quando la passiamo agli array, sottraiamo 1 dato che la numerazione degli array inizia da 0
   */

  if(vel_joints >= 0) {
    j-> velocita = vel_joints;
    j-> direzione = HIGH;
  } else {
    j-> velocita = !vel_joints;
    j-> direzione = LOW;
  }
  if(j-> velocita > 255) {
    j-> velocita = 255;
  }

  digitalWrite(j-> dir_a[joints], j-> direzione);
  digitalWrite(j-> dir_b[joints], j-> !direzione);
  analogWrite(j-> pwm[joints], j-> velocita);
}
