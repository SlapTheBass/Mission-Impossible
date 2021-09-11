#pragma once
/*Rocks should be helpful for player. Collecting them increases
  ammo and player can slow down or mislead agents
*/
#include "Item.h"

class cRock : public Item
{
public:

	/*default constructor*/
	cRock();


private:
	sf::Texture rock;
};

