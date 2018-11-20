#pragma once
#include <SDL.h>
#include "inputs.h"

#ifndef EVENTS_H
#define EVENTS_H

class Events
{
public:

	//Data members
	//InputManager inputs;
	SDL_Event e;
	bool varQuit;
	SDL_KeyboardEvent key;

	//Member Functions()
	Events();
	void pollEvents();
	bool quit();
	bool inputMoveRight();
	bool keyDown();
	bool keyUp();

};



#endif
