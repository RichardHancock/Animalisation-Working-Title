#include "fileLoader.h"

FileLoader::FileLoader(std::string fileName)//constructor
{
	loadFile(fileName);
}

FileLoader::~FileLoader()//De-constuctor
{

}

void FileLoader::loadFile(std::string fileName)
{
	/*KEY:grass=0/hill=1/town=2/water=3*/

	/*VARIABLE INITIALIZATION*/
	numberOfGrass = 0;
	numberOfHills = 0;
	numberOfTowns = 0;
	numberOfWater = 0;
	int tempGrass = 0;
	int tempWater = 0;
	int tempHill = 0;
	int tempTown = 0;

	std::ifstream file(fileName);//creates a input file stream called file using the value of fileName
	std::vector<std::string> line; //creates a vector of strings for the lines in the file

	if (file.is_open())//if the file successfully opens
	{
		/*FILE READ IN*/
		int i = -1, count = 0;
		std::string temp;
		while (getline(file, temp)) //while there are still lines to be read in from the file
		{
			i++;
			line.resize(i + 1);
			line[i] = temp;
		}
		file.close();

		/*Loop for the number of lines in the line array*/
		for (int i = 0; i < line.size(); i++)
		{
			/*loop for the number of characters in a single line*/
			for (int a = 0; a < line[i].size(); a++){
				switch (line[i][a])//check the character at this position in the array
				{
				case '0': //if 0 add 1 to the value of the number of grass in the file
					numberOfGrass++;
					break;
				case '1': //if 1 add 1 to the value of the number of hills in the file
					numberOfHills++;
					break;
				case '2': //if 2 add 1 to the value of the number of towns in the file
					numberOfTowns++;
					break;
				case '3': //if 3 add 1 to the value of the number of water in the file
					numberOfWater++;
					break;
				default: //if not any of thesee then do nothing
					break;
				}
			}
		}

		/*RESIZE ARRAYS USING NUMBERS COLLECTED*/
		waterPosition.resize(numberOfWater);
		townPosition.resize(numberOfTowns);
		hillPosition.resize(numberOfHills);
		grassPosition.resize(numberOfGrass);

		/*Loop for the number of lines in the line array*/
		for (int i = 0; i < line.size(); i++)
		{
			/*loop for the number of characters in a single line*/
			for (int a = 0; a < line[i].size(); a++){
				switch (line[i][a])//check the character at this position in the array
				{
				case '0':// if 0 set the index position using the loop variables in the grass vector array and add one to the value of temp grass
					grassPosition[tempGrass].x = a;
					grassPosition[tempGrass].y = i;
					tempGrass++;
					break;
				case '1':// if 1 set the index position using the loop variables in the hills vector array and add one to the value of temp hills
					hillPosition[tempHill].x = a;
					hillPosition[tempHill].y = i;
					tempHill++;
					break;
				case '2':// if 2 set the index position using the loop variables in the town vector array and add one to the value of temp town
					townPosition[tempTown].x = a;
					townPosition[tempTown].y = i;
					tempTown++;
					break;
				case '3':// if 3 set the index position using the loop variables in the water vector array and add one to the value of temp water
					waterPosition[tempWater].x = a;
					waterPosition[tempWater].y = i;
					tempWater++;
					break;
				default: //else do nothing
					break;
				}
			}
		}
	}

	else //if the file could be opened then output error message
	{
		std::cout << "Unable to open file";
	}

}

/*grass*/
int FileLoader::getGrassIndexX(int i)
{
	/*get grass x index*/
	return grassPosition[i].x;
}

int FileLoader::getGrassIndexY(int i)
{
	/*get grass y index*/
	return grassPosition[i].y;
}

int FileLoader::getGrassNum()
{
	/*get number of grass*/
	return numberOfGrass;
}

/*hill*/
int FileLoader::getHillIndexX(int i)
{
	/*get hill x index*/
	return hillPosition[i].x;
}

int FileLoader::getHillIndexY(int i)
{
	/*get hill y index*/
	return hillPosition[i].y;
}

int FileLoader::getHillNum()
{
	/*get number of hills*/
	return numberOfHills;
}

/*town*/
int FileLoader::getTownIndexX(int i)
{
	/*get town x index*/
	return townPosition[i].x;
}

int FileLoader::getTownIndexY(int i)
{
	/*get town y index*/
	return townPosition[i].y;
}

int FileLoader::getTownNum()
{
	/*get number of towns*/
	return numberOfTowns;
}

/*water*/
int FileLoader::getWaterIndexX(int i)
{
	/*get water x index*/
	return waterPosition[i].x;
}

int FileLoader::getWaterIndexY(int i)
{
	/*get water y index*/
	return waterPosition[i].y;
}

int FileLoader::getWaterNum()
{
	/*get number of water*/
	return numberOfWater;
}
