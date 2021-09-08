#pragma once
/*Item class will be base for branches, rocks and diamod*/
#include "cObject.h"

class Item : public cObject
{
public:
	/*default constructor*/
	Item();

	/*this method draws an item, returns void, and should take game window as an argument*/
	void Draw(sf::RenderWindow& window);

	/*this method returns type of an item -> item types can be found in utilities file (enum class)*/
	ITEM GetType() const;

protected:
	/*method setting item name from string, returns void*/
	void SetItemName(std::string name);

public:
	std::string m_name;

	ITEM m_type;
};

