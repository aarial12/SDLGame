#include "GameStateMachine.h"

void GameStateMachine::pushState(GameState* pState) {
	m_gameStates.push_back(pState);
	m_gameStates.back()->onEnter();
}

void GameStateMachine::popState() {
	if (!m_gameStates.empty()) {
		if (m_gameStates.back()->onExit()) {
			delete m_gameStates.back();
			m_gameStates.pop_back();
		}
	}
}

void GameStateMachine::changeState(GameState* pState) {
	if (!m_gameStates.empty()) { //Check if there are any state in the array
		if (m_gameStates.back()->getStateID() == pState->getStateID()) { //If the state is the same as the current
			return;
		}

		if (m_gameStates.back()->onExit()) { //Exit the current state
			delete m_gameStates.back(); //Remove the current state
			m_gameStates.pop_back();
		}
	}

	m_gameStates.push_back(pState); //Add the new state

	m_gameStates.back()->onEnter(); //Enter the new state
}

void GameStateMachine::update() {
	if (!m_gameStates.empty()) {
		m_gameStates.back()->update();
	}
}

void GameStateMachine::render() {
	if (!m_gameStates.empty()) {
		m_gameStates.back()->render();
	}
}