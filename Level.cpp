#include "Level.h"


Level::Level(sf::RenderWindow* window) :
	m_window(*window)
{

}

bool Level::loadLevel(std::string fileName)
{
	std::ifstream file(fileName);

	if (file.is_open())
	{
		for (int j = 0; j < GRID_HEIGHT; j++)
		{
			for (int i = 0; i < GRID_WIDTH; i++)
			{
				std::string input;

				file.get();
				input += file.get();
				file.get();

				std::stringstream convert(input);
				int tileID;
				convert >> tileID;

				if (tileID == 1)
				{
					auto spr = bush.GetSprite();
					spr.setPosition(TILE_SIZE * i, TILE_SIZE * j);
					bushSprites.push_back(std::move(spr));
				}
			}
			file.get();
		}
		file.close();
	}
	else
		return false;
	
	return true;
}

void Level::drawLevel(sf::RenderWindow& window)
{
	for (auto spr : bushSprites)
	{
		window.draw(spr);
	}
}
