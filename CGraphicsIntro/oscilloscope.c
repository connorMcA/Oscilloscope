#include "globals.h"
#include "oscilloscope.h"
#include "shapes.h"

int(*updateShape)(Point**, int);

void update(Point **points)
{
	static int time = 0;
	time++;
	updateShape(points, time);
}

void init(enum SHAPE shape)
{
	switch (shape) {
	case circle:
		updateShape = &updateCircles;
		break;
	}
}
