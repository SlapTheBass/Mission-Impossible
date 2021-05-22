#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class cBackground{

public:

	cBackground();

	cBackground(std::string);

	void drawBackground(sf::RenderWindow&);

private:

	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
};

