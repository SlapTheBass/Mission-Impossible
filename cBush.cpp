#include "cBush.h"

cBush::cBush()
{
	if (!bushTexture.loadFromFile("graphics/tiles/spr_bush.png")) {
		std::cerr << "Texture loading fail\n";
	}

	bushSprite.setTexture(bushTexture);
}

sf::Vector2f cBush::GetPosition()
{
	return bushSprite.getPosition();
}

sf::Sprite cBush::GetSprite()
{
	return bushSprite;
}

void cBush::SetPosition(sf::Vector2f position)
{
	bushSprite.setPosition(position.x, position.y);
}

float cBush::distanceBtwPts(sf::Vector2f position1, sf::Vector2f position2)
{
	return (abs(sqrt(((position1.x - position2.x) * (position1.x - position2.x)) + ((position1.y - position2.y) * (position1.y - position2.y)))));
}

void cBush::hidePlayer(cPlayer& player)
{
	if (distanceBtwPts(player.GetPosition(), GetPosition()) < 25.f)
	{
		player.Hide(true);
	}
	else
		player.Hide(false);
}

void cBush::drawBush(sf::RenderWindow& window)
{
	window.draw(bushSprite);
}