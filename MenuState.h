#pragma once
#include "GameState.h"
#include <vector>
#include "GameObject.h"

class MenuState : public GameState {
	
public:
	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const;

private:

	static const std::string s_menuID;
	std::vector<GameObject*> m_gameObjects;
	
	static void s_menuToPlay();
	static void s_exitFromMenu();

};

