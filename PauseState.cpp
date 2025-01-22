#include "PauseState.h"
#include "MenuState.h"
#include "MenuButton.h"
#include "Game.h"

const std::string PauseState::s_pauseID = "PAUSE";

void PauseState::s_pauseToMain() {
	TheGame::Instance()->getStateMachine()->changeState(new MenuState);
	SDL_Delay(100);
}

void PauseState::s_resumePlay() {
	TheGame::Instance()->getStateMachine()->popState();
}

void PauseState::update() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
}

void PauseState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

bool PauseState::onEnter() {
	if (!TheTextureManager::Instance()->load("Assets/resume.png", "resume", TheGame::Instance()->getRenderer()))
		return false;

	if (!TheTextureManager::Instance()->load("Assets/main.png", "main", TheGame::Instance()->getRenderer()))
		return false;

	GameObject* resumeButton = new MenuButton(new LoaderParams(200, 100, 200, 80, "resume"), s_resumePlay);
	GameObject* mainButton = new MenuButton(new LoaderParams(200, 300, 200, 80, "main"), s_pauseToMain);

	m_gameObjects.push_back(resumeButton);
	m_gameObjects.push_back(mainButton);

	return true;
}

bool PauseState::onExit() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}

	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("resume");
	TheTextureManager::Instance()->clearFromTextureMap("main");

	TheInputHandler::Instance()->reset();
	return true;
}

std::string PauseState::getStateID() const {
	return s_pauseID;
}