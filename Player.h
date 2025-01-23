#pragma once
#ifndef __PLAYER__
#define __PLAYER__

#include "SDLGameObject.h"

class Player : public SDLGameObject {

public:

	Player(const LoaderParams* pParagrams);

	void draw(SDL_Renderer* p_Renderer);
	void handleInput();
	void update();
	void clean();

};

#endif // !__PLAYER__