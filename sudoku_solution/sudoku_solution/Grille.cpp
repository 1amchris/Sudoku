#include "Grille.h"



void Grille::_init()
{
	_complete = false;
}

Grille::Grille()
{
	for (int i = 0; i < 0; i++) {
		_zones[i] = 0;
	}
}

Grille::Grille(Zone init_zones[9])
{
	for (int i = 0; i < 9; i++) {
		_zones[i] = init_zones[i];
	}

	_init();
}


Grille::~Grille()
{
}

bool Grille::get_complete()
{
	return _complete;
}

void Grille::set_case_value(unsigned short int value, unsigned short int number, char letter)
{
	// Where does this letter lead
	unsigned short int letter_number = unsigned(short(int(letter - 'A')));	// This is to get a number instead of a letter ranging [0, 8]
	unsigned short int letter_zone = letter_number / 3;						// This is the zone in which the value will be changed
	unsigned short int letter_rank = letter_number % 3;						// This is the case in the zone that will be changed

	// Where does this number lead
	unsigned short int number_zone = number / 3;	// This is the zone in which the value will be changed
	unsigned short int number_rank = number % 3;	// This is the case in the zone that will be changed

	// Assign the value
	unsigned short int zone_index = (3 * letter_zone) + number_zone;	// This is the zone from a 2D array to a 1D array
	unsigned short int case_index = (3 * letter_rank) + number_rank;	// This is the case from a 2D array to a 1D array
	_zones[zone_index].set_case_value(value, case_index);				// This assigns the case the value
}
