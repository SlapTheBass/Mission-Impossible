#include "cObject.h"

cObject::cObject() :
	m_position({ 0.f, 0.f })
{
}


void cObject::SetPosition(sf::Vector2f position)
{
	m_position.x = position.x;
	m_position.y = position.y;

	m_sprite.setPosition(position.x, position.y);
}

sf::Vector2f cObject::GetPosition()
{
	return m_position;
}