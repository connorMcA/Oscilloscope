#include <SDL.h>
#include <conio.h>
#include "globals.h"
#include "oscilloscope.h"

Point newPoint();
void setup(Point **points);
void initPoints(Point **points);
void render(SDL_Renderer *ren, Point *points);

int main(int argc, char * argv[]) {

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		_cprintf("SDL_Init Error: \n");
		return 1;
	}
	const Point *points;
	setup(&points);

	SDL_Window *win = NULL;
	SDL_Renderer *ren = NULL;
	if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &win, &ren)) {
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
		return 3;

	}

	SDL_bool done = SDL_FALSE;
	while (!done) {
		SDL_Event event;

		update(&points);
		render(ren, points);

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				done = SDL_TRUE;
			}
		}
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
	SDL_SetRenderDrawColor(ren, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(ren);

	SDL_SetRenderDrawColor(ren, 255, 255, 255, SDL_ALPHA_OPAQUE);
	/*for (int i = 1; i < POINTS_COUNT; i++) {
		Point last = points[i - 1];
		Point point = points[i];
		SDL_RenderDrawLine(ren, last.x, last.y, point.x, point.y);
	}*/
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
