/**
 * joints.ino => Creare le funzioni per il drive che gestiscono i motori fisici
 * @author Massimo Giordano
 */

void morsjoints_init(MorsJoints* j, uint8_t* t_dir_a, uint8_t* t_dir_b, uint8_t* t_pwm) {

  for(int i = 0; i < NUM_JOINTS; i++) {
    j-> dir_a[i] = t_dir_a[i];
    j-> dir_b[i] = t_dir_b[i];
    j-> pwm[i]   = t_pwm[i];
    j-> velocita[i] = 0;
    j-> direzione[i] = HIGH;

    pinMode(j-> dir_a[i], OUTPUT);
    pinMode(j-> dir_b[i], OUTPUT);
    pinMode(j-> pwm[i], OUTPUT);
  }
}

void morsjoints_setspeed(MorsJoints* j, uint8_t t_joints, int t_vel) {
  /**
   * La variabile joints quando richiamiamo la funzione assume i valori 1, 2 o 3.
   * Quando la passiamo agli array, sottraiamo 1 dato che la numerazione degli array inizia da 0
   */

  if(t_vel >= 0) {

    if(j-> velocita[t_joints] > 255) {
      j-> velocita[t_joints] = 255;
    }
    j-> velocita[t_joints] = t_vel;
    j-> direzione[t_joints] = HIGH;

  } else {
    
    if(j-> velocita[t_joints] > 255) {
      j-> velocita[t_joints] = 255;
    }
    j-> velocita[t_joints] = !t_vel;
    j-> direzione[t_joints] = LOW;
  }
}

void morsjoints_handle(MorsJoints* j, uint8_t t_joints) {

  digitalWrite(j-> dir_a[t_joints], j-> direzione[t_joints]);
  digitalWrite(j-> dir_b[t_joints], !j-> direzione[t_joints]);
  analogWrite(j-> pwm[t_joints], j-> velocita[t_joints]);

}
