#include "cBush.h"


cBush::cBush()
{
	if (!bushTexture.loadFromFile("graphics/tiles/spr_bush.png")) {
		std::cerr << "Texture loading fail\n";
	}

	bushSprite.setTexture(bushTexture);
	bushSprite.setScale(1.3, 1.3);
	bushSprite.setPosition(900, 500);
}

sf::Vector2f cBush::GetPosition()
{
	return bushSprite.getPosition();
}

float cBush::distanceBtwPts(sf::Vector2f position1, sf::Vector2f position2)
{
	return (abs(sqrt(((position1.x - position2.x) * (position1.x - position2.x)) + ((position1.y - position2.y) * (position1.y - position2.y)))));
}

void cBush::hidePlayer(cPlayer& player)
{
	if (distanceBtwPts(player.GetPosition(), GetPosition()) < 45.f)
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