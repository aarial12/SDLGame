#ifndef __GAME__  // Corrected header guard
#define __GAME__

#include <iostream>
#include <SDL.h>
#include <vector>
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "GameStateMachine.h"

class Game {

public:
    bool init(const char* title, int xpos, int ypos, int height, int width, int flags);
    void render();
    void update();
    void handleEvents();
    void clean();
    void quit() { m_bRunning = 0; }
    bool running();
    GameStateMachine* getStateMachine();
    std::vector<GameObject*> m_gameObjects;

    static Game* Instance() {
        if (s_pInstance == nullptr) {
            s_pInstance = new Game();
        }
        return s_pInstance;
    }

    SDL_Renderer* getRenderer() const { return m_pRenderer; }
    SDL_Event event;

private:

    GameStateMachine* m_pGameStateMachine;
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    bool m_bRunning;
    static Game* s_pInstance;

};

typedef Game TheGame;
#endif // __GAME__
