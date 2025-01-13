#include"Game.h"


int main(int argc, char* args[]) {

	if (!TheGame::Instance()->init("Chapter 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, NULL))
		return -1;

	while (TheGame::Instance()->running()) {
		TheGame::Instance()->handleEvents();
		TheGame::Instance()->update();
		TheGame::Instance()->render();

		SDL_Delay(10);
	}

	TheGame::Instance()->clean();

	return 0;
}
