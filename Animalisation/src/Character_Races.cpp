#include"Character_Races.h"


Character_Races::Character_Races()
{
	hp = 100.0f;
	strength = 100.0f;
	race = rUnknown;
	specialisation = rUnidentified;
	race_hp_mult =  0.0f;
	race_str_mult = 0.0f;
	had_error_race = false;
	had_error_specialise = false;
	
	
}

Character_Races::Character_Races(int in_race, int in_specialisation)
{
	hp = 0.0f;
	strength = 0.0f;
	race = in_race;
	race_hp_mult = 0.0f;
	race_str_mult = 0.0f;
	specialisation = in_specialisation;
	had_error_race = false;
	had_error_specialise = false;
	
}


void Character_Races::RACE(int in_race)
{
	switch (in_race)
	{
		case rUnknown:
			had_error_race = true;
			break;
		case rCat:
			race_hp_mult = 0.65f;
			race_str_mult = 1.23f;
			break;
		case rDog:
			race_hp_mult = 0.75f;
			race_str_mult = 1.03f;
			break;
		case rMouse:
			race_hp_mult = 0.34f;
			race_str_mult = 0.57f;
			break;
		default:
			had_error_race = true;
			break;
	}
}


void Character_Races::SPECIALISE(int in_specialisation)
{
	switch (in_specialisation)
	{
		case rFighter:
			hp = 200.0f + ( 200.0f * race_hp_mult);
			// hp = 200 + race.base.hp
			strength = 250.0f + (250.0f * race_str_mult);
			break;
		case rEngineer:
			hp = 100.0f + (100.0f * race_hp_mult);
			strength = 125.0f + (125.0f * race_str_mult);
			break;
		case rCivilian:
			hp = 50.0f + ( 50.0f * race_hp_mult);
			strength = 25.0f + (25.0f * race_str_mult);
			break;
		case rMedic:
			hp = 25.0f + (25.0f * race_hp_mult);
			strength = 27.0f + (27.0f * race_str_mult);
			break;
		case rBuilder:
			hp = 75.0f + (75.0f * race_hp_mult);
			strength = 300.0f + (300.0f * race_str_mult);
			break;
		case rUnidentified:
		default:
			//This default case is here in case an undefinied specialisation is used.
			had_error_specialise = true;
			break;
	}
}


void Character_Races::ErrorUPDATE()
{
	
	
	if (had_error_race)
	{
		std::cerr << "Race not specified at all, please do that first before calling this function. \n";
	}

	if (had_error_specialise)
	{
		std::cerr << "You have failed at assigning the type for specialise - it is undefined, you are a noob, please fix the input or die?\n";
	}
}
Character_Races::~Character_Races()
{
    
}

bool Character_Races::checkErrorRACE() const
{
	return had_error_race;
}

bool Character_Races::checkErrorSPECIALISE() const
{
	return had_error_specialise;
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
	
void Character_Races::setSPECIALISATION(int in_specialisation)
{
	specialisation = in_specialisation;
}

	int Character_Races::getSPECIALISATION() const
	{
			return specialisation;
	}
	


