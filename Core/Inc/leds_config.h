/*
 * leds_config.h
 *
 *  Created on: Jan 7, 2022
 *      Author: debian
 */

#ifndef SRC_LEDS_CONFIG_H_
#define SRC_LEDS_CONFIG_H_

#include "stm32f0xx_hal.h"

typedef struct {
	uint16_t leds_number;
	uint32_t *buff;
} LedsConfigTypeDef;


#endif /* SRC_LEDS_CONFIG_H_ */
