#pragma once
/*Item class will be base for branches, rocks and diamod*/
#include "cObject.h"

class Item : public cObject
{
public:
	/*default constructor*/
	Item();

	/*this method returns type of an item -> item types can be found in utilities file (enum class)*/
	ITEM GetType() const;

public:
	ITEM m_type;
};

