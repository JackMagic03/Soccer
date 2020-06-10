/**
 * globals.hpp
 */
#pragma once
#include "mors_lineHandler.hpp"
#include "mors_drive.hpp"
#include "mors_imuHandler.hpp"
#include "mors_pixyHandler.hpp"
#include "mors_attackPlanner.hpp"
#include "mors_defensePlanner.hpp"

const uint8_t PIN_LINE[NUM_LINES] = {A0, A1, A2, A3, A4, A5}; //pin fisici dei sensori
const uint16_t ANGLE_LINE[NUM_LINES] = {30, 90, 150, 210, 270, 330}; //angoli a cui si trovano i sensori
const uint16_t TRESHOLD_LINE[NUM_LINES] = {800, 800, 800, 800, 800, 800}; //soglie dei singoli sensori. da tarare

const uint8_t PIN_DIR_A[NUM_JOINTS] = {4, 13, 7};
const uint8_t PIN_DIR_B[NUM_JOINTS] = {3, 12, 6};
const uint8_t PIN_PWM[NUM_JOINTS] = {2, 11, 5};

extern MorsLine line_vect[NUM_LINES]; //array di linee
extern MorsLineHandler line_handler; //gestore di linee

extern MorsJoint joint_vect[NUM_JOINTS]; //array di motori
extern MorsDrive drive_handler; //gestore dei motori

extern Adafruit_BNO055 bno; //oggetto fisico
extern MorsImu imu_dev; //oggeto della libreria più bassa
extern MorsPid pid_controller; //oggetto Pid
extern MorsImuHandler imu_handler; //gestore di bussola con anche il Pid

extern Pixy2 pixy; //oggetto pixy
extern MorsPixyHandler pixy_handler; //gestore di pixy

extern MorsPlanner* planner; //puntatore a planner
extern MorsAttackPlanner attack_planner; //oggetto attaccante
extern MorsDefensePlanner defense_planner; //oggetto difensore
