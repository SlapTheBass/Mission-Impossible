#include "Level.h"

Level::Level()
{
}

Level::Level(sf::RenderWindow& window)
{
	bush.loadFromFile("graphics/tiles/spr_bush.png");
	tree.loadFromFile("graphics/tiles/spr_tree.png");
	empty.loadFromFile("graphics/tiles/spr_grass_alt.png");
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

void Level::Generate() //DO NOT USE YET
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
		for (int j = 0; j < GRID_HEIGHT; j++)
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
					break;

				default:
					cell.type = TILE::EMPTY;
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
	for (auto const& item : m_items)
	{
		item->Draw(window);
	}

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
	Tile& topTile = *GetTile(playerTile.columnIndex, playerTile.rowIndex - 1);
	Tile& botTile = *GetTile(playerTile.columnIndex, playerTile.rowIndex + 1);
	Tile& rigTile = *GetTile(playerTile.columnIndex + 1, playerTile.rowIndex);
	Tile& lefTile = *GetTile(playerTile.columnIndex - 1, playerTile.rowIndex);

	if (topTile.type == TILE::TREE)
	{
		if (player.GetPosition().y - topTile.sprite.getPosition().y < 40.f)
		{
			player.SetPosition({ player.GetPosition().x, playerTile.sprite.getPosition().y - 5.f});
		}
	}
	else if (botTile.type == TILE::TREE)
	{
		if (botTile.sprite.getPosition().y - player.GetPosition().y < 40.f)
		{
			player.SetPosition({ player.GetPosition().x, playerTile.sprite.getPosition().y });
		}
	}
	else if (rigTile.type == TILE::TREE)
	{
		if (rigTile.sprite.getPosition().x - player.GetPosition().x < 40.f)
		{
			player.SetPosition({playerTile.sprite.getPosition().x , player.GetPosition().y });
		}
	}
	else if (lefTile.type == TILE::TREE)
	{
		if (player.GetPosition().x - lefTile.sprite.getPosition().x < 40.f)
			{
				player.SetPosition({ playerTile.sprite.getPosition().x , player.GetPosition().y });
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

Tile* Level::GetTile(int columnIndex, int rowIndex)
{
	return &m_grid[columnIndex][rowIndex];
}

bool Level::IsEmpty(int columnIndex, int rowIndex)
{
	Tile* tile = &m_grid[columnIndex][rowIndex];

	return (tile->type == TILE::EMPTY);
}

bool Level::IsEmpty(const Tile& tile)
{
	return (tile.type == TILE::EMPTY);
}

sf::Vector2f Level::GetTileLocation(int columnIndex, int rowIndex)
{
	sf::Vector2f location;

	location.x = m_origin.x + (columnIndex * TILE_SIZE) + (TILE_SIZE / 2);
	location.y = m_origin.y + (rowIndex * TILE_SIZE) + (TILE_SIZE / 2);

	return location;
}

sf::Vector2f Level::RandomSpawnLocation()
{
	int rowIndex(0), columnIndex(0);

	while (!IsEmpty(columnIndex, rowIndex))
	{
		columnIndex = std::rand() % GRID_WIDTH;
		rowIndex = std::rand() % GRID_HEIGHT;
	}

	sf::Vector2f randLocation(GetTileLocation(columnIndex, rowIndex));

	randLocation.x += std::rand() % 21 - 10;
	randLocation.y += std::rand() % 21 - 10;

	return randLocation;
}

void Level::SpawnItem(ITEM itemType, sf::Vector2f position)
{
	std::unique_ptr<Item> item;

	int itemIndex = 0;

	sf::Vector2f spawnLocation;

	if ((position.x >= 0.f) || (position.y >= 0.f))
	{
		spawnLocation = position;
	}
	else
	{
		spawnLocation = RandomSpawnLocation();
	}

	switch (itemType)
	{
	case ITEM::BRANCH :
		item = std::make_unique<cBranch>();
		break;

	case ITEM::STONE :
		item = std::make_unique<cRock>();
		break;

	case ITEM::DIAMOND :
		item = std::make_unique<Diamond>();
		break;
	}

	item->SetPosition(spawnLocation);

	m_items.push_back(std::move(item));
}

void Level::Populate()
{
	for (int i = 0; i < 25; i++)
	{

		SpawnItem(static_cast<ITEM>(std::rand() % 2));

	}

	SpawnItem(ITEM::DIAMOND, { 1800, 510 });
}

void Level::UpdateItems(cPlayer& player)
{
	auto itemIterator = m_items.begin();
	while (itemIterator != m_items.end())
	{
		Item& item = **itemIterator;
		if (distanceBtwPts(item.GetPosition(), player.GetPosition()) < 35.f)
		{
			switch (item.GetType())
			{

			case ITEM::DIAMOND:
				game_over = true;
				break;

			case ITEM::BRANCH :
				player.SetSlow(true);
				break;

			case ITEM::STONE :
				cRock& rock = dynamic_cast<cRock&>(item);
				player.SetSlip(true);
				break;


			}

			itemIterator = m_items.erase(itemIterator);
		}
		else
		{
			++itemIterator;
		}
	}
}

void Level::EndGame(bool test)
{
	game_over = test;
}

bool Level::GameOver()
{
	return game_over;
}

void Level::ResetNodes()
{
	for (int i = 0; i < GRID_WIDTH; ++i)
	{
		for (int j = 0; j < GRID_HEIGHT; ++j)
		{
			m_grid[i][j].parentNode = nullptr;
			m_grid[i][j].H = 0;
			m_grid[i][j].F = 0;
			m_grid[i][j].G = 0;
		}
	}
}

TILE Level::GetTileType(int columnIndex, int rowIndex) const
{
	if ((columnIndex >= GRID_WIDTH) || (rowIndex >= GRID_HEIGHT))
	{
		return TILE::EMPTY;
	}

	return m_grid[columnIndex][rowIndex].type;
}

