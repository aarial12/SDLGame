#include<iostream>
#include "Game.h"

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

	if (!TheTextureManager::Instance()->load("Assets/animate.png", "animate", m_pRenderer))
		return false;

	SDL_SetRenderDrawColor(m_pRenderer, 100, 0, 0, 255);

	std::cout << "Init succes.\n";
	m_bRunning = true;

	return true;
}

void Game::renderer() {

	SDL_RenderClear(m_pRenderer);;

	TheTextureManager::Instance()->draw("animate", 0, 0, 128, 82, m_pRenderer);
	TheTextureManager::Instance()->drawFrame("animate", 100, 100, 128, 82, 1, m_currentFrame, m_pRenderer);

	SDL_RenderPresent(m_pRenderer);

}

void Game::update() {

	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));

}

void Game::handleEvents() {

	SDL_Event event;

	if (SDL_PollEvent(&event)) { //If there is any event in the event poll
		if (event.type == SDL_QUIT)
			m_bRunning = false;

	}
}

void Game::clean() {

	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}