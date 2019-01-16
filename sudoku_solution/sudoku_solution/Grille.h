#pragma once
#include "Zone.h"
#include "Sudoku.h"

class Grille
{
	void _init();
	void _create_zones_from_sudoku(Sudoku _sudoku);
	Sudoku _sudoku;

	Zone _zones[9];
	bool _complete;
	void _update_complete();

public:
	Grille();
	Grille(Sudoku sudoku);
	~Grille();

	bool get_complete();
	void set_case_value(unsigned short int value, unsigned short int number, char letter);

	static char parse_value(std::string input);
	static unsigned int parse_index(std::string input);
};

