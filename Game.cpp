#include<iostream>
#include "Game.h"

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

	if (!TheTextureManager::Instance()->load("Assets/animate.png", "animate", m_pRenderer))
		return false;


	m_gameObjects.push_back(new Player (new LoaderParams(100, 100, 128, 82, "animate")));
	m_gameObjects.push_back(new Enemy (new LoaderParams(200, 200, 128, 82, "animate")));

	SDL_SetRenderDrawColor(m_pRenderer, 100, 0, 0, 255);

	std::cout << "Init succes.\n";
	m_bRunning = true;

	return true;
}


void Game::render() {

	SDL_RenderClear(m_pRenderer);
	

	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
		m_gameObjects[i]->draw();
	}
	SDL_SetRenderDrawColor(TheGame::Instance()->getRenderer(), 100, 200, 0, 255);
	SDL_RenderDrawRect(TheGame::Instance()->getRenderer(), &terrain);
	SDL_RenderFillRect(TheGame::Instance()->getRenderer() , &terrain);
	SDL_SetRenderDrawColor(TheGame::Instance()->getRenderer(), 0, 0, 0, 255);
	

	SDL_RenderPresent(TheGame::Instance()->getRenderer());

}

void Game::update() {


	SDL_GetWindowSize(m_pWindow, &w,
		NULL);

	terrain.w = w;
	for (std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}

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

bool Game::running() {
	return m_bRunning;
}