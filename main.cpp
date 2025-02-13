#include"Game.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* args[]) {

	Uint32 frameStart, frameTime;

	if (!TheGame::Instance()->init("Chapter 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_RESIZABLE))
		return -1;

	while (TheGame::Instance()->running()) {
		frameStart = SDL_GetTicks();

		TheGame::Instance()->handleEvents();
		TheGame::Instance()->update();
		TheGame::Instance()->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameStart < DELAY_TIME) {
			SDL_Delay((int) (DELAY_TIME - frameStart));
		}
	}

	TheGame::Instance()->clean();

	return 0;
}
