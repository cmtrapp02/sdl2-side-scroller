#include "SDL.h"
#include "../include/sprite.h"

Sprite::Sprite() 
{
	rect = getRect();
}

void Sprite::location(int posX, int posY)
{
	setLocation(posX, posY);
}

SDL_Rect * Sprite::getSpriteRect()
{
	return rect;
}

int Sprite::spriteRectTop()
{
	return objectRectTop();
}

int Sprite::spriteRectBottom()
{
	return objectRectBottom();
}

int Sprite::spriteRectLeft()
{
	return objectRectLeft();
}

int Sprite::spriteRectRight()
{
	return objectRectRight();
}

void Sprite::blitSprite(SDL_Surface* image, SDL_Surface* surf)
{
	blitObject(image, surf);
}