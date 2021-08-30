#pragma once

#include "PCH.h"

class cBackground
{
public:

	cBackground();

	void drawBackground(sf::RenderWindow&);

	//void setTexture(std::string);

	//sf::Sprite getSprite();
private:

	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
};

