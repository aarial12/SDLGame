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

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
		m_velocity.setX(2);
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
		m_velocity.setX(-2);
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
		m_velocity.setY(-2);
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
		m_velocity.setY(2);

}

void Player::clear() {

}