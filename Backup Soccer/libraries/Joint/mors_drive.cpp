/**
 * mors_drive.cpp
 */
#include "mors_drive.hpp"

static double matrix[NUM_JOINTS][NUM_JOINTS] =
{
	{0.87, 0.50, 1}, //sin T1, cos T1, 1
	{0,    -1,   1}, //sin T2, cos T2, 1
	{-0.87, 0.5, 1}  //sin T3, cos T3, 1
};

MorsDrive::MorsDrive()
{
	for(int i = 0; i < NUM_JOINTS; i++)
	{
		this-> speed[i] = 0;
	}
	this-> v_x = 0;
	this-> v_y = 0;
}

float MorsDrive::gradi(float t_rad)
{
  /**
   * Ritorna i gradi dei radianti passati come parametro
   */
  return (t_rad * 180.0 / PI);
}

float MorsDrive::radianti(float t_gradi)
{
  /**
   * Ritorna i radianti di un angolo passato come parametro
   */
  return (t_gradi * PI / 180.0);
}

void MorsDrive::handle(float t_angle, int t_speed, float t_imu)
{
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
	this-> v_x = t_speed * sin(//MorsDrive::radianti(t_angle - OFFSET_ANGLE));
                    t_angle);
	this-> v_y = t_speed * cos(//MorsDrive::radianti(t_angle - OFFSET_ANGLE));
                    t_angle);

	/**
	 * Il vero e proprio calcolo delle velocità.
	 * Si moltiplicano i termini delle matrici con v_x, v_y e t_imu.
	 */
	for(int i = 0; i < NUM_JOINTS; i++)
	{
		speed[i] = 	matrix [i][0] * (v_x) +
					matrix [i][1] * (v_y) +
					matrix [i][2] * (t_imu);

		joint[i].setSpeed(speed[i]); //passo la velocita alla classe dei motori
	}
	for(int i = 0; i < NUM_JOINTS; i++)
	{
		joint[i].handle(); //muovo i giunti
	}
}
