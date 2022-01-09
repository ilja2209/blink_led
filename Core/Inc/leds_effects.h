/*
 * leds_effects.h
 *
 *  Created on: Jan 6, 2022
 *      Author: debian
 */

#ifndef SRC_LEDS_EFFECTS_H_
#define SRC_LEDS_EFFECTS_H_

#include "leds_config.h"

void LED_Animation_Init(LedsConfigTypeDef *config);
void LED_Animation_Step(LedsConfigTypeDef *config);
void LED_Switch_Mode(LedsConfigTypeDef *config);

#endif /* SRC_LEDS_EFFECTS_H_ */
