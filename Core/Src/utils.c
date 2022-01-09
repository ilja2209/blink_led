#include "utils.h"

void fill_all_leds_with_color(LedsConfigTypeDef *config, uint32_t colors) {
	for (int i = 0; i < config->leds_number; i++) {
		config->buff[i] = colors;
	}
}
