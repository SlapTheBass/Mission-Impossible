#pragma once
#include "PCH.h"
#include "cPlayer.h"
#include "Entity.h"
#include "cBackground.h"
#include "Level.h"
#include "Agent.h"
#include "Command.h"


class GameEngine
{
public:
	/*default constructor*/
	GameEngine();

	/*Constructor - takes a pointer to the main renderwindow*/
	GameEngine(sf::RenderWindow& window);

	/*Initialazes the game object by initialazing all objects that game uses*/
	void Initialize();

	/*Main game loop. Loop runs the game and draws all objects to screen*/
	void Run(sf::RenderWindow& window);

	/*Draws all objects on the game window*/
	void Draw(sf::RenderWindow& window);

private:
	/*moves all objects*/
	void MoveObjects();

	/*updates all game objects*/
	void Update();


private:
	sf::Music music;

	sf::Clock timer;

	std::unique_ptr<Level> level;

	cPlayer player;

	cBackground background;

	Agent agent1, agent2, agent3, agent4, agent5;
};

