#include "util.h"
#pragma once

int approach(int32_t to, int32_t from, uint32_t step, uint32_t length)
{
	double temp = step / ((double)length);
	int dif = to - from;
	return (int)(dif* ((3 * temp * temp) - (2 * temp * temp * temp))) + from;
}
