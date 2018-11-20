#include <SDL.h>
#include "worldobject.h"

#ifndef SPRITE_H
#define SPRITE_H

class Sprite : public WorldObject
{
public:

	//Functions
	Sprite();
	void location(int posX, int posY);
	SDL_Rect * getSpriteRect();
	int spriteRectTop();
	int spriteRectBottom();
	int spriteRectLeft();
	int spriteRectRight();
	void blitSprite(SDL_Surface* image, SDL_Surface* surf);

private:

	SDL_Rect* rect;

protected:

};

#endif
