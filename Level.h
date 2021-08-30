#pragma once

#include "PCH.h"
#include "cTree.h"
#include "cBush.h"

static int const GRID_WIDTH = 38;
static int const GRID_HEIGHT = 21;

static float const TILE_SIZE = 50;

struct Tile {
	TILE type;
	int columnIndex;
	int rowIndex;
	sf::Sprite sprite;
	int H;
	int G;
	int F;
	Tile* parentNode;
};

class Level
{
public:
	Level(sf::RenderWindow* window);

	void Generate();

	void drawLevel(sf::RenderWindow& window);

	bool loadLevel(std::string fileName);

private:
	sf::RenderWindow& m_window;

	Tile m_grid[GRID_WIDTH][GRID_HEIGHT];

	cBush bush;

	std::vector<sf::Sprite> bushSprites;

	int m_levelNum;

	int m_textureIDs[static_cast<int>(TILE::COUNT)];

	
};

