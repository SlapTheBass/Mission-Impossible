#include "cBranch.h"

cBranch::cBranch()
{
	branch.loadFromFile("graphics/items/spr_branch.png");
	m_type = ITEM::BRANCH;
	m_sprite.setTexture(branch);
}