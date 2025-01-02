#include<iostream>
#include<SDL.h>
#include"Game.h"

SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;
bool g_bRunning;

void init() {
	
}

void render() {
}

void update() {}

void handeEvents(){}

void clean(){}

int main(int argc, char* args[]) {

	init();

	while (g_bRunning) {
		handeEvents();
		update();
		render();
	}

	clean();

	return 0;
}
