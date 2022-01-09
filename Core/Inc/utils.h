/*
 * utils.h
 *
 *  Created on: Jan 7, 2022
 *      Author: debian
 */

#ifndef INC_UTILS_H_
#define INC_UTILS_H_

#include "stm32f0xx_hal.h"
#include "leds_config.h"

/**
 * Convert RGB vector to uint32 value in format 0xGGRRBB
 */
#define Pack_RGB(R, G, B) ((uint32_t)B | ((uint32_t)R << 8) | ((uint32_t)G << 16))
#define Get_B(value) (((uint8_t)value) & 0x000000FF)

void fill_all_leds_with_color(LedsConfigTypeDef *config, uint32_t colors);

#endif /* INC_UTILS_H_ */
