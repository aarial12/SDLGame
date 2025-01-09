#include"Game.h"

Game* g_game = 0;

int main(int argc, char* args[]) {

	g_game = new Game();

	g_game->init("Chapter 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, NULL);

	while (g_game->running()) {
		g_game->update();
		g_game->handleEvents();
		g_game->renderer();
		
		SDL_Delay(10);
	}
	g_game->clean();

	return 0;
}
