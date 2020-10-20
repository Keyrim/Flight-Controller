/*
 * regulation_filtrage.c
 *
 *  Created on: 20 oct. 2020
 *      Author: Theo
 */
#include "regulation_filtrage.h"

//Param�tres
//Appr�s analyse des courbes des sorties de pid sur un google sheet
//Un filtre du second ordre avec ces param�tres fonctionne bien
#define alpha 	0.15173867f
#define beta	1.50684931f
#define gamma  -0.65858798f

//Param�tres pid "levelled/angle"
#define PID_ANGLE_FREQUENCY REGULATION_AND_MPU_FREQUENCY
float PID_SETTINGS_ROLL [PID_NB_SETTINGS] =  {4.0f, 0.0f, 0.0f, PID_ANGLE_FREQUENCY, SETPOINT_MAX_ACCRO_PITCH_ROLL};
float  PID_SETTINGS_PITCH [PID_NB_SETTINGS] = {6.0f, 0.0f, 0.0f, PID_ANGLE_FREQUENCY, SETPOINT_MAX_ACCRO_PITCH_ROLL};

//float PID_SETTINGS_ROLL [PID_NB_SETTINGS] =  {1.5f, 0.0f, 0.29f, PID_ANGLE_FREQUENCY, SETPOINT_MAX_ACCRO_PITCH_ROLL};
//float  PID_SETTINGS_PITCH [PID_NB_SETTINGS] = {2.47f, 0.0f, 0.4f, PID_ANGLE_FREQUENCY, SETPOINT_MAX_ACCRO_PITCH_ROLL};

float  PID_SETTINGS_YAW [PID_NB_SETTINGS] = {6.0f, 0.0f, 2.0f, PID_ANGLE_FREQUENCY, SETPOINT_MAX_ACCRO_YAW} ;

//Param�tres pid "accro/angle rate"
#define PID_ANGLE_RATE_FREQUENCY	REGULATION_AND_MPU_FREQUENCY
float PID_SETTINGS_ROLL_ACCRO[PID_NB_SETTINGS] = {0.6f, 0.0f, 0.00f, PID_ANGLE_RATE_FREQUENCY, 250};
float PID_SETTINGS_PITCH_ACCRO[PID_NB_SETTINGS] = {0.5f, 0.0f, 0.00f, PID_ANGLE_RATE_FREQUENCY, 250};
float PID_SETTINGS_YAW_ACCRO[PID_NB_SETTINGS] = {0.0f, 1.0f, 0.0f, PID_ANGLE_RATE_FREQUENCY, 250};

//Settings filters pid angle$
// https://docs.google.com/spreadsheets/d/17qEF8PeXgOc0zejo5EkO0WPrfYT0EIATipH0eUmFORY/edit#gid=0
float FILTER_SETTINGS_ANGLE[3] = {alpha, beta, gamma};

float FILTER_first_order_settings[3] = {0.1f, 0.9f, 0.0f};

//Settings fitlers gyro
// https://docs.google.com/spreadsheets/d/10sJPc1aYeCNcukzN5P1F0smk6_KCdXfGAj5ekmFCErw/edit#gid=0
float FILTER_SETTINGS_GYRO[3] = {0.1142857143f, 1.6f, -0.7142857143f}; 				//(dt 0.004 w0 100 ksi 0.3 )	//plus lisse donc un peu de latence
//float FILTER_SETTINGS_GYRO[3] = {0.1836734694f, 1.326530612f, -0.5102040816f}; 	//(dt 0.004 w0 150 ksi 0.5 )	//moins lisse, moins de latence


void REGU_FILTRAGE_pids_orientation_init(State_drone_t * drone){

	//Init pids pour le mode "angle / levelled "
	PID_init(&drone->stabilisation.pid_roll, PID_SETTINGS_ROLL, FILTER_NO_FILTERING, NULL);
	PID_init(&drone->stabilisation.pid_pitch,  PID_SETTINGS_PITCH, FILTER_NO_FILTERING, NULL);
	PID_init(&drone->stabilisation.pid_yaw, PID_SETTINGS_YAW, FILTER_NO_FILTERING, NULL);

	//Init pids pour le mode "accro / rate"
	PID_init(&drone->stabilisation.pid_roll_rate, PID_SETTINGS_ROLL_ACCRO, FILTER_FIRST_ORDER, FILTER_first_order_settings);
	PID_init(&drone->stabilisation.pid_pitch_rate, PID_SETTINGS_PITCH_ACCRO, FILTER_FIRST_ORDER, FILTER_first_order_settings);
	PID_init(&drone->stabilisation.pid_yaw_rate, PID_SETTINGS_YAW_ACCRO, FILTER_FIRST_ORDER, FILTER_first_order_settings);
}
void REGU_FILTRAGE_filters_imu_config(State_drone_t * drone){
	DRONE_mpu6050_t * imu = &drone->capteurs.mpu ;
	//Filtre de l'acc
	FILTER_init(&imu->x_acc_filter, FILTER_first_order_settings, FILTER_FIRST_ORDER);
	FILTER_init(&imu->y_acc_filter, FILTER_first_order_settings, FILTER_FIRST_ORDER);
	FILTER_init(&imu->z_acc_filter, FILTER_first_order_settings, FILTER_FIRST_ORDER);
	//Filtre du gyro
	FILTER_init(&imu->x_gyro_filter, FILTER_first_order_settings, FILTER_FIRST_ORDER);
	FILTER_init(&imu->y_gyro_filter, FILTER_first_order_settings, FILTER_FIRST_ORDER);
	FILTER_init(&imu->z_gyro_filter, FILTER_first_order_settings, FILTER_FIRST_ORDER);

}

