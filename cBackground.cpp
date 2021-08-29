#include "PCH.h"

sf::Clock clkB;

cBackground::cBackground()
{
}


void cBackground::drawBackground(sf::RenderWindow& window)
{
    backgroundTexture.loadFromFile("graphics/tiles/spr_grass.png");
    backgroundSprite.setTexture(backgroundTexture);

    std::vector<sf::Sprite> backgroundSpr;

    for (float i = 0; i <= window.getSize().x; i += 49.5)
    {
        for (float j = 0; j <= window.getSize().y; j += 49.5)
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
