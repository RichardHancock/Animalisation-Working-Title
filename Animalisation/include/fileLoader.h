#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

/**
@brief creates a class to laod in a map txt file*/
class FileLoader
{
private:
	/*varibles*/
	struct indexPosition //a structure for coordinates of an entity
	{
		int x;
		int y;
	};
	int numberOfGrass;
	int numberOfHills;
	int numberOfTowns;
	int numberOfWater;
	std::vector<indexPosition> grassPosition;
	std::vector<indexPosition> hillPosition;
	std::vector<indexPosition> townPosition;
	std::vector<indexPosition> waterPosition;
public:
	/**
	contruct the fileLoader
	contruct the fileLoader
	@param std::string the file location*/
	FileLoader(std::string);

	/**
	de-construct the fileLoader
	de-construct the fileLoader*/
	~FileLoader();

	/**load the file
	load the file
	@param std::string the file location*/
	void loadFile(std::string);

	/**getter # grass x index
	@param int the array index
	@return int the grass x index*/
	int getGrassIndexX(int);

	/**getter # grass y index
	@param int the array index
	@return int the grass y index*/
	int getGrassIndexY(int);

	/**getter # number of grass tiles
	@return int the number of grass tiles*/
	int getGrassNum();

	/**getter # hill x index
	@param int the array index
	@return int the hill x index*/
	int getHillIndexX(int);
#
	/**getter # hill y index
	@param int the array index
	@return int the hill y index*/
	int getHillIndexY(int);

	/**getter # number of hill tiles
	@return int the number of hill tiles*/
	int getHillNum();
	
	/**getter # town x index
	@param int the array index
	@return int the town x index*/
	int getTownIndexX(int);

	/**getter # town y index
	@param int the array index
	@return int the town y index*/
	int getTownIndexY(int);

	/**getter # number of town tiles
	@return int the number of town tiles*/
	int getTownNum();
	
	/**getter # water x index
	@param int the array index
	@return int the water x index*/
	int getWaterIndexX(int);

	/**getter # water y index
	@param int the array index
	@return int the water y index*/
	int getWaterIndexY(int);

	/**getter # number of water tiles
	@return int the number of water tiles*/
	int getWaterNum();
};
