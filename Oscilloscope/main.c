#include <SDL.h>
#include <conio.h>
#include "globals.h"
#include "oscilloscope.h"
#include "color.h"
#include <time.h>


void setup(Point **points);
void initPoints(Point **points);
void render(SDL_Renderer *ren, Point *points);

static uint32_t time_step = 1000;

int main(int argc, char * argv[]) {

	srand(time(0));
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		_cprintf("SDL_Init Error: \n");
		return 1;
	}


	const Point *points;
	setup(&points);
	color_init();

	SDL_Window *win = NULL;
	SDL_Renderer *ren = NULL;
	if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &win, &ren)) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
		return 3;

	}

	SDL_bool done = SDL_FALSE;
	while (!done) {

		SDL_Event event;

		update(&points, time_step);
		render(ren, points);

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				done = SDL_TRUE;
			}
		}
		time_step++;

	}
	if (points) {
		free(points);
		points = NULL;
	}

	
	
	if (ren) {
		SDL_DestroyRenderer(ren);
	}
	if (win) {
		SDL_DestroyWindow(win);
	}
	SDL_Quit();
	
	return 0;

}

void render(SDL_Renderer *ren, Point *points) {
	static Color color = { .rgba.r=0, .rgba.g=0, .rgba.g = 0, .rgba.a=255 };
	update_color(&color, time_step);

	SDL_SetRenderDrawColor(ren, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(ren);

	SDL_SetRenderDrawColor(ren, color.rgba.r, color.rgba.g, color.rgba.b, color.rgba.a);
	SDL_RenderDrawLines(ren, points, POINTS_COUNT);
	SDL_RenderPresent(ren);
}

Point newPoint()
{
	Point point = { .x = 0,.y = 0 };
	return point;
}

void setup(Point **points) {
	initPoints(points);
	init(circle);
	return points;
}

void initPoints(Point **points)
{
	*points = malloc(POINTS_COUNT * sizeof(Point));
	for (int i = 0; i < POINTS_COUNT; i++) {
		(*points)[i] = newPoint();
	}
}
