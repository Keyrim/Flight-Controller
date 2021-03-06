/*
 * MAE.h
 *
 *  Created on: 13 juin 2020
 *      Author: Th�o
 */

#ifndef MAE_H_
#define MAE_H_

//�tat pour la high lvl
typedef enum{
	ON_THE_GROUND,
	MANUAL,
	PARACHUTE,
	MANUAL_HAND_CONTROL,
	POSITION_HOLD,
	ALTITUDE_HOLD,
	CALIBRATE_MPU6050,
	MANUAL_PC,
	MANUAL_ACCRO,
	IMU_FAILED_INIT,
	PID_CHANGE_SETTINGS
}Flight_Mode_SM;

//�tat pour la stabilisation
typedef enum{
	STAB_OFF,
	LEVELLED,
	ACCRO
}Stabilisation_SM;

#endif /* MAE_H_ */
