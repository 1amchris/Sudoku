#pragma once
#include "Case.h"

class Zone
{
	void _init();

	Case _cases[9];
	bool _complete;
	void _update_complete();

public:
	Zone();
	Zone(Case[9]);
	~Zone();

	bool get_complete();
	void set_case_value(unsigned short int value, unsigned short int index);

	bool validate_cases();
};

