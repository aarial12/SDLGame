#pragma once
#include "GameState.h"
#include <vector>
#include "GameObject.h"

class PauseState : public GameState
{
public: 

	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const;

private:

	static const std::string s_pauseID;
	std::vector<GameObject*> m_gameObjects;

	static void s_pauseToMain();
	static void s_resumePlay();
};

