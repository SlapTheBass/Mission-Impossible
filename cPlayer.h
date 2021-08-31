#pragma once

#include "PCH.h"

class cPlayer{

public:
	cPlayer();

	void drawPlayer(sf::RenderWindow&);

	void playerDirection(char, float);

	void setSpeed(float);

	sf::Sprite isHidden();

	bool Hide(bool);

	sf::Vector2f GetPosition();

	void Slow();

	void movePlayer();

	bool isThrowing();

	sf::Sprite& getAimSprite();

	bool canBeChased();


private:
	sf::Texture pTexture;
	sf::Sprite pSprite;
	int i = 0;
	float interval = 20;
	float speed = 12.2;
	bool slow;
	bool hide = false;
};

