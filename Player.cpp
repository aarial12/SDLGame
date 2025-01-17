#include "Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams){
	
}

void Player::draw(SDL_Renderer* pRenderer) {

	SDLGameObject::draw();
}

void Player::update() {

	m_velocity.setX(0);
	m_velocity.setY(0);
	
	handleInput();

	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	
	SDLGameObject::update();	
}

void Player::handleInput() {

	if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
		m_acceleration.setX(1);
	else if (TheInputHandler::Instance()->getMouseButtonState(RIGHT))
		m_acceleration.setX(-1);
	else {
		m_acceleration.setX(0);
	}

}

void Player::clear() {

}