/*
 * high_lvl_cases.h
 *
 *  Created on: 29 juin 2020
 *      Author: Th�o
 */

#include "system_d.h"
#include "MAE.h"
#include "settings.h"
#include "sub/sub_action.h"
#include "../events/events.h"

#ifndef HIGH_LVL_H_
#define HIGH_LVL_H_

//Fonctions .. bref
void HIGH_LVL_Switch(State_drone_t * drone, State_base_t * base);


//Fonctions pour les diff�rents mode de vol + la fonction qui les appelle
void HIGH_LVL_On_The_Ground(State_drone_t * drone);
void HIGH_LVL_Manual(State_drone_t * drone);
void HIGH_LVL_Manual_Hand_Control(State_drone_t * drone, State_base_t * base);
void HIGH_LVL_Parachute(State_drone_t * drone);
void HIGH_LVL_Calibrate_MPU(State_drone_t * drone);
void HIGH_LVL_Manual_Pc(State_drone_t * drone);
void HIGH_LVL_IMU_Failed_Init(State_drone_t * drone);
void HIGH_LVL_Manual_Accro(State_drone_t * drone);
void HIGH_LVL_Change_Pid_Settings(State_drone_t * drone);

//Fonction pour la mise � jour des flags
void HIGH_LVL_Update_Flags(State_drone_t * drone);


#endif /* HIGH_LVL_CASES_H_ */
