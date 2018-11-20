
#include "../include/worldobject.h"
#include <SDL.h>
#include <iostream>
#include <tuple>


WorldObject::WorldObject()
{
	// Initialize variables
	rect = new SDL_Rect;
}

void WorldObject::setObjectSize(int width, int height) 
{
	// Sets the size of the object
	rect->w = width, rect->h = height;
}

void WorldObject::fillRect(SDL_Surface* surf, SDL_Rect* rect, int R, int G, int B)
{
	//fill the rect with a particular color
	SDL_FillRect(surf, rect, SDL_MapRGB(surf->format, R, G, B));
}

void WorldObject::setLocation(int posX, int posY)
{
	//Sets the location of the object in the world, 
	//can be used to move the object
	//if constantly updated through the main loop.

	rect->x = posX, rect->y = posY;

}

SDL_Rect * WorldObject::getRect()
{
	//Return the objects rectangle
	return rect;
}

std::tuple<int, int> WorldObject::getRectSize()
{
	int width = rect->w;
	int height = rect->h;
	return std::make_tuple(width, height);
}

int WorldObject::objectRectTop()
{
	int top = rect->y;
	return top;
}

int WorldObject::objectRectBottom()
{
	int bottom = rect->y + rect->h;
	return bottom;
}

int WorldObject::objectRectLeft()
{
	int left = rect->x;
	return left;
}

int WorldObject::objectRectRight()
{
	int right = rect->x + rect->w;
	return right;
}

bool WorldObject::objectRectCollision(SDL_Rect* rect1, SDL_Rect* rect2)
{
	if (SDL_HasIntersection(rect1, rect2))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void WorldObject::blitObject(SDL_Surface* img, SDL_Surface* surface) 
{
	//Blits the image to the screen
	SDL_SetClipRect(img, rect);
	SDL_BlitSurface(img, NULL, surface, rect);
}