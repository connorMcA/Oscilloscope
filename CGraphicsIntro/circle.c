#include <math.h>
#include "globals.h"
#include "shapes.h"

static int RADIUS = (HEIGHT - BUFFER) / 2;
static Point center = { .x = WIDTH / 2,.y = HEIGHT / 2 };
static float incr = (2 * PI) / 360.0f;
static int xFactor = 2;

void updateCircles(Point **points, int time) {

	for (int i = 0; i < POINTS_COUNT; i++) {
		float rad = (i/5.0f) * incr;
		float radius = RADIUS + 50 * sin(time / 13.0f * incr);
		(*points)[i].x = (int)(cos(rad *(xFactor + cos(time/2000.0f))) * radius) + center.x;
		(*points)[i].y = (int)(sin(rad * 2.0f) * radius) + center.y;
	}

}