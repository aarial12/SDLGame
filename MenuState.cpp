#include "MenuState.h"
#include "MenuButton.h"
#include "Game.h"

const std::string MenuState::s_menuID = "MENU";

void MenuState::update() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
}

void MenuState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

bool MenuState::onEnter() {

	if (!TheTextureManager::Instance()->load("Assets/button.png", "playButton", TheGame::Instance()->getRenderer())) 
		return false;
	
	if (!TheTextureManager::Instance()->load("Assets/exit.png", "exitButton", TheGame::Instance()->getRenderer())) 
		return false;

	SDLGameObject* button1 = new MenuButton(new LoaderParams(100, 100, 400, 100, "playButton"));
	SDLGameObject* button2 = new MenuButton(new LoaderParams(100, 300, 400, 100, "exitButton"));

	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);

	return true;
}

bool MenuState::onExit() {
	
	for(int i = 0; i<m_gameObjects.size(); i++){
		m_gameObjects[i]->clean();
	}

	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("playButton");
	TheTextureManager::Instance()->clearFromTextureMap("exitButton");
	
	return true;
}

std::string MenuState::getStateID() const{
	return s_menuID;
}