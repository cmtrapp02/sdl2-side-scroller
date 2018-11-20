#include <SDL.h>
#include "../include/player.h"
#include "../include/inputs.h"
#include "../include/states.h"
#include <iostream>

Player::Player()
{
	posX = 0;
	posY = 0;
	playerSpeed = 1;
	iii = 0;
}

void Player::playerCollision(Sprite sprite[], int size)
{
	States states;
	cldTop = false;
	cldBottom = false;
	cldLeft = false;
	cldRight = false;
	int collisionShreshold = 10;
	
	for (iii; iii < size; ++iii)
	{
		if (states.collidingTop(this, sprite[iii]))
		{
			cldTop = true;
		}

		if (states.collidingBottom(this, sprite[iii]))
		{
			cldBottom = true;
		}

		if (states.collidingLeft(this, sprite[iii]))
		{
			cldLeft = true;
		}

		if (states.collidingRight(this, sprite[iii]))
		{
			cldRight = true;
		}

	}
	
	if (iii = size)
	{
		iii = 0;
	}
}

void Player::movePlayer()
{
	InputManager input;
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	if (input.moveRight() && !cldRight)
	{
		posX += 1 * playerSpeed;
	}
	if (input.moveLeft() && !cldLeft)
	{
		posX -= 1 * playerSpeed;
	}
	if (input.moveDown() && !cldBottom)
	{
		posY += 1 * playerSpeed;
	}
	if (input.moveUp() && !cldTop)
	{
		posY -= 1 * playerSpeed;
	}

	setLocation(posX, posY);
}

SDL_Rect * Player::getPlayerRect()
{
	//Return the player rect for collision detection
	return getRect();
}

int Player::playerRectTop()
{
	int top = objectRectTop();
	return top;
}

int Player::playerRectBottom()
{
	int bottom = objectRectBottom();
	return bottom;
}

int Player::playerRectLeft()
{
	int left = objectRectLeft();
	return left;
}

int Player::playerRectRight()
{
	int right = objectRectRight();
	return right;
}

void Player::blitPlayer(SDL_Surface* image, SDL_Surface* surf)
{
	blitObject(image, surf);
}