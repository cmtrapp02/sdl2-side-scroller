#pragma once
#include <SDL.h>
#include <tuple>

#ifndef WORLDOBJECT_H
#define WORLDOBJECT_H

class WorldObject
{
public:
	
	WorldObject();

protected:
	 
	// Member functions
	void setObjectSize(int width, int height);
	void fillRect(SDL_Surface* surf, SDL_Rect* rect, int R, int G, int B);
	void setLocation(int posX, int posY);
	SDL_Surface setImage(SDL_Surface* img);
	std::tuple<int, int> getRectSize();
	SDL_Rect * getRect();
	int objectRectTop();
	int objectRectLeft();
	int objectRectRight();
	int objectRectBottom();
	bool objectRectCollision(SDL_Rect* rect1, SDL_Rect* rect2);
	void blitObject(SDL_Surface* img, SDL_Surface* surface);

private:

	// Data members
	SDL_Rect* rect;
	SDL_Surface* image;
};

#endif