/*
 * snake.h
 *
 *  Created on: Jan 7, 2022
 *      Author: debian
 */

#ifndef SRC_SNAKE_H_
#define SRC_SNAKE_H_

#include "leds_config.h"

void Snake_Init(LedsConfigTypeDef *config);
void Snake_Step(LedsConfigTypeDef *config);

#endif /* SRC_SNAKE_H_ */
