/**
 * drive.hpp
 * @author Massimo Giordano
 */

#pragma once
#include "joints.hpp"
#include "config.hpp"

class Drive {
  /**
   * Sto di cendo che esistono 3 oggetti per i motori.
   * Vengono dichiarati nel drive.cpp
   */
  Joints joint_1;
  Joints joint_2;
  Joints joint_3;

  double matrix [NUM_JOINTS][NUM_JOINTS] =
  {
    {0.87, 0.50, 1}, //sin T1, cos T1, 1
    {0, -1, 1},     //sin T2, cos T2, 1
    {-0.87, 0.5, 1} //sin T3, cos T3, 1
  };
  float vel[NUM_JOINTS]; //Le velocità che andranno passate ai motori

  float v_x;       //Componente velocità del'asse X
  float v_y;       //Componente velocità dell'asse Y
  float d_w;       //Velocità angolare
  float r_w;       //Il terzo componente del calcolo della matrice. Usato per la correzione della direzione;
public:
  Drive();

  static float gradi(float t_rad);      //Funzione che restituisce i gradi
  static float radianti(float t_gradi); //Funzione che restituisce i radianti
  void setSpeed(float t_angle, int t_vel, float t_imu); //La setSpeed che calcola le velocita con le matrici
  void handle(); //La handle che dice ai singoli motori di muoversi
};
