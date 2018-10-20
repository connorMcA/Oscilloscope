#pragma once

#include "color.h"

static uint32_t colorChangeLength = 10000;
static Color nextColor;
static Color baseColor;

void update_color(Color * color, uint32_t time)
{
	uint32_t t = time % colorChangeLength;
	
	if (t == 0) {
		baseColor.color = color->color;
		randomize_color(&nextColor);
	}

	color->rgba.r = (uint8_t)approach(nextColor.rgba.r, baseColor.rgba.r, t, colorChangeLength);
	color->rgba.g = (uint8_t)approach(nextColor.rgba.g, baseColor.rgba.g, t, colorChangeLength);
	color->rgba.b = (uint8_t)approach(nextColor.rgba.b, baseColor.rgba.b, t, colorChangeLength);

}

void color_init()
{
	randomize_color(&baseColor);
	randomize_color(&nextColor);
}

void randomize_color(Color *color) {
	color->rgba.r = rand() % 200 + 55;
	color->rgba.g = rand() % 200 + 55;
	color->rgba.b = rand() % 200 + 55;
	color->rgba.a = UINT8_MAX;
}
