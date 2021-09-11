#pragma once
#include "PCH.h"
#include "Agent.h"
#include "cPlayer.h"


class Command
{
public:
	/*default constructor*/
	Command();

	/*send agent to specific position*/
	void Check(Agent& agent);

	void ChaseOrder();

private:
	bool playerSeen;
	std::vector<Agent> agents;
};

