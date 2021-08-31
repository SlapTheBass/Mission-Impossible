#pragma once

#include "PCH.h"
#include "cTree.h"
#include "cBush.h"
#include "cPlayer.h"

static int const GRID_WIDTH = 38;
static int const GRID_HEIGHT = 21;

static float const TILE_SIZE = 50;

struct Tile {
	int type;
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
	Level(sf::RenderWindow* window, cPlayer* player);

	void Generate();

	int AddTile(std::string, TILE);

	void drawLevel(sf::RenderWindow& window);

	bool loadLevel(std::string fileName);

	float distanceBtwPts(sf::Vector2f position1, sf::Vector2f position2);

	void hidePlayer();

private:
	sf::RenderWindow& m_window;

	Tile m_grid[GRID_WIDTH][GRID_HEIGHT];

	sf::Texture bush;

	std::vector<sf::Sprite> bushes;

	int m_levelNum;

	int m_textureIDs[static_cast<int>(TILE::COUNT)];

	cPlayer m_player;

	
};

