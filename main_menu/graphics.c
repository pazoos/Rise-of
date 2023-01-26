
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define GRAPHICS

#include "SDL_ttf.h"

#include "irudiak.h"
#include "graphics.h"
#include "ebentuak.h"



 static SDL_Window* window = NULL;
SDL_Renderer* gRenderer;
int colorR, colorG, colorB;
const wTD = 640, hTD = 480;

SDL_Renderer* getRenderer(void) { return gRenderer; }




void doRender()
{

  
    //Fonduan kolorea ezarri
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 250, 250);

    //Fondua marraztu
    SDL_RenderClear(gRenderer);

    
    float scaleX;
    float scaleY;


    SDL_RenderGetScale(gRenderer, &scaleX, &scaleY);
    //pantailaZenb aldagaiak ze pantailatan dagoen adierazten dau,0 menu printzipalerako, 1 nola jokatu atalerako eta 2 aukerak atalerako
    if (pantailaZenb == 0)
    {
        irudiBeltzakMarraztu();
        if (mouse_x > 170 * scaleX && mouse_y > 60 * scaleY && mouse_y < 120 * scaleY && mouse_x < 460 * scaleX)
        {
            irudiGorriaMarraztu(4);
        }
        if (mouse_x > 60 * scaleX && mouse_y > 120 * scaleY && mouse_y < 180 * scaleY && mouse_x < 500 * scaleX)
        {
            irudiGorriaMarraztu(5);
        }
        if (mouse_x > 120 * scaleX && mouse_y > 180 * scaleY && mouse_y < 240 * scaleY && mouse_x < 460 * scaleX)
        {
            irudiGorriaMarraztu(6);
        }
        if (mouse_x > 170 * scaleX && mouse_y > 240 * scaleY && mouse_y < 300 * scaleY && mouse_x < 400 * scaleX)
        {
            irudiGorriaMarraztu(7);
        }
    }
    if (pantailaZenb == 1)
    {
        nolaJokatuIrudiakMarraztu();
    }
    if (pantailaZenb == 2)
    {
        kontrolenIrudiakMarraztu();
    }
    irudiakMugitu();

    pantailaBerriztu();
    pantailaGarbitu();

}
int sgHasieratu() {
    {
        int ret = 0;

        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            fprintf(stderr, "ezin SDL hasieratu: %s\n", SDL_GetError());
            return -1;
        }
        atexit(SDL_Quit);
        window = SDL_CreateWindow("Rise of the MUtants", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            fprintf(stderr, "Ezin lehioa sortu: %s\n", SDL_GetError());
            return -1;
        }
        gRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        SDL_RenderSetLogicalSize(gRenderer, wTD, hTD);
        SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
        TTF_Init();
        atexit(TTF_Quit);
        return ret;
    }
}

void sgItxi()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(gRenderer);
    SDL_Quit();
}

void arkatzKoloreaEzarri(red, green, blue)
{
    colorR = red;
    colorG = green;
    colorB = blue;
}


void zuzenaMarraztu(x1, y1, x2, y2)
{
    SDL_SetRenderDrawColor(gRenderer, colorR, colorG, colorB, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(gRenderer, x1, y1, x2, y2);
}

void puntuaMarraztu(x, y)
{
    SDL_SetRenderDrawColor(gRenderer, colorR, colorG, colorB, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawPoint(gRenderer, x, y);
}

void zirkuluaMarraztu(x, y, r)
{

    int i, h;

    SDL_SetRenderDrawColor(gRenderer, colorR, colorG, colorB, SDL_ALPHA_OPAQUE);
    for (i = x - r; i <= x + r; i++)
    {
        h = (int)llround(sqrt((double)(r * r - (i - x) * (i - x))));
        SDL_RenderDrawLine(gRenderer, i, y + h, i, y - h);
    }
}



int irudiaMarraztu(SDL_Texture* texture, SDL_Rect* pDest)
{
    SDL_Rect src;

    src.x = 0;
    src.y = 0;
    src.w = pDest->w;
    src.h = pDest->h;
    SDL_RenderCopy(gRenderer, texture, &src, pDest);
    return 0;
}

void pantailaGarbitu()
{
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(gRenderer);
}


void pantailaBerriztu()
{
    SDL_RenderPresent(gRenderer);
}