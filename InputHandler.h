#pragma once
#ifndef __INPUTHANDLER__
#define __INPUTHANDLER__	

#include <vector>
#include "Vector2D.h"

enum mouse_buttons {
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler {

public:

	static InputHandler* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new InputHandler;
		}

		return s_pInstance;
	}

	void update();
	void clean();
	bool getMouseButtonState(int buttonNumber);
	Vector2D* getMousePosition();

private:

	InputHandler();
	~InputHandler();

	static InputHandler* s_pInstance;

	std::vector<bool> m_mouseButtonStates;

	Vector2D* m_mousePosition;

};
typedef InputHandler TheInputHandler;

#endif // !__INPUTHANDLER__
