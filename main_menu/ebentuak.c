#include "ebentuak.h"
#include "graphics.h"
#include "audio.h"
#include "game02/game02.h"

#include <SDL.h>


 static POSIZIOA saguPos;
SDL_Event event;
static SDL_Renderer* gRenderer;

 static POSIZIOA saguarenPosizioa() { return saguPos; }


SDL_Window* window = NULL;
int processEvents(void)
{
	

	float scaleX;
	float scaleY;
	
	SDL_Renderer* gRenderer = getRenderer();


 	SDL_RenderGetScale(gRenderer, &scaleX, &scaleY);


	SDL_Event event;
	int done = 0;



	arratoiaPosAurkitu();
	//check events
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_WINDOWEVENT_CLOSE:
		{
			if (window)
			{
				SDL_DestroyWindow(window);
				window = NULL;
				done = 1;
			}
		}
		break;
		case SDL_KEYDOWN:
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				done = 1;
				break;
			}
		}
		break;
		case SDL_MOUSEBUTTONDOWN:
		{
			if (pantailaZenb == 0)
			{

				if (mouse_x > 170 * scaleX && mouse_y > 60 * scaleY && mouse_y < 120 * scaleY && mouse_x < 460 * scaleX)
				{
					playSound(0);
					jokoaAurkeztu();
					jokatu();
					
					
				}
				if (mouse_x > 170 * scaleX && mouse_y > 240 * scaleY  && mouse_y < 300 * scaleY && mouse_x < 400 * scaleX)
				{
					done = 1;
				}
				if (mouse_x > 60 * scaleX && mouse_y > 120 * scaleY && mouse_y < 180 * scaleY && mouse_x < 400 * scaleX)
				{
					playSound(0);
					

					pantailaZenb = 1;
					
				} 
				if (mouse_x > 110 * scaleX && mouse_y > 180 * scaleY && mouse_x < 400 * scaleX && mouse_y < 240 * scaleY)
				{
					playSound(0);

					pantailaZenb = 2;
				}
			}
			if (pantailaZenb == 1)
			{
				if (mouse_x > 0 && mouse_y > 400 * scaleY && mouse_y < 450 * scaleY && mouse_x < 100 * scaleX)
				{
					playSound(0);
					pantailaZenb = 0;
					
				}
			}
			if (pantailaZenb == 2)
			{
				if (mouse_x > 0 && mouse_y > 400 * scaleY && mouse_y < 450 * scaleY && mouse_x < 100 * scaleX)
				{
					playSound(0);
					pantailaZenb = 0;
				}
			}
			break;
		}
		case SDL_QUIT: {
			//quit out of the game
			done = 1;
			break;
		}
		}
	}


	return done;
}
void arratoiaPosAurkitu()
{
	SDL_PumpEvents();
	SDL_GetMouseState(&mouse_x, &mouse_y);
}
void eventLoop()
{
	int done = 0;
	while (!done)
	{
		arratoiaPosAurkitu();
		//Check for events
		done = processEvents();

		//render display
		doRender();

		menuOptionSound = 0;

		//don't burn up the CPU
		SDL_Delay(10);
	}
}