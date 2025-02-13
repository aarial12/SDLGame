#include "InputHandler.h"
#include "Game.h"

InputHandler* InputHandler::s_pInstance = 0;
Vector2D* m_mousePosition = 0;
const Uint8* m_keystate = SDL_GetKeyboardState(0);

InputHandler::InputHandler() {
	for (int i = 0; i < 3; i++)
		m_mouseButtonStates.push_back(false);

	m_mousePosition = new Vector2D(0, 0);
}

void InputHandler::update() {
	
	SDL_Event event;
	while (SDL_PollEvent(&event)) {

		switch (event.type) {
		case	SDL_QUIT:
			TheGame::Instance()->quit();
			break;

		case	SDL_MOUSEMOTION:
			onMouseMove(event);
			break;

		case	SDL_MOUSEBUTTONDOWN:
			onMouseButtonDown(event);
			break;

		case	SDL_MOUSEBUTTONUP:
			onMouseButtonUp(event);
			break;

		case	SDL_KEYDOWN:
			onKeyDown();
			break;

		case	SDL_SCANCODE_ESCAPE:


		default:
			break;
		}
	}
	
}

void InputHandler::onMouseButtonDown(SDL_Event& event) {

	if (event.type == SDL_MOUSEBUTTONDOWN) {
			if (event.button.button == SDL_BUTTON_LEFT)
				m_mouseButtonStates[LEFT] = true;
			if (event.button.button == SDL_BUTTON_MIDDLE)
				m_mouseButtonStates[MIDDLE] = true;
			if (event.button.button == SDL_BUTTON_RIGHT)
				m_mouseButtonStates[RIGHT] = true;
	}
}

void InputHandler::onMouseButtonUp(SDL_Event& event) {
	if (event.type == SDL_MOUSEBUTTONUP) {
		if (event.button.button == SDL_BUTTON_LEFT)
			m_mouseButtonStates[LEFT] = false;
		if (event.button.button == SDL_BUTTON_MIDDLE)
			m_mouseButtonStates[MIDDLE] = false;
		if (event.button.button == SDL_BUTTON_RIGHT)
			m_mouseButtonStates[RIGHT] = false;
	}
}

void InputHandler::onMouseMove(SDL_Event& event) {
		if (event.type == SDL_MOUSEMOTION) {
			m_mousePosition->setX(event.motion.x);
			m_mousePosition->setY(event.motion.y);
		}
}

bool InputHandler::isKeyDown(SDL_Scancode key) {
	
	if (m_keystate != 0) {
		if (m_keystate[key] == 1)
			return true;
		else
		{

		}
			return false;
	}

	return false;
}

void InputHandler::onKeyDown() {
	m_keystate = SDL_GetKeyboardState(0);
}

bool InputHandler::getMouseButtonState(int buttonNumber) {
	return m_mouseButtonStates[buttonNumber];
}

Vector2D* InputHandler::getMousePosition() {
	return m_mousePosition;
}

void InputHandler::reset() {
	for (int i = 0; i < 3; i++)
		m_mouseButtonStates.push_back(false);
}

InputHandler::~InputHandler(){}