#include "Grille.h"



void Grille::_init()
{
	_complete = false;
}

void Grille::_create_zones_from_sudoku(Sudoku _sudoku)
{
	for (int zoney = 0; zoney < 3; zoney++) {		// zoney is worth 27 cases jump	-- this is 3 rows down
		for (int zonex = 0; zonex < 3; zonex++) {	// zonex is worth 3 cases jump -- this is 3 columns right
			for (int j = 0; j < 3; j++) {			// j is worth 9 cases jump -- this is 1 row down
				for (int i = 0; i < 3; i++) {		// i is worth 1 cases jump -- this is 1 column right
					
					// Value for the sudoku at this place
					unsigned int string_index = (zoney * 27) + (zonex * 3) + (j * 9) + (i);
					char case_value = _sudoku.puzzle[string_index];
					
					// Where in the grid
					unsigned int zone_index = (zoney * 3) + (zonex);
					unsigned int case_index = (j * 3) + (i);
					_zones[zone_index].set_case_value(case_value, case_index);
					// TODO add lockability
				}
			}
		}
	}
}

void Grille::_update_complete()
{
	bool is_completed = true;
	for (int i = 0; i < 9; i++) {
		if (!_zones[i].get_complete()) {
			is_completed = false;
			break;
		}
	}

	_complete = is_completed;
}

Grille::Grille()
{
	_init();
	for (int i = 0; i < 0; i++) {
		_zones[i] = 0;
	}
}

Grille::Grille(Sudoku _Sudoku)
{
	_init();
	_sudoku = _Sudoku;
	_create_zones_from_sudoku(_Sudoku);
}


Grille::~Grille()
{
}

bool Grille::get_complete()
{
	_update_complete();
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

	unsigned short int index_puzzle = number * 9 + letter_number;
	_sudoku.puzzle[index_puzzle] = value;
}
