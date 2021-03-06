/*
 * telemetrie_periodic_send_functions.h
 *
 *  Created on: 6 oct. 2020
 *      Author: Theo
 */

#ifndef TELEMETRIE_TELEMETRIE_PERIODIC_SEND_FUNCTIONS_H_
#define TELEMETRIE_TELEMETRIE_PERIODIC_SEND_FUNCTIONS_H_

#include "stdio.h"
#include "scheduler/scheduler.h"
#include "telemetrie.h"


#define TASK_TO_SEND TASK_IMU


//Fonction appeler periodiquement
void TELEMETRIE_Periodic_send(State_drone_t * drone);



// ---------------------- Fonctions pour la sub télémétrie ------------------------
//Période task
void TELEMETRIE_send_periode_task(State_drone_t * drone);

//Cpu used
void TELEMETRIE_send_cpu_pourcentage(State_drone_t * drone);

//Altitude
void TELEMETRIE_send_altitude(State_drone_t * drone);

//Pids
void TELEMETRIE_send_pid_roll(State_drone_t * drone);
void TELEMETRIE_send_pid_pitch(State_drone_t * drone);
void TELEMETRIE_send_pid_yaw(State_drone_t * drone);
void TELEMETRIE_send_pid_roll_p(State_drone_t * drone);
void TELEMETRIE_send_pid_roll_d(State_drone_t * drone);

//Pids coefs
void TELEMETRIE_send_pid_roll_kp(State_drone_t * drone);
void TELEMETRIE_send_pid_roll_ki(State_drone_t * drone);
void TELEMETRIE_send_pid_roll_kd(State_drone_t * drone);
void TELEMETRIE_send_pid_pitch_kp(State_drone_t * drone);
void TELEMETRIE_send_pid_pitch_ki(State_drone_t * drone);
void TELEMETRIE_send_pid_pitch_kd(State_drone_t * drone);
///////////////////

//Envoi moteurs
void TELEMETRIE_send_moteur_all(State_drone_t * drone);

//Envoi channels
void TELEMETRIE_send_channel_all_1_4(State_drone_t * drone);
void TELEMETRIE_send_channel_all_5_8(State_drone_t * drone);

//Envoi angle
void TELEMETRIE_send_angle_x_y_as_int(State_drone_t * drone);
void TELEMETRIE_send_angle_x_y_z_rate_as_int(State_drone_t * drone);
void TELEMETRIE_send_angle_z_as_int(State_drone_t * drone);

//Envoi angle de l acc
void TELEMETRIE_send_angle_x_y_acc_as_int(State_drone_t * drone);

//Envoi acc
void TELEMETRIE_send_acc_z(State_drone_t * drone);


//Envoi state flying
void TELEMETRIE_send_state_flying(State_drone_t * drone);


//Envoi v_bat
void TELEMETRIE_send_v_bat(State_drone_t * drone);


//ENVOI gps
void TELEMETRIE_send_lat(State_drone_t * drone);
void TELEMETRIE_send_long(State_drone_t * drone);

//Envoi every_is_ok
void TELEMETRIE_send_every_is_ok(State_drone_t * drone);

#endif /* TELEMETRIE_TELEMETRIE_PERIODIC_SEND_FUNCTIONS_H_ */
