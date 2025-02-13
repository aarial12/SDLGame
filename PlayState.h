#pragma once
#include "GameState.h"
#include <vector>
#include "SDLGameObject.h"

class PlayState : public GameState {

public:

	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	bool checkCollision(SDLGameObject* pi, SDLGameObject* p2);

	virtual std::string getStateID() const;

private:

	static const std::string s_playID;

	std::vector <GameObject*> m_gameObjects;

};
