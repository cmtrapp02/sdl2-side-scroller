#include <SDL.h>

#ifndef INPUTS_H
#define INPUTS_H

class InputManager
{
public:

	//Variables
	const Uint8 *state = NULL;

	//Functions
	InputManager();
	bool moveRight();
	bool moveLeft();
	bool moveUp();
	bool moveDown();

private:

protected:
};

#endif INPUTS_H
