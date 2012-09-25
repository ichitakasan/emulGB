#include "screen.h"

/************************************************************************************
 *                               INIT FUNCTIONS
 ************************************************************************************/
/** Initialises the screen by setting SDL init functions.
 * @return Error code: 0 if OK, 1 if error occurred. */
int initialiseScreen() {

	putenv(strdup("SDL_VIDEO_CENTERED=1"));

	atexit(exitProgram);

	// SDL initialisation
	if (SDL_Init(SDL_INIT_VIDEO) == -1) {
		fprintf(stderr, "SDL initialisation error: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	// Create a new window
    screen = SDL_SetVideoMode(WIDTH, HEIGHT, 16, SDL_HWSURFACE|SDL_RESIZABLE|SDL_DOUBLEBUF);
	SDL_WM_SetCaption("EmulGB By Ichitaka", NULL);
    if (!screen) {
        printf("Unable to set %dx%d video: %s\n", WIDTH, HEIGHT, SDL_GetError());
        return 1;
    }

	updatePixelSize(WIDTH, HEIGHT);

	// Create pixel surfaces
	int i, j;
	for (i = 0; i < SIZEX; i++) {
		for (j = 0; j < SIZEY; j++) {
			// Surface
			pixel[i][j].surface = SDL_CreateRGBSurface(SDL_HWSURFACE, pixel[i][j].pixelWidth, pixel[i][j].pixelHeight, 32,0,0,0,0);
			if (pixel[i][j].surface == NULL) {
				fprintf(stderr, "Error while loading surface for pixel [%d, %d]: %s", i, j, SDL_GetError());
				exit(EXIT_FAILURE);
			}
		}
	}

	clearScreen();

	gpu.mode = 0;
	gpu.modeClock = 0;
	gpu.line = 0;

	return 0;
}

/** Clears the screen. */
void clearScreen() {

	int i, j;
	for (i = 0; i < SIZEX; i++) {
		for (j = 0; j < SIZEY; j++) {
			// Colour
//			pixel[i][j].colour = CLEAR_COLOUR;
			if(i % (j + 1) == 0) pixel[i][j].colour = 0; else pixel[i][j].colour = 128;
			SDL_FillRect(pixel[i][j].surface, NULL, SDL_MapRGB((pixel[i][j].surface)->format,
																pixel[i][j].colour, pixel[i][j].colour, pixel[i][j].colour));
		}
	}
}

/** Sets pixels' size and position.
 * @param screenWidth Screen width (in pixels).
 * @param screenHeight Screen height (in pixels). */
void updatePixelSize(int screenWidth, int screenHeight) {

	int i, j;
	for (i = 0; i < SIZEX; i++) {
		for (j = 0; j < SIZEY; j++) {
			// Size
			pixel[i][j].pixelWidth = screenWidth*2 / SIZEX;
			pixel[i][j].pixelHeight = screenHeight*2 / SIZEY;
			// Position
			pixel[i][j].position.x = (int)(i * screenWidth / (float)SIZEX);
			pixel[i][j].position.y = (int)(j * screenHeight / (float)SIZEY);
		}
	}
}

/** Quits SDL and exits the program. */
void exitProgram() {

	// Pixel array
 	int i, j;
	for (i = 0; i < SIZEX; i++)
		for (j = 0; j < SIZEY; j++)
			SDL_FreeSurface(pixel[i][j].surface);
	// Screen surface
	SDL_FreeSurface(screen);

    // Quit SDL
	SDL_Quit();
}

/************************************************************************************
 *                               UPDATE FUNCTION
 ************************************************************************************/
/** Clock step function. */
void clockStep() {

	gpu.modeClock += cpu.t;
	switch (gpu.mode) {

	// OAM read mode, scanline active
	case 2:
		if (gpu.modeClock >= 80) {

			// Enter scanline mode 3
			gpu.modeClock = 0;
			gpu.mode = 3;
		}
		break;

	// VRAM read mode, scanline active
	// Treat end of mode 3 as end of scanline
	case 3:
		if (gpu.modeClock >= 172) {

			// Enter HBlank
			gpu.modeClock = 0;
			gpu.mode = 0;
			// Write a scanline to the framebuffer
			gpu.renderscan();
		}
		break;

	// HBlank
	// After the last HBlank, push the screen data to canvas
	case 0:
		if (gpu.modeClock >= 204) {

			gpu.modeClock = 0;
			gpu.line++;

			if (gpu.line >= 143) {
				// Enter VBlank
				gpu.mode = 1;
				gpu.putImageData(gpu.screen, 0, 0);
			} else
				gpu.mode = 2;
		}
		break;

	// VBlank (10 lines)
	case 1:
		if (gpu.modeClock >= 456) {

			gpu.modeClock = 0;
			gpu.line++;

			if (gpu.line >= 153) {
				// Restart scanning modes
				gpu.mode = 2;
				gpu.line = 0;
			}
		}
		break;
	}
}

/************************************************************************************
 *                               DRAWING FUNCTION
 ************************************************************************************/
/** Draws the screen by plotting each pixel. */
void drawScreen() {

	// Clear screen
	SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, CLEAR_COLOUR, CLEAR_COLOUR, CLEAR_COLOUR));

	// Draw each pixel
	int i, j;
	for (i = 0; i < SIZEX; i++)
		for (j = 0; j < SIZEY; j++)
			SDL_BlitSurface(pixel[i][j].surface, NULL, screen, &pixel[i][j].position);

	// Finally, update the screen :)
	SDL_Flip(screen);
}
