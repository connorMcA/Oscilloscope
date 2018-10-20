#include <math.h>
#include "globals.h"
#include "shapes.h"

static int32_t RADIUS = (HEIGHT - BUFFER) / 2;
static Point center = { .x = WIDTH / 2,.y = HEIGHT / 2 };
static float incr = (2 * PI) / 360.0f;
static int32_t xFactor = 2;
static int32_t baseOscillations = 80;
void updateCircles(Point **points, uint32_t time) {

	float cos_shift = cos(time/1000.0f);
	float sin_shift = sin(time/1000.0f);

	float diff = sin((time / 10000.0f) * incr);
	float oscillations = baseOscillations + (40 * sin(time / 1000.0f));

	float radius = RADIUS;// +50 * sin(time / 10.0f * incr);
	for (int32_t i = 0; i < POINTS_COUNT; i++) {
		float rad = (i / 5.0f) * incr;	
		float temp_x = (radius + diff) * cos(rad) - oscillations * cos(((radius + diff) /  diff)* rad);
		float temp_y = (radius + diff) * sin(rad) - oscillations * sin(((radius + diff) / diff)* rad);
		float dx = (temp_x * cos_shift - temp_y * sin_shift) / ROOT_TWO;
		float dy = (temp_y * cos_shift + temp_x * sin_shift) / ROOT_TWO;
		(*points)[i].x = (int32_t)(dx) + center.x;
		(*points)[i].y = (int32_t)(dy) + center.y;
	}

}