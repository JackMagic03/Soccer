/**
 * imu.ino => Gestire la bussola e le correzioni che ne seguono
 * @author Massimo Giordano
 */

#define MAX_OUTPUT 255
#define MIN_OUTPUT -255

void morsimu_init(MorsImu* c, Adafruit_BNO055* t_imu_ptr, float t_k_p, float t_k_i, float t_k_d, float t_d_t, float t_id_t) {

  c-> imu_ptr = t_imu_ptr;
  c-> imu_ptr-> begin(c-> imu_ptr-> OPERATION_MODE_IMUPLUS);

  c-> heading = 0;
  c-> set_point = 0;
  c-> input = 0;
  c-> output = 0;
  c-> k_p = t_k_p;
  c-> k_i = t_k_i;
  c-> k_d = t_k_d;
  c-> error = 0;
  c-> prev_error = 0;
  c-> tot_error = 0;
  c-> d_t = t_d_t;
  c-> id_t = t_id_t;

}

void morsimu_read(MorsImu* c) {

  imu::Vector<3> euler = c-> imu_ptr-> getVector(Adafruit_BNO055::VECTOR_EULER);
  c-> heading = euler.x();
  /**
   * Questo passagio serve per portare la lettura della bussola
   * da 0 % 360 a -180 % +180
   */
  if(c-> heading > 180) {
    c-> heading -= 360;
  }
}

void morsimu_handle(MorsImu* c) {

  morsimu_read(c);
  /**
   * Calcolo dell'errore
   */
  c-> error = c-> set_point - c-> heading;
  /**
   * Moltiplico la variabile errore per il tempo per non far aumentare troppo
   * la variabile accumulatore.
   */
  c-> tot_error += c-> error * c-> d_t * c-> k_i;
  ////////////

  /**
   * La parte derivariva del pid
   */
  float error_d = c-> k_d * ((c-> error - c-> prev_error) * c-> id_t);
  ////////////

  c-> output = c-> tot_error + error_d + (c-> k_p * c-> error);
                                         //Parte proporzionale

  if(c-> output > MAX_OUTPUT) {
    c-> output = MAX_OUTPUT;
  }
  if(c-> output < MIN_OUTPUT) {
    c-> output = MIN_OUTPUT;
  }
}

float morsimu_getOutput(MorsImu* c) {
  return c-> output;
}
