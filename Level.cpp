#include "Level.h"


Level::Level(sf::RenderWindow& window)
{
	bush.loadFromFile("graphics/tiles/spr_bush.png");
	tree.loadFromFile("graphics/tiles/spr_tree.png");

	m_origin.x = (window.getSize().x - (GRID_WIDTH * TILE_SIZE));
	m_origin.y = (window.getSize().y - (GRID_HEIGHT * TILE_SIZE));

	winWidth = (window.getSize().x);
	winHeight = (window.getSize().y);

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

void Level::Generate()
{
	std::ofstream file;

	file.open("levelData.txt");

	int random_data;

	for (int i = 0; i <= 857; i++)
	{
		random_data = rand() % 3;

		file << random_data << ' ';

		if ((i + 1) % 39 == 0)
		{
			file << '\n';
		}
	}
	file.close();
}

bool Level::loadLevel(std::string fileName)
{
	std::ifstream file(fileName);

	if (file.is_open())
	{
		for (int j = 0; j < GRID_HEIGHT; ++j)
		{
			for (int i = 0; i < GRID_WIDTH; ++i)
			{
				auto& cell = m_grid[i][j];

				std::string input;

				input += file.get();
				file.get();

				std::stringstream convert(input);
				int tileID;
				convert >> tileID;

				cell.type = static_cast<TILE>(tileID);

				switch (cell.type)
				{
				case TILE::BUSH:
					cell.sprite.setTexture(bush);
					break;

				case TILE::TREE:
					cell.sprite.setTexture(tree);
					cell.sprite.setOrigin(-3, 30);
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

void Level::hidePlayer(cPlayer& player)
{
	Tile& playerTile = *GetTile(player.GetPosition());

	if (playerTile.type == TILE::BUSH)
	{
		player.Hide(true);
	}
	else
		player.Hide(false);
}

void Level::playerCollision(cPlayer& player)
{
	Tile& playerTile = *GetTile(player.GetPosition());
	Tile& lowerTile = *GetTile({ player.GetPosition().x, player.GetPosition().y + 70.f });
	Tile& nextTile = *GetTile({ player.GetPosition().x + 15.f, player.GetPosition().y + 50.f});
	Tile& previousTile = *GetTile({player.GetPosition().x - 15.f, player.GetPosition().y + 50.f });

	if (playerTile.type == TILE::TREE)
	{
		if (player.GetPosition().y - playerTile.sprite.getPosition().y < 10.f)
		{
			player.SetPosition({ player.GetPosition().x, playerTile.sprite.getPosition().y});
		}
	}
	else if (lowerTile.type == TILE::TREE)
	{
		if (playerTile.sprite.getPosition().y - lowerTile.sprite.getPosition().y < 0.f)
		{
			player.SetPosition({ player.GetPosition().x, (lowerTile.sprite.getPosition().y - lowerTile.sprite.getLocalBounds().height - 15.f) });
		}
	}
	else if (nextTile.type == TILE::TREE)
	{
		if (playerTile.sprite.getPosition().x - nextTile.sprite.getPosition().x < 15.f)
		{
			player.SetPosition({ playerTile.sprite.getPosition().x - 55.f + nextTile.sprite.getLocalBounds().width, player.GetPosition().y });
		}
	}
	else if (previousTile.type == TILE::TREE)
	{
		if (playerTile.sprite.getPosition().x - (previousTile.sprite.getPosition().x + previousTile.sprite.getLocalBounds().width) < 15.f)
			{
				player.SetPosition({ playerTile.sprite.getPosition().x - previousTile.sprite.getLocalBounds().width + 40.f, player.GetPosition().y });
			}
	}
	else if (player.GetPosition().x < 1.f)
	{
		player.SetPosition({ 1.f, player.GetPosition().y });
	}
	else if (player.GetPosition().y < 0)
	{
		player.SetPosition({ player.GetPosition().x, 0 });
	}
	else if (player.GetPosition().x > winWidth - 44.f)
	{
		player.SetPosition({ (float)winWidth - 44.f, player.GetPosition().y });
	}
	else if (player.GetPosition().y  > winHeight - 84.f)
	{
		player.SetPosition({ player.GetPosition().x, (float)winHeight - 84.f });
	}
	else
		player.SetPosition(player.GetPosition());
}

Tile* Level::GetTile(sf::Vector2f position)
{
	position.x -= m_origin.x;
	position.y -= m_origin.y;

	int tileColumn, tileRow;

	tileColumn = (static_cast<int>(position.x) / TILE_SIZE);
	tileRow = (static_cast<int>(position.y) / TILE_SIZE);

	return &m_grid[tileColumn][tileRow];
}

sf::Vector2f Level::GetTilePos(int columnIndex, int rowIndex)
{
	return m_grid[columnIndex][rowIndex].sprite.getPosition();
}

