#include <SDL.h>
#include "../include/states.h"
#include <iostream>

States::States()
{
	collisionThreshold = 5;
}

bool States::collidingTop(Player* player, Sprite sprite)
{
	if (SDL_HasIntersection(player->getPlayerRect(), sprite.getSpriteRect()))
	{
		if (player->playerRectTop() >= sprite.spriteRectBottom() - collisionThreshold)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool States::collidingBottom(Player* player, Sprite sprite)
{
	if (SDL_HasIntersection(player->getPlayerRect(), sprite.getSpriteRect()))
	{
		if (player->playerRectBottom() <= sprite.spriteRectTop() + collisionThreshold)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool States::collidingLeft(Player* player, Sprite sprite)
{
	if (SDL_HasIntersection(player->getPlayerRect(), sprite.getSpriteRect()))
	{
		if (player->playerRectLeft() >= sprite.spriteRectRight() - collisionThreshold)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

bool States::collidingRight(Player* player, Sprite sprite)
{
	if (SDL_HasIntersection(player->getPlayerRect(), sprite.getSpriteRect()))
	{
		if (player->playerRectRight() <= sprite.spriteRectLeft() + collisionThreshold)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}