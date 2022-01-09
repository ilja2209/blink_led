/*
 * leds_effects.c
 *
 *  Created on: Jan 6, 2022
 *      Author: debian
 */

#include "snake.h"
#include "stars.h"

uint8_t effect_number = 0;

void LED_Animation_Init(LedsConfigTypeDef *config) {
	switch (effect_number) {
	case 0:
		Snake_Init(config);
		break;
	case 1:
		Stars_Init(config);
		break;
	default:
		effect_number = 0;
		Snake_Init(config);
		break;
	}
}

void LED_Animation_Step(LedsConfigTypeDef *config) {
	switch (effect_number) {
	case 0:
		Snake_Step(config);
		break;
	case 1:
		Stars_Step(config);
		break;
	default:
		Snake_Step(config);
		break;
	}
}

void LED_Switch_Mode(LedsConfigTypeDef *config) {
	effect_number++;
	LED_Animation_Init(config);
}
