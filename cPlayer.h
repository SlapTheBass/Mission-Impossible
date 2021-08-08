#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class cPlayer{

public:
	cPlayer();

	cPlayer(std::string);

	void drawPlayer(sf::RenderWindow&);

	void playerDirection(char, float);

	void movePlayer();


private:
	sf::Texture pTexture;
	sf::Sprite pSprite;
	int i = 0;
	float interval = 20;
};

