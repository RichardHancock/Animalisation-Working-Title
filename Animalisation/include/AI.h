#ifndef AI_H
#define AI_H

#include <vector>
#include "Terrain.h"

class AI
{
private:

	bool aiState; //AI off or on

	const float impasTerrain = 0.4;
	const float unfavTerrain = 0.7;
	const float favTerrain = 1.5;

	int mapHeight;
	int mapWidth;
	std::vector<tile> tileGrid;
	std::vector<int>ExeceptionListLeft;
	std::vector<int>ExeceptionListRight;
	std::vector<int>ExeceptionListDown;
	std::vector<int>ExeceptionListTop;
public:
	AI(int Height, int Width);
	~AI();
	/**
	@brief A method to check the nearby grid tiles, and find out which tiles are adjacent

	The method takes in the Grid, and checks the IDs of the grids to find the ones next to the origin grid.
	The Origin grid is the one that the object that called the AI is currently on.
	@param Grid - Temp
	*/
	void getNearbySquare(std::vector<tile> & tiles, int index);
	/**
	@brief A method to check the nearby adjacent tiles for enemies

	This method uses the information from getNearbySquare to check for enemies.
	(Possible that grid stores a state if it is currently occupied with a object.)
	@param Grid - Temp
	*/
	bool getOccupied(std::vector<tile>&tileGrid,int i);
	/**
	@brief A method to check the tactical value of the adjacent hexagon tiles

	This method uses the information from getNearbySquare to check what type of tile it is, and assign any modifies to it.
	@param Grid - Temp
	*/
	int checkTacticalValue(std::vector<tile>&tilegrid, int i);
	void getExceptionSquare();
	tile setMovement(tile move);
	void clearVectors();
	/**
	@brief A method to initialize, and carry out the Movement AI

	This method calls different methods to get information about nearby tiles, and decide which is the best to move to.
	This sets the state for AI to false if all objects that can move have finished.
	*/
	void MovementAI(std::vector<tile>& tiles, int index);
	/**
	@brief A method to check the list of hubs that the race owns for those that are inactive

	This method has a parameter that contains all the hubs the race owns, and checks if their inactive state has been set to true.
	@param HubList - Temp
	*/
	void getAvailableHub(/*&HubList*/);
	/**
	@brief A method to add to the build queue of the hub that is inactive

	This method checks to see what object takes the less amount of time to build.Sets the inactive flag to false on execution
	*/
	void addBuildQueue();
	/**
	@brief A method to initialize, and carry out the Hub AI

	This method calls different methods to get information about hubs, and their current active flag. It then adds to their build queue,
	and cycle through all inactive hubs until all hubs are active.
	*/
	void HubAI(); //Main Hub AI method (will most likely have this call the other methods, and finalize the build queues for the different hubs)

};


#endif