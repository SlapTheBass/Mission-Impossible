#include "cBackground.h"

cBackground::cBackground()
{
}


void cBackground::drawBackground(sf::RenderWindow& window)
{
    backgroundTexture.loadFromFile("graphics/tiles/spr_grass.png");
    backgroundSprite.setTexture(backgroundTexture);

    std::vector<sf::Sprite> backgroundSpr;

    for (float i = 0; i <= window.getSize().x; i += 50)
    {
        for (float j = 0; j <= window.getSize().y; j += 50)
        {
            backgroundSprite.setPosition(i, j);
            backgroundSpr.push_back(std::move(backgroundSprite));
        }
    }

    for (const auto spr : backgroundSpr)
    {
        window.draw(spr);
    }
}
