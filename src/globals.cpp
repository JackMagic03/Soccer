/**
 * globals.cpp
 */
#include "globals.hpp"

MorsLine line_vect[NUM_LINES] =
{
	{
		pin: PIN_LINE[0],
		angle: ANGLE_LINE[0],
		treshold: TRESHOLD_LINE[0]
	},
	{
		pin: PIN_LINE[1],
		angle: ANGLE_LINE[1],
		treshold: TRESHOLD_LINE[1]
	},
	{
		pin: PIN_LINE[2],
		angle: ANGLE_LINE[2],
		treshold: TRESHOLD_LINE[2]
	},
	{
		pin: PIN_LINE[3],
		angle: ANGLE_LINE[3],
		treshold: TRESHOLD_LINE[3]
	},
	{
		pin: PIN_LINE[4],
		angle: ANGLE_LINE[4],
		treshold: TRESHOLD_LINE[4]
	},
	{
		pin: PIN_LINE[5],
		angle: ANGLE_LINE[5],
		treshold: TRESHOLD_LINE[5]
	}
};
MorsLineHandler line_handler;

MorsJoint joint_vect[NUM_JOINTS] =
{
	{
		pin_a: PIN_DIR_A[0],
		pin_b: PIN_DIR_B[0],
		pin_pwm: PIN_PWM[0]
	},
	{
		pin_a: PIN_DIR_A[1],
		pin_b: PIN_DIR_B[1],
		pin_pwm: PIN_PWM[1]
	},
	{
		pin_a: PIN_DIR_A[2],
		pin_b: PIN_DIR_B[2],
		pin_pwm: PIN_PWM[2]
	}
};
MorsDrive drive_handler;

Adafruit_BNO055 bno(55);
MorsImu imu_dev(&bno);
MorsPid pid_controller;
MorsImuHandler imu_handler;

Pixy2 pixy;
MorsPixyHandler pixy_handler(&pixy);

MorsPlanner* planner; //puntatore a planner
MorsAttackPlanner attack_planner; //oggetto attaccante
MorsDefensePlanner defense_planner; //oggetto difensore
