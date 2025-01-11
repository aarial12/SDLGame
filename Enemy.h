#pragma once
#ifndef __ENEMY__
#define __ENEMY__

#include "GameObject.h"

class Enemy : public GameObject {

public:

	void load(int x, int y, int width, int height, std::string textureID);
	void draw(SDL_Renderer* p_Renderer);
	void update();
	void clear();

};

#endif
