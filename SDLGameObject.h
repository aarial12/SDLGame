#pragma once
#ifndef __SDLGAMEOBJECT__
#define __SDLGAMEOBJECT__	

#include "GameObject.h"

class SDLGameObject : public GameObject {

public:

	SDLGameObject(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();

protected:

	int m_x, m_y;
	
	int m_width, m_height;
	
	int m_currentFrame, m_currentRow;

	std::string m_textureID;

	virtual ~SDLGameObject() {}
};

#endif // !__SDLGAMEOBJECT__