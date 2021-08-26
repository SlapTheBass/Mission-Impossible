#include "PCH.h"

cBackground::cBackground(std::string dir1, std::string dir2) {

	int sw = rand() % 2 + 1;
	
	switch (sw)
	{
	case 1:
		backgroundTexture.loadFromFile(dir1);
		break;

	case 2:
		backgroundTexture.loadFromFile(dir2);
		break;
	}

	if (!backgroundTexture.loadFromFile(dir1) && !backgroundTexture.loadFromFile(dir2)) {
		std::cerr << "Failed to load texture!";
	}
	
	backgroundSprite.setTexture(backgroundTexture);

}

void cBackground::drawBackground(sf::RenderWindow& window) {
	window.draw(backgroundSprite);
}

sf::Sprite cBackground::getBgrSprite()
{
	return backgroundSprite;
}
