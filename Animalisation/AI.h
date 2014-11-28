#ifndef AI_H
#define AI_H

class AI
{
Private:

	bool aiState; //AI off or on

	const float unfavTerrain = 0.7;
	const float favTerrain = 1.5;

Public:
	AI();
	~AI();

	void getNearbyHex(/*&HexagonGrid*/); //Gets the Hexagon System, and grabs the IDs of the closest Hexagons to the target that called the AI
	void getNearbyEnemies(/*&HexagonGrid*/); //Think about storing a state that changes if an enemy is on the tile or not... (discuss with lewis)
	void checkTacticalValue(/*&HexagonGrid*/); //Check the type of tile the hexagon is, and then multiply it based on the const floats, and find the path with the highest number
	void MovementAI(); //Main Movement AI method (Will most likely have this call the other methods, and finalize the movement of the object)

	void getAvailableHub(/*&HubList*/); //Checks the Hub list for all owned hubs that have the available queue state set to true, and returns the ID
	void addBuildQueue(); //Checks for what object at the hub will build the fastest, and adds it to its build queue setting the queue state to false
	void HubAI(); //Main Hub AI method (will most likely have this call the other methods, and finalize the build queues for the different hubs)

}


#endif