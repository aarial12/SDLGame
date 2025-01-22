#include<iostream>
#include "Game.h"
#include "InputHandler.h"
#include "MenuState.h"
#include "PlayState.h"

Game* Game::s_pInstance = 0;


bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags) {

	if (SDL_Init(SDL_INIT_EVERYTHING)) {
		std::cout << "SDL init fail\n";
		return false;
	}

	m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

	if (m_pWindow == NULL){
		std::cout << "Failed to create the window.\n";
		return false;
	}

	m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, NULL);

	if (m_pRenderer == NULL) {
		std::cout << "Failed to create the renderer.\n";
		return false;
	}

	m_pGameStateMachine = new GameStateMachine();
	m_pGameStateMachine->changeState(new MenuState());

	SDL_SetRenderDrawColor(m_pRenderer, 0, 50, 50, 255);

	m_bRunning = true;

	return true;
}


void Game::render() {

	SDL_RenderClear(m_pRenderer);
	
	m_pGameStateMachine->render();

	SDL_RenderPresent(m_pRenderer);

}	

void Game::update() {
	m_pGameStateMachine->update();
}

void Game::handleEvents() {

	TheInputHandler::Instance()->update();

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN)) {
		m_pGameStateMachine->changeState(new PlayState());
	}

}

void Game::clean() {

	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

bool Game::running() {
	return m_bRunning;
}

GameStateMachine* Game::getStateMachine() { 
	return m_pGameStateMachine; 
}