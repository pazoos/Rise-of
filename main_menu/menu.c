#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "irudiak.h"
#include "ebentuak.h"
#include "audio.h"
#include "graphics.h"
#include "textua.h"
#include "SDL_TTF.h"

#define MENU_OPTION_SOUND "musika/optionSelect.wav"

typedef struct
{
	int x, y;
	short life;
	char* name;
} Man;

typedef struct {
	//Players
	Man man;
}GameState;

void jokoaHasieratu(void);
void jokoaItxi(void);
int main(int argc, char* argv[])
{
	jokoaHasieratu();
	eventLoop();
	jokoaItxi();
	return 0;

}

void jokoaHasieratu()
{
	sgHasieratu();
	audioInit();
	loadMenuImages();
	menukoMusikaHasieratu();
}
void jokoaItxi()
{
	audioTerminate();
	sgItxi();
}