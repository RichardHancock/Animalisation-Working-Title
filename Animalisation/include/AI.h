#ifndef AI_H
#define AI_H

#include <vector>
//
//class AI
//{
//private:
//
//	bool aiState; //AI off or on
//
//	const float unfavTerrain = 0.7;
//	const float favTerrain = 1.5;
//
//	std::vector<int> IDs;
//
//public:
//	AI();
//	~AI();
//	/**
//	@brief A method to check the nearby Hexagon grid tiles, and find out which tiles are adjacent
//
//	The method takes in the HexagonGrid, and checks the IDs of the grids to find the ones next to the origin grid.
//	The Origin grid is the one that the object that called the AI is currently on.
//	@param HexagonGrid - Temp
//	*/
//	void getNearbyHex(/*&HexagonGrid*/); 
//	/**
//	@brief A method to check the nearby adjacent hexagon tiles for enemies
//
//	This method uses the information from getNearbyHex to check for enemies.
//	(Possible that grid stores a state if it is currently occupied with a object.)
//	@param HexagonGrid - Temp
//	*/
//	void getNearbyEnemies(/*&HexagonGrid*/); 
//	/**
//	@brief A method to check the tactical value of the adjacent hexagon tiles
//
//	This method uses the information from getNearbyHex to check what type of tile it is, and assign any modifies to it.
//	@param HexagonGrid - Temp
//	*/
//	void checkTacticalValue(/*&HexagonGrid*/);
//	void setMovement();
//	void clearVectors();
//	/**
//	@brief A method to initialize, and carry out the Movement AI
//
//	This method calls different methods to get information about nearby tiles, and decide which si the best to move to.
//	This sets the state for AI to false if all objects that can move have finished.
//	*/
//	void MovementAI(); 
//	/**
//	@brief A method to check the list of hubs that the race owns for those that are inactive
//
//	This method has a parameter that contains all the hubs the race owns, and checks if their inactive state has been set to true.
//	@param HubList - Temp
//	*/
//	void getAvailableHub(/*&HubList*/);
//	/**
//	@brief
//	*/
//	void addBuildQueue(); //Checks for what object at the hub will build the fastest, and adds it to its build queue setting the queue state to false
//	void HubAI(); //Main Hub AI method (will most likely have this call the other methods, and finalize the build queues for the different hubs)

}


#endif