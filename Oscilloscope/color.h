#pragma once
#include "globals.h"

typedef struct RGBA_s {
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
} RGBA;

typedef struct Color_s {
	union {
		uint32_t color;
		RGBA rgba;
	};
}Color;

void update_color(Color *color, uint32_t time);

void color_init();

void randomize_color(Color *color);