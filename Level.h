#pragma once

#include "PCH.h"
#include "cBranch.h"
#include "cRock.h"
#include "cPlayer.h"
#include "Diamond.h"



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

	/*method that generates 39x22 grid of random values and saves it to .txt file (NOT WORKING WELL YET)*/
	void Generate();

	/*method that takes position and returns tile*/
	Tile* GetTile(sf::Vector2f);

	/*method that takes column and row index of grid and returns Tile placed ins specific position*/
	Tile* GetTile(int columnIndex, int rowIndex);

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

	/*populates level with items*/
	void Populate();

	/*this method checks if tile at given coordinates is empty, if it is, returns true*/
	bool IsEmpty(int columnIndex, int rowIndex);

	/*this method takes tile and checks if it's empty or bush*/
	bool IsEmpty(const Tile& tile);

	/*returns the position of a tile on the screen*/
	sf::Vector2f GetTileLocation(int columnIndex, int rowIndex);

	/*this method returns random spawn location for brach or rock*/
	sf::Vector2f RandomSpawnLocation();

	/*Spawns a given item*/
	void SpawnItem(ITEM itemType, sf::Vector2f position = { -1.f, -1.f });

	/*Updates items when player reach them*/
	void UpdateItems(cPlayer& player);

	/*checks if game condition was acomplished*/
	bool GameOver();

	/*if true - game over*/
	void EndGame(bool test);

	/*Resets the A* data of all level tiles*/
	void ResetNodes();

	/*Gets tile type at given grid coordinates*/
	TILE GetTileType(int columnIndex, int rowIndex) const;


private:

	Tile m_grid[GRID_WIDTH][GRID_HEIGHT];

	std::vector<std::unique_ptr<Item>> m_items;

	sf::Texture bush;

	sf::Texture tree;
	
	sf::Texture empty;

	sf::Vector2i m_origin;

	int m_levelNum;

	cPlayer m_player;

	int winWidth;

	int winHeight;

	bool game_over;
	
};

