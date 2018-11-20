#include <SDL.h>
#include "../include/inputs.h"
#include <iostream>


InputManager::InputManager()
{
	state = SDL_GetKeyboardState(NULL);
}

bool InputManager::moveRight()
{
	if (state[SDL_SCANCODE_D])
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool InputManager::moveLeft()
{
	if (state[SDL_SCANCODE_A])
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool InputManager::moveUp()
{
	if (state[SDL_SCANCODE_W])
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool InputManager::moveDown()
{
	if (state[SDL_SCANCODE_S])
	{
		return true;
	}
	else
	{
		return false;
	}
}