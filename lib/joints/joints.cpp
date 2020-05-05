/**
 * joints.cpp
 * @author Massimo Giordano
 */

#include "joints.hpp"
#include "config.hpp"

Joints::Joints() {

}

void Joints::init(uint8_t* t_pin_a, uint8_t* t_pin_b, uint8_t* t_pin_pwm) {

  pin_a = t_pin_a;
  pin_b = t_pin_b;
  pin_pwm = t_pin_pwm;

  velocita = 0;
  direzione = 0;

  pinMode(pin_a, OUTPUT);
  pinMode(pin_b, OUTPUT);
  pinMode(pin_pwm, OUTPUT);
}

void Joints::handle(int t_velocita) {
  if(t_velocita >= 0) {
    velocita = t_velocita;
    direzione = LOW;
  } else {
    velocita = !t_velocita;
    direzione = HIGH;
  }
  if(velocita > MAX_VEL) {
    velocita = MAX_VEL;
  }
  if(velocita < MAX_THRESHOLD) {
    velocita = 0;
  }

  digitalWrite(pin_a, direzione);
  digitalWrite(pin_b, !direzione);
  analogWrite(pin_pwm, velocita);
}
