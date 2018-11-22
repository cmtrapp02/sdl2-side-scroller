
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include "../include/constants.h"
#include "../include/events.h"
#include "../include/player.h"
#include "../include/events.h"
#include "../include/sprite.h"

//forward declarations
bool init();
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
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		std::cout << "SDL_Image could not initialize! SDL_Image Error: %s\n" << IMG_GetError() << std::endl;
		success = false;
	}
	if (TTF_Init() == -1)
	{
		std::cout << "SDL_ttf could not initialize! SDL_ttf Error: %s\n" << TTF_GetError() << std::endl;
		success = false;
	}

	return success;
}

SDL_Surface* loadSurface(const char* bmp, SDL_Surface* surf)
{
	SDL_Surface* image = SDL_LoadBMP(bmp);
	SDL_Surface* optimizedSurf = SDL_ConvertSurface(image, surf->format, NULL);
	SDL_FreeSurface(image);
	
	if (optimizedSurf == NULL)
	{
		printf("SDL Error loading %s: %s\n", bmp, SDL_GetError());
		exit(1);
	}

	return optimizedSurf;
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
	
	//define surface variables
	SDL_Window* window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
	
	//Load images
	SDL_Surface* backGround = loadSurface("graphics/testsky.bmp", screenSurface);
	SDL_Surface* blueRectImage = loadSurface("graphics/bluerect.bmp", screenSurface);
	SDL_Surface* playerImage = loadSurface("graphics/testplayer.bmp", screenSurface);
	SDL_Surface* groundImage = loadSurface("graphics/testground.bmp", screenSurface);

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

	//Free resources and close SDL
	close(window, screenSurface);

	return 0;
}
