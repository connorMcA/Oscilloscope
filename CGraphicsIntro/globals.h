#pragma once
#define POINTS_COUNT (360 * 5 + 1)
#define WIDTH 720
#define HEIGHT 720
#define BUFFER 100

typedef struct Point_s {
	int x;
	int y;
} Point;

enum SHAPE{
	circle
};