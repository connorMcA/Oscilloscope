#include "globals.h"
#include "oscilloscope.h"
#include "shapes.h"

int(*updateShape)(Point**, int32_t);

void update(Point **points, uint32_t time)
{

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
