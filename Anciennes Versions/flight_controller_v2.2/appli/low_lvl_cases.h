/*
 * low_level_cases.h
 *
 *  Created on: 29 juin 2020
 *      Author: Th�o
 */

#ifndef LOW_LVL_CASES_H_
#define LOW_LVL_CASES_H_

#include "MAE.h"
#include "system_d.h"
#include "systick.h"
#include "../../lib_perso/sequence_led.h"
#include "../../ressources/sequences_led.h"
#include "../../lib_perso/telemetrie.h"
#include "../../lib_perso/complementary_filter.h"
#include "../../lib_perso/state_machine.h"
#include "MPU6050/stm32f1_mpu6050.h"
#include "high_lvl_cases.h"
#include "IDs.h"
#include "stm32f1_adc.h"

void LOW_LVL_Wait_Loop(State_drone_t * drone);
void LOW_LVL_Pwm_High(State_drone_t * drone);
void LOW_LVL_Update_Angles(State_drone_t * drone);
void LOW_LVL_Verif_System(State_drone_t * drone);
void LOW_LVL_Pwm_Low(State_drone_t * drone);
void LOW_LVL_Escs_Setpoints(State_drone_t * drone, State_base_t * base);
void LOW_LVL_Send_Data(State_drone_t * drone);
#endif /* LOW_LVL_CASES_H_ */
