#pragma once
#ifndef __GAMEOBJECT__
#define __GAMEOBJECT__

#include <iostream>
#include "TextureManager.h"
#include "LoaderParams.h"


class GameObject
{
public:

	virtual void draw();
	virtual void update();
	virtual void clean();

protected:

	GameObject(const LoaderParams* pParams) {}
	virtual ~GameObject() {}

};

#endif