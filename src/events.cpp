 
#include <SDL.h>
#include <iostream>
#include "../include/events.h"

Events::Events()
{
	varQuit = false;
	e.key.keysym.scancode;
}

void Events::pollEvents()
{
	if (SDL_PollEvent(&e) != 0)
	{
		quit();
		keyDown();
		keyUp();
		//inputs.moveRight();
	}
}

bool Events::quit() 
{
	if (e.type == SDL_QUIT) 
	{
		varQuit = true;
		return varQuit;
	}
	else
	{
		varQuit = false;
		return varQuit;
	}
}

bool Events::inputMoveRight()
{
	if (e.key.keysym.scancode == SDL_SCANCODE_D && keyDown())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Events::keyDown() 
{
	//SDL_Event event;
	if (e.type == SDL_KEYDOWN) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Events::keyUp()
{
	if (e.type == SDL_KEYUP)
	{
		return true;
	}
	else
	{
		return false;
	}
}
