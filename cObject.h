#pragma once
/*base class inherited by item, entity and projectile classes*/
#include "PCH.h"

class cObject
{
public:
	/*default constructor*/
	cObject();

	/*gets position of sprite of an object and returns it as Vector2 of floats*/
	sf::Vector2f GetPosition();

	/*sets position of an object by given Vector2 of floats*/
	void SetPosition(sf::Vector2f);

protected:
	sf::Sprite m_sprite;

	sf::Vector2f m_position;
};

