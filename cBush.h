
#include "cPlayer.h"


class cBush
{
public:
	cBush();

	void drawBush(sf::RenderWindow& window);

	void hidePlayer(cPlayer& player);

	float distanceBtwPts(sf::Vector2f position1, sf::Vector2f position2);

	sf::Vector2f GetPosition();

	sf::Sprite GetSprite();

	void SetPosition(sf::Vector2f position);

private:
	bool slow;

	sf::Texture bushTexture;

	sf::Sprite bushSprite;

};

