
#include "SDL.h"

#include "graphics.h"
#include "irudiak.h"
#include <stdio.h>
#include <SDL_Image.h>

int irudiarenPosizioaAurkitu(int id);

typedef struct Img
{
	int id;
	SDL_Surface* imagen;
	SDL_Texture* texture;
	SDL_Rect dest;
}Irudi;

Irudi irudiak[100];
int irudiKop = 0;
int id = 0;

int irudiaKargatu(char* fileName)
{
	int colorkey;
	SDL_Surface* surface;
	SDL_Renderer* gRenderer = getRenderer();

	if (irudiKop < 100)
	{
		surface = IMG_Load(fileName);
		if (surface == NULL)
		{
			fprintf(stderr, "Couldn't load %s: %s\n", fileName, SDL_GetError());
			return -1;
		}
		else
		{
			colorkey = SDL_MapRGB(surface->format, 255, 0, 255);
			SDL_SetColorKey(surface, SDL_TRUE, colorkey);
			irudiak[irudiKop].texture = SDL_CreateTextureFromSurface(gRenderer, surface);
			irudiak[irudiKop].dest.x = irudiak[irudiKop].dest.y = 0;
			irudiak[irudiKop].dest.w = surface->w;
			irudiak[irudiKop].dest.h = surface->h;
			SDL_FreeSurface(surface);
			irudiak[irudiKop].id = id;
			irudiKop++;
			id++;
		}
	}
	else
	{
		printf("Has superado el maixmo de Imagens por aplicación.Para aumentar imagen.h\n");
		return -1;
	}

	return id - 1;
}

void  irudiaMugitu(int numImg, int x, int y)
{

	int id = 0;

	id = irudiarenPosizioaAurkitu(numImg);

	irudiak[id].dest.x = x;
	irudiak[id].dest.y = y;
}

void irudiBeltzakMarraztu(void)
{
	int i = 0;

	for (i = 0; i < 4; i++)
	{
		irudiaMarraztu(irudiak[i].texture, &irudiak[i].dest);
	}
}
void irudiakMugitu()
{
	//irudi bakoitzaren posizioa hemen joango da
	irudiaMugitu(0, 160, 60);
	irudiaMugitu(1, 60, 120);
	irudiaMugitu(2, 110, 190);
	irudiaMugitu(3, 160, 240);
	irudiaMugitu(4, 155, 60);
	irudiaMugitu(5, 50, 120);
	irudiaMugitu(6, 118, 170);
	irudiaMugitu(7, 184, 242);
	irudiaMugitu(8, 100, 0);
	irudiaMugitu(9, 0, 400);
}


void irudiaKendu(int id)
{
	int i = 0, pos = 0;

	pos = irudiarenPosizioaAurkitu(id);
	SDL_DestroyTexture(irudiak[pos].texture);
	for (i = pos; i < irudiKop; i++)
	{

		irudiak[i] = irudiak[i + 1];
	}
	irudiKop--;
}

int irudiarenPosizioaAurkitu(int id)
{
	int i = 0;

	for (i = 0; i < irudiKop; i++)
	{
		if (id == irudiak[i].id) return i;
	}
	return -1;
}

void loadMenuImages()
{
	irudiaKargatu("irudiak/jokatu.png");
	irudiaKargatu("irudiak/nola_jokatu.png");
	irudiaKargatu("irudiak/kontrolak.png");
	irudiaKargatu("irudiak/irten.png");
	irudiaKargatu("irudiak/jokatu_activate.png");
	irudiaKargatu("irudiak/nolaRed.png");
	irudiaKargatu("irudiak/kontrolak_red.png");
	irudiaKargatu("irudiak/irtenRed.png");
	irudiaKargatu("irudiak/jarraipenak.png");
	irudiaKargatu("irudiak/fletxa.png");
	irudiaKargatu("irudiak/kontrolak_screen.png");
}
void irudiGorriaMarraztu(int numImg)
{
	irudiaMarraztu(irudiak[numImg].texture, &irudiak[numImg].dest);
}
void nolaJokatuIrudiakMarraztu()
{
	int i;
	for (i = 8; i < 10; i++)
	{
		irudiaMarraztu(irudiak[i].texture, &irudiak[i].dest);
	}
}
void kontrolenIrudiakMarraztu()
{
	int i;
	for (i = 9; i <= 10; i++)
	{
		irudiaMarraztu(irudiak[i].texture, &irudiak[i].dest);
	}
}
void irudiakMarraztu(void)
{
	int i = 0;

	for (i = 0; i < irudiKop; i++)
	{
		irudiaMarraztu(irudiak[i].texture, &irudiak[i].dest);
	}
}
