#pragma once
#ifndef __ENEMY__
#define __ENEMY__

#include "SDLGameObject.h"

class Enemy : public SDLGameObject {

public:

	Enemy(const LoaderParams* pParams);

	void draw();
	void update();
	void clean();

};

#endif
