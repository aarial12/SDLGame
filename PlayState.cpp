#include "PlayState.h"
#include "Player.h"
#include "PauseState.h"
#include "TextureManager.h"
#include "Game.h"

const std::string PlayState::s_playID = "PLAY";

void PlayState::update() {
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
		TheGame::Instance()->getStateMachine()->pushState(new PauseState());
	}

	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
}

void PlayState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

bool PlayState::onEnter() {
	if (!TheTextureManager::Instance()->load("Assets/animate.png", "player", TheGame::Instance()->getRenderer()))
		return false;

	GameObject* player = new Player(new LoaderParams(100, 100, 128, 82, "player"));
	m_gameObjects.push_back(player);

	return true;
}

bool PlayState::onExit() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("player");

	return true;
}

std::string PlayState::getStateID() const{
	return s_playID;
}