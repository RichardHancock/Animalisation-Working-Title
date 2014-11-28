#ifndef __CHARACTER_RACES_H__
#define __CHARACTER_RACES_H__
#pragma once


using namespace std;



#include <SDL.h>
#include <string>

enum race
{
	rUnknown,
	rCat,
	rDog,
	rMouse,
};


class Character_Races
{
public:

		Character_Races();
		
		Character_Races(int in_hp, int in_strength, int in_race, string in_specialisation);
		
		void setHP(int in_hp);
		int getHP() const;
		
		void setSTRENGTH(int in_strength);
		int getSTRENGTH() const;
		
		void setRACE(int in_race);
		int getRACE() const;
		
		void setSPECIALISATION(string in_specialisation);
		string getSPECIALISATION() const;
		
		~Character_Races();
		
		
protected:

SDL_Texture *_cTexture;

int hp;
int strength;
int race;
string specialisation;


private:

	


};
#endif


