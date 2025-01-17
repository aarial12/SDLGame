#pragma once
#ifndef __SDLGAMEOBJECT__
#define __SDLGAMEOBJECT__	

#include "GameObject.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject {

public:

	SDLGameObject(const LoaderParams* pParams);

	virtual void draw();
	virtual void update();
	virtual void clean();

protected:

	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;
	
	int m_width, m_height;
	
	int m_currentFrame, m_currentRow;

	std::string m_textureID;

	virtual ~SDLGameObject() {}
};

#endif // !__SDLGAMEOBJECT__