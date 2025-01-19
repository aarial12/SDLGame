#include "InputHandler.h"
#include "Game.h"

InputHandler* InputHandler::s_pInstance = 0;
Vector2D* m_mousePosition = 0;

InputHandler::InputHandler() {
	for (int i = 0; i < 3; i++)
		m_mouseButtonStates.push_back(false);

	m_mousePosition = new Vector2D(0, 0);
}

void InputHandler::update() {
	
	SDL_Event event;

	while (SDL_PollEvent(&event)) {

		if (event.type == SDL_QUIT)
			TheGame::Instance()->quit();

		if (event.type == SDL_MOUSEBUTTONDOWN) {

			if (event.button.button == SDL_BUTTON_LEFT)
				m_mouseButtonStates[LEFT] = true;
			if (event.button.button == SDL_BUTTON_MIDDLE)
				m_mouseButtonStates[MIDDLE] = true;
			if (event.button.button == SDL_BUTTON_RIGHT)
				m_mouseButtonStates[RIGHT] = true;
		}

		if (event.type == SDL_MOUSEBUTTONUP) {
			if (event.button.button == SDL_BUTTON_LEFT)
				m_mouseButtonStates[LEFT] = false;
			if (event.button.button == SDL_BUTTON_MIDDLE)
				m_mouseButtonStates[MIDDLE] = false;
			if (event.button.button == SDL_BUTTON_RIGHT)
				m_mouseButtonStates[RIGHT] = false;
		}

		if (event.type == SDL_MOUSEMOTION) {
			m_mousePosition->setX(event.motion.x);
			m_mousePosition->setY(event.motion.y);
		}

	}
	
}

bool InputHandler::getMouseButtonState(int buttonNumber) {
	return m_mouseButtonStates[buttonNumber];
}

Vector2D* InputHandler::getMousePosition() {
	return m_mousePosition;
}

InputHandler::~InputHandler(){}