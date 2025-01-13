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
	
	static Game* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}
		
	
	~Game() {}

	SDL_Renderer* getRenderer() const { return m_pRenderer; }

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

	Game() {}
	static Game* s_pInstance;

	typedef Game TheGame;

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	bool m_bRunning;

};

#endif
