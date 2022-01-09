/*
 * stars.c
 *
 *  Created on: Jan 8, 2022
 *      Author: debian
 */

#include "utils.h"
#include "stars.h"

uint32_t queue[10];
uint16_t queue_size;
uint16_t queue_pointer;
uint8_t default_intensity = 250;
uint32_t next;

uint32_t rand() {
	next = next * 1103515245 + 12345;
	return (uint32_t) (next / 65536) % 32768;
}

uint32_t Get_RndNumber(uint32_t value) {
	return (uint32_t) rand() % ((value + 1) - 0) + 0; //0 - low
}

void Stars_Init(LedsConfigTypeDef *config) {
	next = 1020;
	fill_all_leds_with_color(config, Pack_RGB(0x00, 0x00, 0x00));
	queue_size = 10;
	queue_pointer = 0;
}

void Stars_Step(LedsConfigTypeDef *config) {
	if (queue_pointer < queue_size) {
		queue[queue_pointer] = Get_RndNumber(config->leds_number - 1);
		config->buff[queue[queue_pointer]] = Pack_RGB(0x00, 0x00, default_intensity);
		queue_pointer++;
	} else {
		// Check queue. If buff[queue] == 0 then fill this place with new value
		for (int i = 0; i < queue_size; i++) {
			uint8_t B = Get_B(config->buff[queue[i]]);
			if (B == 0) {
				queue[i] = Get_RndNumber(config->leds_number - 1);
				config->buff[queue[i]] = Pack_RGB(0x00, 0x00, default_intensity);
			} else {
				B -= 10;
				config->buff[queue[i]] = Pack_RGB(0x00, 0x00, B);
			}
		}
	}
}
