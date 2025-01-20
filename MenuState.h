#pragma once
#include "GameState.h"
#include "SDLGameObject.h"
#include <vector>

class MenuState : public GameState {
	
public:
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const;

private:

	static const std::string s_menuID;
	std::vector<SDLGameObject*> m_gameObjects;

};

