#include "AI.h"

AI::AI()
{
}


AI::~AI()
{
}

void AI::getNearbyHex(/*&HexagonGrid*/)
{


}


void AI::getNearbyEnemies(/*&HexagonGrid*/)
{
	
	for (int i = 0; i < sizeof(/*vector containing enemies*/); i++)
	{
		if(/*Vector containing enemies Enemy state == true*/
		{
			IDs.push_back(/*Vector state == true ID*/)
		}
	}
}

void AI::checkTacticalValue(/*&HexagonGrid*/)
{
}

void AI::setMovement()
{

}

void AI::clearVectors()
{
	IDs.clear();
}

void AI::MovementAI()
{
	if (aiState == true)
	{
		getNearbyHex();
		getNearbyEnemies();

		for (int i = 0; i < sizeof(/*nearby hex*/); i++)
		{
			getNearbyHex(/*Adjectent hex tile*/);
			getNearbyEnemies(/*Adjectent hex tile*/);
			if (/*Hex tile enemies == false && tactical value >= 1*/)
			{
				setMovement(/*Hex tile*/);
				clearVectors();
				aiState = false;
			}
		}
	}
}


void AI::getAvailableHub()
{
}

void AI::addBuildQueue()
{
}

void AI::HubAI()
{
}

