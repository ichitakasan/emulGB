#ifndef SCREEN_H
#define SCREEN_H

#include <SDL/SDL.h>

#include "cpu.h"

#define SIZEX			160		// Number of pixels in X-axis
#define SIZEY			144		// Number of pixels in Y-axis
#define WIDTH			800		// Default screen width
#define HEIGHT			600		// Default screen height

#define NB_COLOURS		256		// Number of possible colours
#define CLEAR_COLOUR	128		// Colour when screen is cleared


/************************************************************************************
 *                                   STRUCTS
 ************************************************************************************/
typedef struct {
	SDL_Rect position;				// Pixel position on screen
	int pixelWidth, pixelHeight; 	// Pixel size, in case of a window resize
	SDL_Surface* surface;			// Pixel surface
	Uint8 colour;					// Pixel colour
} Pixel;

typedef struct {
	int mode;						// GPU mode
	int modeClock;					// Clock mode
	int line;						// Current drawn line
} GPU;

/************************************************************************************
 *                                  VARIABLES
 ************************************************************************************/
Pixel pixel[SIZEX][SIZEY];		// Pixels array
SDL_Surface* screen;			// SDL screen surface
GPU gpu;						// Graphical unit

/************************************************************************************
 *                                  FUNCTIONS
 ************************************************************************************/
// Init functions ...
int initialiseScreen();
void clearScreen();
void updatePixelSize();
void exitProgram();

// Drawing functions ...
void drawScreen();
void clockStep();

#endif // SCREEN_H
