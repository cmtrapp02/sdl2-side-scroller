
#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include "../include/constants.h"
#include "../include/events.h"
#include "../include/player.h"
#include "../include/events.h"
#include "../include/sprite.h"

//forward declarations
bool init();
bool loadMedia(SDL_Surface* media[], int size);
void close(SDL_Window* window, SDL_Surface* screenSurface);

bool init() 
{
	//Init flags
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) 
	{
		std::cout << "SDL could not initialize! SDL_Error: %s\n" << SDL_GetError() << std::endl;
		success = false;
	}

	return success;
}


bool loadMedia(SDL_Surface* media[], int size) 
{
	bool success = true;

	int iii = 0;
	for (iii; iii < size; ++iii)
	{
		if (media[iii] == NULL)
		{
			std::cout << "Unable to load image %s! SDL Error: %\n" << SDL_GetError() << std::endl;
			success = false;
		}
	}

	return success;
}


void close(SDL_Window* window, SDL_Surface* screenSurface) 
{
	//Deallocate the surface
	SDL_FreeSurface(screenSurface);
	screenSurface = NULL;

	//Destroy the window
	SDL_DestroyWindow(window);
	window = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}


int main(int argc, char* args[])
{
	if (!init())
	{
		std::cout << "SDL could not initialize! SDL_Error: %s\n" << SDL_GetError() << std::endl;
		return 0;
	}

	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	SDL_Surface* backGround = NULL;
	SDL_Surface* blueRectImage = NULL;
	SDL_Surface* playerImage = NULL;
	SDL_Surface* groundImage = NULL;
	SDL_Renderer* renderer = NULL;
		
	//define surface variables
	window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	screenSurface = SDL_GetWindowSurface(window);
	
	//Load images
	backGround = SDL_LoadBMP("graphics/testsky.bmp");
	blueRectImage = SDL_LoadBMP("graphics/bluerect.bmp");
	playerImage = SDL_LoadBMP("graphics/testplayer.bmp");
	groundImage = SDL_LoadBMP("graphics/testground.bmp");

	//Put images in array to be sorted through and checked for errors
	SDL_Surface* media[] = { backGround, blueRectImage, playerImage, groundImage };
	int mediaSize = std::size(media);

	//instantiate classes
	Events e;
	Player player;
	WorldObject object;
	Sprite blueRect01;
	Sprite blueRect02;
	Sprite testGround;
	
	//Sprites in array to be be aggregated through for collisions
	Sprite sprites[] = { blueRect01, blueRect02, testGround };
	int spriteSize = std::size(sprites);

	//Main flags
	bool qt = false;

	//Load media
	if (!loadMedia(media, mediaSize)) 
	{
		std::cout << "Falied to load media!" << std::endl;
	}
	else 
	{
		//Main game loop
		while (!qt) 
		{
			//Events aggregator
			e.pollEvents();
			if (e.quit() == true) 
			{
				qt = true;
			}

			//TODO: break most of these processes down into functions so that it
			//isn't all sitting in main.
			WorldObject blueRect = blueRect01;
			//blit the surfaces to the screen
			SDL_BlitSurface(backGround, NULL, screenSurface, NULL);
			blueRect01.blitSprite(blueRectImage, screenSurface);
			blueRect02.blitSprite(blueRectImage, screenSurface);
			testGround.blitSprite(groundImage, screenSurface);

			//set the location of the surfaces
			blueRect01.location(0, 150);
			blueRect02.location(500, 150);
			testGround.location(0, 350);

			player.blitPlayer(playerImage, screenSurface);
			player.playerCollision(sprites, spriteSize);
			player.movePlayer();

			SDL_UpdateWindowSurface(window);
		}
			
	}

	//Free resources and close SDL
	close(window, screenSurface);

	return 0;
}
