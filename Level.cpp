#include "Level.h"


Level::Level(sf::RenderWindow* window) :
	m_window(*window),
	m_levelNum(1)
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
				auto& cell = m_grid[i][j];

				std::string input;

				file.get();
				input += file.get();
				file.get();

				std::stringstream convert(input);
				int tileID;
				convert >> tileID;

				cell.type = static_cast<TILE>(tileID);
				cell.sprite.setTexture();

				
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

	}
}
