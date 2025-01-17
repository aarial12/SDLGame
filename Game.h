#ifndef __GAME__
#define __GAME__

#include <iostream>
#include <SDL.h>
#include <vector>
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"

class Game
{
public:

	bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
	void render();
	void update();
	void handleEvents();
	void clean();
	void quit() { m_bRunning = 0; }
	bool running();

	std::vector<GameObject*> m_gameObjects;

	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}

	SDL_Renderer* getRenderer() const { return m_pRenderer; }

	SDL_Event event;

private:

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	int w;

	SDL_Rect terrain{ 0, 400, 500, 50 };

	bool m_bRunning;
	static Game* s_pInstance;
};

typedef Game TheGame;
#endif // !__GAME__
