/**
 * drive.cpp
 * @author Massimo Giordano
 */

#include "drive.hpp"

Drive::Drive(): joint_1(PIN_DIR_A[0], PIN_DIR_B[0], PIN_PWM[0]),
                joint_2(PIN_DIR_A[1], PIN_DIR_B[1], PIN_PWM[1]),
                joint_3(PIN_DIR_A[2], PIN_DIR_B[2], PIN_PWM[2]) {
  /**
   * Inizializziamo le variabili del drive
   */
  v_x = 0;
  v_y = 0;
  d_w = 0;
  r_w = 0;

  for(int i = 0; i < NUM_JOINTS; i++) {
    vel[i] = 0;
  }
}

float Drive::gradi(float t_rad) {
  /**
   * Ritorna i gradi dei radianti passati come parametro
   */
  return (t_rad * 180.0 / PI);
}

float Drive::radianti(float t_gradi) {
  /**
   * Ritorna i radianti di un angolo passato come parametro
   */
  return (t_gradi * PI / 180.0);
}

void Drive::handle(float t_angle, int t_vel, float t_imu) {
  /**
   * Impostare la velocità per ogni singolo motore
   * dati angolo e velocità finale a cui il robot
   * dovrà andare e lettura della bussola.
   */
  /**
   * Ragioniamo senza la conversione da gradi in radianti
   * perché tutti i componenti elettronici del robot ragionano in radianti,
   * tranne la bussola ma in questo caso non importa.
   */
   v_x = t_vel * sin(//Drive::radianti(t_angle - OFFSET_ANGLE));
                     t_angle);
   v_y = t_vel * cos(//Drive::radianti(t_angle - OFFSET_ANGLE));
                     t_angle);

   /**
    * Il vero e proprio calcolo delle velocità.
    * Si moltiplicano i termini delle matrici con v_x, v_y e d_w.
    */
    vel[0] = matrix [0][0] * (v_x) +
             matrix [0][1] * (v_y) +
             matrix [0][2] * (t_imu);

    vel[1] = matrix [1][0] * (v_x) +
             matrix [1][1] * (v_y) +
             matrix [1][2] * (t_imu);

    vel[2] = matrix [2][0] * (v_x) +
             matrix [2][1] * (v_y) +
             matrix [2][2] * (t_imu);

    joint_1.setSpeed(vel[0]);
    joint_2.setSpeed(vel[1]);
    joint_3.setSpeed(vel[2]);

    joint_1.handle();
    joint_2.handle();
    joint_3.handle();
}
