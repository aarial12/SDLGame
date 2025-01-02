#include"Game.h"

Game* g_game = 0;

int main(int argc, char* args[]) {

	g_game = new Game();

	g_game->init("Chapter 1", 100, 100, 640, 480, NULL);

	while (g_game->running()) {
		g_game->handleEvents();
		g_game->renderer();
	}
	g_game->clean();

	return 0;
}
