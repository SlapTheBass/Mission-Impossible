#include "Agent.h"

Agent::Agent()
{
	m_speed = 5.f;
	slow = false;
	slip = false;
	
	agent.loadFromFile("graphics/agent/agent.png");
	m_sprite.setTexture(agent);

	moveDirection('x', 0);
}

void Agent::moveAgent()
{
	if (!targetPositions.empty())
	{
		sf::Vector2f targetLocation = targetPositions.front();
		velocity = sf::Vector2f(targetLocation.x - m_position.x, targetLocation.y - m_position.y);

		if (abs(velocity.x) < 10.f && abs(velocity.y) < 10.f)
		{
			targetPositions.erase(targetPositions.begin());
		}
		else
		{
			float length = sqrt(velocity.x * velocity.x + velocity.y * velocity.y);

			velocity.x /= length;
			velocity.y /= length;

			m_position.x += velocity.x * m_speed;
			m_position.y += velocity.y * m_speed;

			m_sprite.setPosition(m_position);
			if (abs(velocity.x) > abs(velocity.y))
			{
				if (velocity.x <= 0)
				{
					moveDirection('l', m_speed);
				}
				else
				{
					moveDirection('r', m_speed);
				}
			}
			else
			{
				if (velocity.y <= 0)
				{
					moveDirection('u', m_speed);
				}
				else
				{
					moveDirection('d', m_speed);
				}
			}
		}
	}
}

void Agent::moveAgent(sf::Vector2f target)
{
	velocity = sf::Vector2f(target.x - m_position.x, target.y - m_position.y);

	float length = sqrt(velocity.x * velocity.x + velocity.y * velocity.y);

	velocity.x /= length;
	velocity.y /= length;

	m_position.x += velocity.x * m_speed;
	m_position.y += velocity.y * m_speed;

	m_sprite.setPosition(m_position);
	if (abs(velocity.x) > abs(velocity.y))
	{
		if (velocity.x <= 0)
		{
			moveDirection('l', m_speed);
		}
		else
		{
			moveDirection('r', m_speed);
		}
	}
	else
	{
		if (velocity.y <= 0)
		{
			moveDirection('u', m_speed);
		}
		else
		{
			moveDirection('d', m_speed);
		}
	}
}

