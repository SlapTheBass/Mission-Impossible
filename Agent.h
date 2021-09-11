#pragma once
#include "Entity.h"
#include "Level.h"


class Agent : public Entity
{
public:
	/*default constructor*/
	Agent();

	/*Recalculates the target position of the enemy*/
	void UpdatePathFinding(Level& level, sf::Vector2f target);

	/*moves agent to location given in in Seek method*/
	void moveAgent();

	/*moves agent to specific target*/
	void moveAgent(sf::Vector2f target);

	/*search the level for the player*/
	void Seek(Level& level, cPlayer& player);

	/*Recives orders from command unit*/
	void RecieveOrder(bool orders, int type);

	bool PlayerSeen();

	void CanChase(bool test);


private:
	sf::Texture agent;
	sf::Vector2f velocity;
	std::vector<sf::Vector2f> targetPositions;
	sf::Vector2f currentTarget;
	bool hasOrders;
	bool knowsPosition;
	int posIndex;

	sf::Vector2f diamond = { 1700, 510 };
	sf::Vector2f center = { 960, 510 };
	sf::Vector2f bot = { 800, 900 };
	sf::Vector2f topLeft = { 100, 100 };
};

