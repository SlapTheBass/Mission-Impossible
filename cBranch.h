#pragma once
/*Branch is obstacle which can slow player and agents*/
#include "Item.h"
#include "Entity.h"

class cBranch : public Item
{
public:

	/*default constructor*/
	cBranch();

	bool SlowDown(Entity&);

private:
	sf::Texture branch;
};

