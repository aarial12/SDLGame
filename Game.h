#ifndef __Game__
#define __Game__
#include"SDL.h"
#include <iostream>
#include <vector>
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"

class Game {

public:

	Game() {}
	~Game() {}

	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);

	void renderer();
	void update();
	void handleEvents();
	void clean();
	// a function to acces the private running variable
	bool running() { return m_bRunning; }

	int m_currentFrame;

	GameObject* m_go;
	GameObject* m_player;
	GameObject* m_enemy;
	std::vector<GameObject*> m_gameObjects;

private:

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	bool m_bRunning;

};

#endif
