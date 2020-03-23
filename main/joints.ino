/**
 * joints.ino => Creare le funzioni per il drive che gestiscono i motori fisici
 * @author Massimo Giordano
 */

void morsjoints_init(MorsJoints* j, uint8_t* t_dir_a, uint8_t* t_dir_b, uint8_t* t_pwm) {

  for(int i = 0; i < NUM_JOINTS; i++) {
    j-> dir_a[i] = t_dir_a[i];
    j-> dir_b[i] = t_dir_b[i];
    j-> pwm[i]   = t_pwm[i];

    pinMode(j-> dir_a[i], OUTPUT);
    pinMode(j-> dir_b[i], OUTPUT);
    pinMode(j-> pwm[i], OUTPUT);
  }
}

void morsjoints_handle(MorsJoints* j, uint8_t t_joints, int t_vel) {
  /**
   * La variabile joints quando richiamiamo la funzione assume i valori 1, 2 o 3.
   * Quando la passiamo agli array, sottraiamo 1 dato che la numerazione degli array inizia da 0
   */

  if(t_vel >= 0) {

    if(t_vel > 255) {
      t_vel = 255;
    }
    digitalWrite(j-> dir_a[t_joints], LOW);
    digitalWrite(j-> dir_b[t_joints], HIGH);
    analogWrite(j-> pwm[t_joints], t_vel);

  } else {

    if(t_vel < -255) {
      t_vel = 255;
    }

    digitalWrite(j-> dir_a[t_joints], HIGH);
    digitalWrite(j-> dir_b[t_joints], LOW);
    analogWrite(j-> pwm[t_joints], t_vel);
  }
}