void Agent::UpdatePathFinding(Level& level, sf::Vector2f target)
{
	std::vector<Tile*> openList;
	std::vector<Tile*> closedList;
	std::vector<Tile*> pathList;
	std::vector<Tile*>::iterator position;
	Tile* currentNode;
	Tile* xnode;

	level.ResetNodes();

	Tile* startNode = level.GetTile(m_position);
	Tile* goalNode = level.GetTile(target);

	if (startNode == goalNode)
	{
		targetPositions.clear();

		return;
	}

	for (int i = 0; i < 38; i++)
	{
		for (int j = 0; j < 22; j++)
		{
			int rowOffset, heightOffset;
			xnode = level.GetTile(i, j);

			heightOffset = abs(xnode->rowIndex - goalNode->rowIndex);
			rowOffset = abs(xnode->columnIndex - goalNode->columnIndex);

			xnode->H = heightOffset + rowOffset;
		}
	}

	openList.push_back(startNode);

	while (!openList.empty())
	{
		int lowestF = INT_MAX;

		for (Tile* tile : openList)
		{
			if (tile->F < lowestF)
			{
				lowestF = tile->F;
				currentNode = tile;
			}
		}

		position = std::find(openList.begin(), openList.end(), currentNode);

		if (position != openList.end())
		{
			openList.erase(position);
		}

		closedList.push_back(currentNode);

		std::vector<Tile*> adjacentTiles;

		Tile* node;

		//Top
		node = level.GetTile(currentNode->columnIndex, currentNode->rowIndex - 1);
		if ((node != nullptr) && ((node->type == TILE::EMPTY) || (node->type == TILE::BUSH)))
		{
			adjacentTiles.push_back(level.GetTile(currentNode->columnIndex, currentNode->rowIndex - 1));
		}
		//Right
		node = level.GetTile(currentNode->columnIndex + 1, currentNode->rowIndex);
		if ((node != nullptr) && ((node->type == TILE::EMPTY) || (node->type == TILE::BUSH)))
		{
			adjacentTiles.push_back(level.GetTile(currentNode->columnIndex + 1, currentNode->rowIndex));
		}
		//Bottom
		node = level.GetTile(currentNode->columnIndex, currentNode->rowIndex + 1);
		if ((node != nullptr) && ((node->type == TILE::EMPTY) || (node->type == TILE::BUSH)))
		{
			adjacentTiles.push_back(level.GetTile(currentNode->columnIndex, currentNode->rowIndex + 1));
		}
		//Left
		node = level.GetTile(currentNode->columnIndex - 1, currentNode->rowIndex);
		if ((node != nullptr) && ((node->type == TILE::EMPTY) || (node->type == TILE::BUSH)))
		{
			adjacentTiles.push_back(level.GetTile(currentNode->columnIndex - 1, currentNode->rowIndex));
		}

		for (Tile* node : adjacentTiles)
		{
			if (node == goalNode)
			{
				node->parentNode = currentNode;

				while (node->parentNode != nullptr)
				{
					pathList.push_back(node);
					node = node->parentNode;
				}

				openList.clear();
				break;
			}
			else
			{
				position = std::find(closedList.begin(), closedList.end(), node);
				if (position == closedList.end())
				{
					position = std::find(openList.begin(), openList.end(), node);
					if (position == openList.end())
					{
						openList.push_back(node);

						node->parentNode = currentNode;

						node->G = currentNode->G + 10;

						node->F = node->G + node->H;
					}
					else
					{
						int tempG = currentNode->G + 10;

						if (tempG < node->G)
						{
							node->parentNode = currentNode;
						}
					}
				}
			}
		}
	}

	targetPositions.clear();

	for (Tile* tile : pathList)
	{
		targetPositions.push_back(level.GetTileLocation(tile->columnIndex, tile->rowIndex));
	}

	std::reverse(targetPositions.begin(), targetPositions.end());
}

void Agent::Seek(Level& level, cPlayer& player)
{
	sf::Vector2f target;

	if (level.distanceBtwPts(GetPosition(), player.GetPosition()) < 350.f)
	{
		if (player.isVisible())
		{
			knowsPosition = true;
			UpdatePathFinding(level, player.GetPosition());

			if (level.distanceBtwPts(GetPosition(), player.GetPosition()) < 40.f)
			{
				level.EndGame(true);
			}
		}
	}
	else if (hasOrders == true)
	{
		if (PlayerSeen())
		{
			UpdatePathFinding(level, player.GetPosition());
			if (level.distanceBtwPts(GetPosition(), player.GetPosition()) < 40.f)
			{
				level.EndGame(true);
			}
		}
		switch (posIndex)
		{
		case 0:
			moveAgent(sf::Vector2f(GetPosition().x + 5, GetPosition().y));
			hasOrders = false;
			knowsPosition = false;
			break;

		case 1:
			moveAgent(center);
			hasOrders = false;
			knowsPosition = false;
			break;

		case 2:
			moveAgent(bot);
			hasOrders = false;
			knowsPosition = false;
			break;

		case 3:
			moveAgent(topLeft);
			hasOrders = false;
			knowsPosition = false;
			break;

		default:
			hasOrders = false;
			knowsPosition = false;
			break;
		}
	}
	else
	{

		auto temp = target;

		while (temp == target)
		{

			target = level.RandomSpawnLocation();

		}
		moveAgent(target);
	
	}

}

void Agent::RecieveOrder(bool orders, int type)
{
	hasOrders = orders;
	posIndex = type;
}

bool Agent::PlayerSeen()
{
	return knowsPosition;
}

void Agent::CanChase(bool test)
{
	knowsPosition = test;
}