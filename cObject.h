#pragma once

#include "PCH.h"

class cObject
{
public:
	cObject();

	sf::Vector2f GetPosition();

	virtual void Draw(sf::RenderWindow& window);

	void SetPosition(sf::Vector2f);

	void SetSprite(sf::Texture&);

	sf::Sprite& GetSprite();

protected:
	sf::Sprite m_sprite;

	sf::Vector2f m_position;
};

