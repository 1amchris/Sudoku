#pragma once
#include "Case.h"

class Zone
{
	void _init();

	Case _cases[9];
	bool _complete;

public:
	Zone();
	Zone(Case[9]);
	~Zone();

	bool get_Complete();
	void set_Case_Value(unsigned short int, unsigned short int);

	bool validate_Cases();
};

