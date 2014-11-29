#ifndef __CHARACTER_RACES_H__
#define __CHARACTER_RACES_H__
#pragma once


using namespace std;



#include <SDL.h>
#include <iostream>

enum race
{
	rUnknown,
	rCat,
	rDog,
	rMouse,
};

enum specialisation
{
	rFighter,
	rEngineer,
	rCivilian,
	rMedic,
	rBuilder,
	rUnidentified,

};


class Character_Races
{
public:

		Character_Races();
		
		Character_Races(int in_race, int in_specialisation);
		
		void setHP(int in_hp);
		int getHP() const;

		void SPECIALISE(int in_specialisation);

		void RACE(int in_race);
		
		void setSTRENGTH(int in_strength);
		int getSTRENGTH() const;
		
		void setRACE(int in_race);
		int getRACE() const;
		
		void setSPECIALISATION(int in_specialisation);
		int getSPECIALISATION() const;

		bool checkErrorRACE() const;
		bool checkErrorSPECIALISE() const;

		void ErrorUPDATE();
		
		~Character_Races();
		
		
protected:

SDL_Texture *_cTexture;

float hp;
float strength;
int race;
int specialisation;

float race_hp_mult;
float race_str_mult;

bool had_error_race;
bool had_error_specialise;


private:

	


};
#endif


