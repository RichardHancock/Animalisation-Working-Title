#include "AI.h"

AI::AI(int Height, int Width)
{
	mapHeight = Height;
	mapWidth = Width;
	getExceptionSquare();
}

AI::~AI()
{
}
void AI::getExceptionSquare()
{
	for (int i = 0; i <= mapWidth; ++i)
	{
		int index = 0 * mapHeight + i;

		ExeceptionListTop.push_back(index);

		index = i * mapHeight;

		ExeceptionListDown.push_back(index);

		index = i * mapHeight + mapWidth;

		ExeceptionListLeft.push_back(index);

		index = mapHeight * mapWidth + i;

		ExeceptionListRight.push_back(index);
	}

};

void AI::getNearbySquare(std::vector<tile> & tiles, int index)
{

	bool left = false, right = false, top = false, down = false;

	for (int i = 0; i < mapHeight; ++i)
	{
		if (!index == ExeceptionListLeft[i])
		{
			if (left == false)
			{
				tileGrid.push_back(tiles[(index - 1)]);
				left = true;
			}
		}
		if (!index == ExeceptionListRight[i])
		{
			if (right == false)
			{
				tileGrid.push_back(tiles[index + 1]);
				right = true;
			}
		}
		if (!index == ExeceptionListTop[i])
		{
			if (top == false)
			{
				tileGrid.push_back(tiles[index + mapHeight]);
				top = true;
			}
		}
		if (!index == ExeceptionListDown[i])
		{
			if (down == false)
			{
				tileGrid.push_back(tiles[index - mapHeight]);
				down = true;
			}

		}
	}
};


bool AI::getOccupied(std::vector<tile>& tileGrid, int i)
{
	/*	if (tileGrid[i].Occupied == true)
		{
			return true;
		}
		else
		{
			return false;
		}*/
	return false;

};

int AI::checkTacticalValue(std::vector<tile>& tileGrid, int i)
	{
		int tile[4] = { 1, 1, 1, 1 };
		int max = tile[0];

		for (int i = 0; i < sizeof(tileGrid); i++)
		{
			int type = tileGrid[i].getType();
			if (type == 0 || type == 2)
			{
				tile[i] = tile[i] * favTerrain;
			}
			else
			{
				if (type == 3)
				{
					tile[i] = tile[i] * impasTerrain;
				}
				else
				{
					tile[i] = tile[i] * unfavTerrain;
				}
			}
			if (tile[i] > max)
			{
				max = tile[i];
			}

		}

		return max;
};

	tile AI::setMovement(tile move)
	{
		/* may change to calling the objects setLocation method, and returning this value to it */
		return move;
	}

	void AI::clearVectors()
	{
		tileGrid.clear();
	}

	void AI::MovementAI(std::vector<tile>& tiles, int index)
	{
		int AIindex = index;
		aiState = true;
		if (aiState == true)
		{
			getNearbySquare(tiles, AIindex);

			for (int i = 0; i < sizeof(tileGrid); i++)
			{
				bool isOccupied = getOccupied(tileGrid, i);
				if (isOccupied == false && checkTacticalValue(tileGrid, i) > 0.4)
				{
					tile move = tileGrid[i];
					setMovement(move);
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

