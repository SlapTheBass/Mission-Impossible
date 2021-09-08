#pragma once
/*class for drawing background on screen*/
#include "PCH.h"

class cBackground
{
public:
	/*default constructor*/
	cBackground();

	/*draw backgtound on game window - this method will draw basic grass tile on whole screen*/
	void drawBackground(sf::RenderWindow&);

private:
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
};

