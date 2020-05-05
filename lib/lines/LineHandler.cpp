/**
 * LineHandler.hpp
 * #author Massimo Giordano
 */

#include "lineHandler.hpp"

LineHandler::LineHandler() {

  for(int i = 0; i < NUM_LINES; ++i) {
    detector_vect[i].init(PIN_LINEE[i], ANGOLI_LINEE[i], SOGLIA_LINEE[i]);
    mask[i] = LOW;
  }
  timer = 0;
  flg = LOW;

}

void LineHandler::reset() {
  for(int i = 0; i < NUM_LINES; ++i) {
    mask[i] = LOW;
  }
  timer = 0;
  flg = LOW;
}

void LineHandler::handle() {

  for(int i = 0; i < NUM_LINES; i++) {
    detector_vect[i].read();
  }

  for(int i = 0; i < NUM_LINES; ++i) {

    if(mask[i] == LOW) {

      if(detector_vect[i].data == HIGH) {

        mask[i] = HIGH;
        tot_angle = tot_angle + detector_vect[i].angle;
        flg = HIGH;
        timer = DEFAULT_TIMER;
        num_angle ++;

        escape_angle = ((tot_angle / num_angle)+ 180)% 360;
      }
    }
  }
  if(flg == HIGH) {
    timer --;
  }
  if(timer == 0) {
    LineHandler::reset();
  }
}
