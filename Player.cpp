#include "Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams){
	
}

void Player::draw(SDL_Renderer* pRenderer) {

	SDLGameObject::draw();
}

void Player::update() {

	m_velocity.setX(0);
	m_velocity.setY(0);
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	
	handleInput();
	
	SDLGameObject::update();	
}

void Player::handleInput() {

	Vector2D* target = TheInputHandler::Instance()->getMousePosition();

	m_velocity = *target - m_position;
	m_velocity /= 50;
}

void Player::clean() {

}