#include "cBackground.h"

cBackground::cBackground(std::string imgDir) {

	if (!backgroundTexture.loadFromFile(imgDir)) {
		std::cerr << "Failed to load texture!";
	}

	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setPosition(0, 0);
}

void cBackground::drawBackground(sf::RenderWindow& window) {
	window.draw(backgroundSprite);
}
