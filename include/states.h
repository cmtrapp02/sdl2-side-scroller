#include <SDL.h> 
#include "sprite.h"
#include "player.h"

#ifndef STATES_H
#define STATES_H

class States
{
public:

	//Variables
	int collisionThreshold;

	//States
	States();
	bool isColliding();
	bool collidingTop(Player* player, Sprite sprite);
	bool collidingBottom(Player* player, Sprite sprite);
	bool collidingLeft(Player* player, Sprite sprite);
	bool collidingRight(Player* player, Sprite sprite);
	bool isMoving();
	bool isFalling();

private:


protected:

};


#endif 