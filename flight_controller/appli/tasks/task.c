/*
 * task.c
 *
 *  Created on: 13 ao�t 2020
 *      Author: Th�o
 */
#include "task.h"
#include "scheduler/scheduler.h"



static State_drone_t * drone ;
static State_base_t * base ;

void tasks_init(State_drone_t * drone_, State_base_t * base_){
	//Structures qui servent pour les diff�rentes t�ches
	drone = drone_ ;
	base = base_ ;

	//Activation des t�ches p�riodiques
	task_enable(TASK_IMU, TRUE);
	task_enable(TASK_PRINTF, TRUE);
}

void task_function_imu(uint32_t current_time_us){
	UNUSED(current_time_us);
	Mpu_imu_update_angles(&drone->capteurs.mpu);
}

void task_function_printf(uint32_t current_time_us){
	// Print du temps pour tester la pr�cision du scheduler
	// r�sultats :
	// https://docs.google.com/spreadsheets/d/1ht3PXd8hl_F3A8eyyvMGMx47aYmt8lzz4U1-OB26JfE/edit#gid=0
	// => revoir le current time peut �tre ?
	printf("y\t%f\ttime\t%lu\n", drone->capteurs.mpu.y, current_time_us);
}

#define DEFINE_TASK(id_param, priority_param,  task_function_param, desired_period_us_param) { 	\
	.id = id_param,										\
	.static_priority = priority_param,					\
	.function = task_function_param,					\
	.desired_period_us = desired_period_us_param		\
}

#define PERIOD_US_FROM_HERTZ(hertz_param) (1000000 / hertz_param)



task_t tasks [TASK_COUNT] ={
		[TASK_IMU] = DEFINE_TASK(TASK_IMU ,PRIORITY_HIGH, task_function_imu, PERIOD_US_FROM_HERTZ(250)),
		[TASK_PRINTF] = DEFINE_TASK(TASK_PRINTF, PRIORITY_LOW, task_function_printf, PERIOD_US_FROM_HERTZ(60))
};

task_t * get_task(task_ids_t id){
	return &tasks[id];
}

//tasks[TASK_IMU] = DEFINE_TASK(TASK_IMU, PRIORITY_REAL_TIME, tast_function_imu, 4000) ;

