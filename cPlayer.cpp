#include "cPlayer.h"

sf::Clock clk;

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

	int frameX = 0;
	int frameY = 64;
	int width = 64;
	int height = 64;


		if (dir == 'u') {//if direction is 'up'
			pSprite.move(0, -velocity); 
			if (clk.getElapsedTime().asMilliseconds() >= interval) {
				clk.restart();
				if (i == 0) {
					pSprite.setTextureRect({ 0, 512, width, height });
					i++;
				}
				else if (i == 1) {
					pSprite.setTextureRect({ 64, 512, width, height });
					i++;
				}
				else if (i == 2) {
					pSprite.setTextureRect({ 128, 512, width, height });
					i++;
				}
				else if (i == 3) {
					pSprite.setTextureRect({ 192, 512, width, height });
					i++;
				}
				else if (i == 4) {
					pSprite.setTextureRect({ 256, 512, width, height });
					i++;
				}
				else if (i == 5) {
					pSprite.setTextureRect({ 320, 512, width, height });
					i++;
				}
				else if (i == 6) {
					pSprite.setTextureRect({ 384, 512, width, height });
					i++;
				}
				else if (i == 7) {
					pSprite.setTextureRect({ 448, 512, width, height });
					i++;
				}
				else if (i == 8) {
					pSprite.setTextureRect({ 512, 512, width, height });
					i = 0;
				}
				else {
					i = 0;
				}
			}
		} else 	if (dir == 'd') {
			pSprite.move(0, velocity);
			if (clk.getElapsedTime().asMilliseconds() >= interval) {
				clk.restart();
				if (i == 0) {
					pSprite.setTextureRect({ 0, 640, width, height });
					i++;
				}
				else if (i == 1) {
					pSprite.setTextureRect({ 64, 640, width, height });
					i++;
				}
				else if (i == 2) {
					pSprite.setTextureRect({ 128, 640, width, height });
					i++;
				}
				else if (i == 3) {
					pSprite.setTextureRect({ 192, 640, width, height });
					i++;
				}
				else if (i == 4) {
					pSprite.setTextureRect({ 256, 640, width, height });
					i++;
				}
				else if (i == 5) {
					pSprite.setTextureRect({ 320, 640, width, height });
					i++;
				}
				else if (i == 6) {
					pSprite.setTextureRect({ 384, 640, width, height });
					i++;
				}
				else if (i == 7) {
					pSprite.setTextureRect({ 448, 640, width, height });
					i++;
				}
				else if (i == 8) {
					pSprite.setTextureRect({ 512, 640, width, height });
					i = 0;
				}
				else {
					i = 0;
				}
			}
		} else 	if (dir == 'l') {
			pSprite.move(-velocity, 0);
			if (clk.getElapsedTime().asMilliseconds() >= interval) {
				clk.restart();
				if (i == 0) {
					pSprite.setTextureRect({ 0, 576, width, height });
					i++;
				}
				else if (i == 1) {
					pSprite.setTextureRect({ 64, 576, width, height });
					i++;
				}
				else if (i == 2) {
					pSprite.setTextureRect({ 128, 576, width, height });
					i++;
				}
				else if (i == 3) {
					pSprite.setTextureRect({ 192, 576, width, height });
					i++;
				}
				else if (i == 4) {
					pSprite.setTextureRect({ 256, 576, width, height });
					i++;
				}
				else if (i == 5) {
					pSprite.setTextureRect({ 320, 576, width, height });
					i++;
				}
				else if (i == 6) {
					pSprite.setTextureRect({ 384, 576, width, height });
					i++;
				}
				else if (i == 7) {
					pSprite.setTextureRect({ 448, 576, width, height });
					i++;
				}
				else if (i == 8) {
					pSprite.setTextureRect({ 512, 576 , width, height });
					i = 0;
				}
				else {
					i = 0;
				}
			}
		} else 	if (dir == 'r') {
			pSprite.move(velocity, 0);
			if (clk.getElapsedTime().asMilliseconds() >= interval) {
				clk.restart();
				if (i == 0) {
					pSprite.setTextureRect({ 0, 704, width, height });
					i++;
				}
				else if (i == 1) {
					pSprite.setTextureRect({ 64, 704, width, height });
					i++;
				}
				else if (i == 2) {
					pSprite.setTextureRect({ 128, 704, width, height });
					i++;
				}
				else if (i == 3) {
					pSprite.setTextureRect({ 192, 704, width, height });
					i++;
				}
				else if (i == 4) {
					pSprite.setTextureRect({ 256, 704, width, height });
					i++;
				}
				else if (i == 5) {
					pSprite.setTextureRect({ 320, 704, width, height });
					i++;
				}
				else if (i == 6) {
					pSprite.setTextureRect({ 384, 704, width, height });
					i++;
				}
				else if (i == 7) {
					pSprite.setTextureRect({ 448, 704, width, height });
					i++;
				}
				else if (i == 8) {
					pSprite.setTextureRect({ 512, 704, width, height });
					i = 0;
				}
				else {
					i = 0;
				}
			}	
		} else {
			pSprite.setTextureRect({ 0, 448, width, height });
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
	} else {
		playerDirection('x', 0);
	}
}