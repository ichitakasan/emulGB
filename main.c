
#include "cpu.h"
#include "screen.h"
#include "keys.h"

/************************************************************************************
 *                                  VARIABLES
 ************************************************************************************/
SDL_Event event;

int listen();

/************************************************************************************
 *                                MAIN FUNCTION
 ************************************************************************************/
int main(int argc, char *argv[]) {

	// Initialisation ...
	int out = initialiseScreen();
	if (out)
		return out;
	initialiseCPU();

	// Load ROM file ...
	loadROM("roms/Tetris (W) (V1.0) [!].gb");

	// Print game info ...
	printGameInfo();

	// program main loop
	int done = 0;
	while (!done) {

		updateCPU();
//		drawScreen();
		done = listen();
		manageKeys();
	}

	printf("Exited cleanly\n");
	exitProgram();
	return 0;
}


/** Key events listening function. */
int listen() {

	int done = 0;
	int newWidth, newHeight;
	while (SDL_PollEvent(&event)) {

		switch (event.type) {
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE)
				done = 1;
			break;
		case SDL_VIDEORESIZE:
			newWidth = event.resize.w;
			newHeight = event.resize.h;

			// Create a new window
			screen = SDL_SetVideoMode(newWidth, newHeight, 16, SDL_HWSURFACE|SDL_RESIZABLE|SDL_DOUBLEBUF);
			if (!screen) {
				printf("Unable to set %dx%d video: %s\n", WIDTH, HEIGHT, SDL_GetError());
				exit(EXIT_FAILURE);
			}

			updatePixelSize(newWidth, newHeight);

			// Create pixel surfaces
			int i, j;
			for (i = 0; i < SIZEX; i++) {
				for (j = 0; j < SIZEY; j++) {
					// Surface
					SDL_FreeSurface(pixel[i][j].surface);
					pixel[i][j].surface = SDL_CreateRGBSurface(SDL_HWSURFACE, pixel[i][j].pixelWidth, pixel[i][j].pixelHeight, 32,0,0,0,0);
					if (pixel[i][j].surface == NULL) {
						fprintf(stderr, "Error while loading surface for pixel [%d, %d]: %s", i, j, SDL_GetError());
						exit(EXIT_FAILURE);
					}
				}
			}
			clearScreen();
			break;
		case SDL_QUIT:
			done = 1;
			break;
		default:
			break;
		}
	}
	return done;
}

