/*
 * telem_2.h
 *
 *  Created on: 8 sept. 2020
 *      Author: Th�o
 */

#ifndef BTM_TELEM_2_H_
#define BTM_TELEM_2_H_

#include "stdio.h"
#include "../../appli/IDs.h"
#include "../appli/system_d.h"
#include "scheduler/scheduler.h"

//Fonction "utilitaire" r�utilis�es par d autres fonctions de telemetrie
void TELEM2_send_data(Ids_t id, uint8_t * data, uint8_t len);
void TELEM2_send_float(Ids_t id, float value);


#endif /* BTM_TELEM_2_H_ */
