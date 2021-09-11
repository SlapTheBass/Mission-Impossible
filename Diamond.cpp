#include "Diamond.h"

Diamond::Diamond()
{
	diamond.loadFromFile("graphics/items/spr_diamond.png");
	m_type = ITEM::DIAMOND;
	m_sprite.setTexture(diamond);
	m_sprite.setScale(0.5, 0.5);
}