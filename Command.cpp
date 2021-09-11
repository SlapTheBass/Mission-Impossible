#include "Command.h"

Command::Command()
{

}

void Command::Check(Agent& agent)
{
	agents.push_back(agent);
	if (agent.PlayerSeen())
	{
		playerSeen = true;
	}
}

void Command::ChaseOrder()
{
	for (auto& agent : agents)
	{
		agent.CanChase(true);
	}
}


