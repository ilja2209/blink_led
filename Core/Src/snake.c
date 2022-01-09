/*
 * snake.c
 *
 *  Created on: Jan 7, 2022
 *      Author: debian
 */

#include "snake.h"
#include "utils.h"

static int dx;
static int len;
static int k;
static uint32_t default_color;

void Snake_Init(LedsConfigTypeDef *config) {
	dx = 1;
	len = 100;
	k = 0;
	default_color = Pack_RGB(0x00, 0x00, 0x20);
	fill_all_leds_with_color(config, default_color);
}

void Snake_Step(LedsConfigTypeDef *config) {
	if (k - len - dx >= 0)
		config->buff[k - len - dx] = default_color;
	uint8_t R = 0x00;
	for (int i = k; i > k - len; i--) {
		if (i > len / 2 + (k - len)) {
			R++;
		} else {
			R--;
		}
		if (i >= 0 && i < config->leds_number) {
			config->buff[i] = Pack_RGB(R, 0x00, 0x20);
		}
	}
	k++;
	if (k == config->leds_number + len - 1) {
		fill_all_leds_with_color(config, default_color);
		k = 0;
	}
}
