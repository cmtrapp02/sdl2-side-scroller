#pragma once
#include <SDL.h>
#include "worldobject.h"
#include "sprite.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player: public WorldObject
{
public:

	// Data members
	int playerSpeed;
	int posX;
	int posY;

	Player();
	void movePlayer();
	SDL_Surface setPlayerImage(SDL_Surface* img);
	SDL_Rect * getPlayerRect();
	int playerRectTop();
	int playerRectBottom();
	int playerRectLeft();
	int playerRectRight();
	void playerCollision(Sprite sprite[], int size);
	void blitPlayer(SDL_Surface* surf, SDL_Surface* image);

private:

	bool cldTop;
	bool cldBottom;
	bool cldLeft;
	bool cldRight;
	SDL_Rect* rect;

protected:

	int iii;
};


#endif
