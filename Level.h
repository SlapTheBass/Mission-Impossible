#pragma once

#include "PCH.h"
#include "cPlayer.h"

static int const GRID_WIDTH = 39;
static int const GRID_HEIGHT = 22;

static float const TILE_SIZE = 50;

/*struct that describes every single tile drawn on screen*/
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
	/*parametrized constructor which takes game window as an argument*/
	Level(sf::RenderWindow& window);

	/*method that generates 39x22 table of random values and saves it to .txt file (NOT WORKING WELL YET)*/
	void Generate();

	/*method that takes position and returns tile*/
	Tile* GetTile(sf::Vector2f);

	sf::Vector2f GetTilePos(int columnIndex, int rowIndex);

	/*drawing all tiles on game window*/
	void drawLevel(sf::RenderWindow& window);

	/*loads level data from .txt file and converts values to tile types*/
	bool loadLevel(std::string fileName);

	/*returns distance between points given by 2 vectors*/
	float distanceBtwPts(sf::Vector2f position1, sf::Vector2f position2);

	/*sets hide parameter of cPlayer to TRUE*/
	void hidePlayer(cPlayer&);

	/*collision handling*/
	void playerCollision(cPlayer&);

private:

	Tile m_grid[GRID_WIDTH][GRID_HEIGHT];

	sf::Texture bush;

	sf::Texture tree;

	sf::Vector2i m_origin;

	int m_levelNum;

	int m_textureIDs[static_cast<int>(TILE::COUNT)];

	cPlayer m_player;

	int winWidth;

	int winHeight;
	
};

