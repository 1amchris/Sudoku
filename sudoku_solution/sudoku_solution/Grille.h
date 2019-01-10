#pragma once
#include "Zone.h"

class Grille
{
	void _init();

	Zone _zones[9];
	bool _complete;

public:
	Grille();
	Grille(Zone[9]);
	~Grille();

	bool get_complete();
	void set_case_value(unsigned short int, unsigned short int, char);
};

