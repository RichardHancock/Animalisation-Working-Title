#include"Character_Races.h"


Character_Races::Character_Races()
{
	hp = 100;
	strength = 100;
	race = rUnknown;
	string specialisation = NULL;
	
	
	
}

Character_Races::Character_Races(int in_hp, int in_strength, int in_race, string in_specialisation)
{
    hp = in_hp;
	strength = in_strength;
	race = in_race;
	specialisation = in_specialisation;
}


Character_Races::~Character_Races()
{
    
}


void Character_Races::setHP(int in_hp)
{
   hp = in_hp;
}

	int Character_Races::getHP() const
	{	
	   return hp;
	}


void Character_Races::setSTRENGTH(int in_strength)
{
	strength = in_strength;
}

	int Character_Races::getSTRENGTH() const
	{
		return strength;
	}

void Character_Races::setRACE(int in_race)
{
	race = in_race;
}

	int Character_Races::getRACE() const
	{
		return race;
	}
	
void Character_Races::setSPECIALISATION(string in_specialisation)
{
	specialisation = in_specialisation;
}

	string Character_Races::getSPECIALISATION() const
	{
			return specialisation;
	}
	


