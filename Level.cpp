#include "Level.h"


Level::Level(sf::RenderWindow* window, cPlayer* player) :
	m_window(*window),
	m_player(*player),
	m_levelNum(1)
{
	bush.loadFromFile("graphics/tiles/spr_tree2.png");

	for (int i = 0; i < GRID_WIDTH; i++)
	{
		for (int j = 0; j < GRID_HEIGHT; j++)
		{
			auto cell = &m_grid[i][j];
			cell->columnIndex = i;
			cell->rowIndex = j;
		}
	}
}

int Level::AddTile(std::string fileName, TILE tileType)
{
	// Add the texture to the texture manager.
	int textureID = GraphicsManager::AddTexture(fileName);

	if (textureID < 0)
	{
		return -1; // Failed
	}
	else
	{
		m_textureIDs[static_cast<int>(tileType)] = textureID;
	}

	// Return the ID of the tile.
	return textureID;
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

				cell.type = tileID;

				switch (cell.type)
				{
				case 1:
					cell.sprite.setTexture(bush);
					break;
				}
				cell.sprite.setPosition(TILE_SIZE * i, TILE_SIZE * j);
				
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
	for (int i = 0; i < GRID_WIDTH; i++)
	{
		for (int j = 0; j < GRID_HEIGHT; j++)
		{
			window.draw(m_grid[i][j].sprite);
		}
	}
}


float Level::distanceBtwPts(sf::Vector2f position1, sf::Vector2f position2)
{
	return (abs(sqrt(((position1.x - position2.x) * (position1.x - position2.x)) + ((position1.y - position2.y) * (position1.y - position2.y)))));
}

void Level::hidePlayer()
{
	for (int i = 0; i < GRID_WIDTH; i++)
	{
		for (int j = 0; j < GRID_HEIGHT; j++)
		{
			auto& cell = m_grid[i][j];
			if (cell.type == 1)
			{
				if (distanceBtwPts(m_player.GetPosition(), m_grid[i][j].sprite.getPosition()) < 25.f)
				{
					m_player.Hide(true);
				}
				else
					m_player.Hide(false);
			}
		}
	}
}