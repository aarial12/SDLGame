#include "PlayState.h"

const std::string PlayState::s_playID = "PLAY";

void PlayState::update() {

}

void PlayState::render() {

}

bool PlayState::onEnter() {
	return true;
}

bool PlayState::onExit() {
	return true;
}

std::string PlayState::getStateID() const{
	return s_playID;
}