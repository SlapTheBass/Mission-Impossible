#include "cPlayer.h"

cPlayer::cPlayer(std::string imgDir){//expanded constructor -> object is created from texture file direction

	if(!pTexture.loadFromFile(imgDir)){
		std::cerr << "Texture loading fail\n";
	}
	pSprite.setTexture(pTexture);
	sf::IntRect basic(657, 1226, 32, 53);
	pSprite.setTextureRect(basic);
	pSprite.setPosition(900, 510);
}

void cPlayer::drawPlayer(sf::RenderWindow& window){
	window.draw(pSprite);
}

void cPlayer::playerDirection(char dir, float velocity){

	if (dir == 'u') {//if direction is 'up'
		pSprite.move(0, -velocity); //move player sprite up
		sf::IntRect pRect(16, 523, 32, 53); //create rectangle with given parameters (crdx, crdy, width, heigth)
		pSprite.setTextureRect(pRect); //cut rectangle from texture
	} else 	if (dir == 'd') {
		pSprite.move(0, velocity);
		sf::IntRect pRect(16, 396, 32, 53);
		pSprite.setTextureRect(pRect);
	} else 	if (dir == 'l') {
		pSprite.move(-velocity, 0);
		sf::IntRect pRect(16, 331, 32, 53);
		pSprite.setTextureRect(pRect);
	} else 	if (dir == 'r') {
		pSprite.move(velocity, 0);
		sf::IntRect pRect(16, 460, 32, 53);
		pSprite.setTextureRect(pRect);
	} else {
		sf::IntRect pRect(16, 460, 32, 53);
		pSprite.setTextureRect(pRect);
	}
}

void cPlayer::movePlayer() {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		playerDirection('u', 7.1);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		playerDirection('d', 7.1);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		playerDirection('l', 7.1);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		playerDirection('r', 7.1);
	}
}