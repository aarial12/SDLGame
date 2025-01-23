#include "GameOverState.h"
#include "Game.h"
#include "MenuState.h"
#include "PlayState.h"
#include "MenuButton.h"
#include "PauseState.h"
#include "AnimatedGraphic.h"

const std::string GameOverState::s_gameOverID = "GAMEOVER";

void GameOverState::s_gameOverToMain() {
	TheGame::Instance()->getStateMachine()->changeState(new MenuState);
}
void GameOverState::s_restartPlay(){
	TheGame::Instance()->getStateMachine()->changeState(new PlayState);
}

void GameOverState::update() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
}

void GameOverState::render() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
}

bool GameOverState::onEnter() {

	if (!TheTextureManager::Instance()->load("Assets/gameover.png", "gameover", TheGame::Instance()->getRenderer()))
		return false;

	if (!TheTextureManager::Instance()->load("Assets/resume.png", "resume", TheGame::Instance()->getRenderer()))
		return false;

	if (!TheTextureManager::Instance()->load("Assets/main.png", "main", TheGame::Instance()->getRenderer()))
		return false;

	GameObject* gameOverText = new AnimatedGraphic(new LoaderParams(200, 100, 190, 30, "gameover"), 1);
	GameObject* resumeButton = new MenuButton(new LoaderParams(200, 200, 200, 80, "resume"), s_restartPlay);
	GameObject* mainButton = new MenuButton(new LoaderParams(200, 300, 200, 80, "main"), s_gameOverToMain);

	m_gameObjects.push_back(gameOverText);
	m_gameObjects.push_back(resumeButton);
	m_gameObjects.push_back(mainButton);

	return true;

}

bool GameOverState::onExit() {
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("player");

	SDL_Delay(100);
	return true;
}

std::string GameOverState::getStateID() const{
	return s_gameOverID;
}
