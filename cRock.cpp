#include "cRock.h"


cRock::cRock()
{
	rock.loadFromFile("graphics/items/spr_rock.png");
	m_type = ITEM::STONE;
	m_sprite.setTexture(rock);
}
