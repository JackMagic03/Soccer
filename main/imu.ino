/**
 * imu.ino => Gestire la bussola e le correzioni che ne seguono
 * @author Massimo Giordano
 */

#define MAX_OUTPUT 255
#define MIN_OUTPUT -255

void morsimu_init(MorsImu* p, Adafruit_BNO055* t_imu_ptr, float t_k_p, float t_k_i, float t_k_d, float t_d_t, float t_id_t) {

  p-> imu_ptr = t_imu_ptr;
  p-> imu_ptr-> begin(p-> imu_ptr-> OPERATION_MODE_IMUPLUS);

  p-> heading = 0;
  p-> set_point = 0;
  p-> input = 0;
  p-> output = 0;
  p-> k_p = t_k_p;
  p-> k_i = t_k_i;
  p-> k_d = t_k_d;
  p-> error = 0;
  p-> prev_error = 0;
  p-> tot_error = 0;
  p-> d_t = t_d_t;
  p-> id_t = t_id_t;

}

void morsimu_read(MorsImu* p) {

  imu::Vector<3> euler = p-> imu_ptr-> getVector(Adafruit_BNO055::VECTOR_EULER);
  p-> heading = euler.x();
  /**
   * Questo passagio serve per portare la lettura della bussola
   * da 0 % 360 a -180 % +180
   */
  if(p-> heading > 180) {
    p-> heading -= 360;
  }
}

void morsimu_handle(MorsImu* p) {
  /**
   * Calcolo dell'errore
   */
  p-> error = p-> set_point - p-> heading;
  /**
   * Moltiplico la variabile errore per il tempo per non far aumentare troppo
   * la variabile accumulatore.
   */
  p-> tot_error += p-> error * p-> d_t * p-> k_i;
  ////////////

  /**
   * La parte derivariva del pid
   */
  float error_d = p-> k_d * ((p-> error - p-> prev_error) * p-> id_t);
  ////////////

  p-> output = p-> tot_error + error_d + (p-> k_p * p-> error);
                                         //Parte proporzionale

  if(p-> output > MAX_OUTPUT) {
    p-> output = MAX_OUTPUT;
  }
  if(p-> output < MIN_OUTPUT) {
    p-> output = MIN_OUTPUT;
  }
}

float morsimu_getOutput(MorsImu* p) {
  return p-> output;
}
