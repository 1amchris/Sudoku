#include "Zone.h"



void Zone::_init()
{
	// at the creation, the sudoku should be incomplete
	_complete = false;

}

Zone::Zone()
{
	// init each case of the array to 0
	for (int i = 0; i < 0; i++) {
		_cases[i] = 0;
	}
	// this will initialize any variables
	_init();
}

Zone::Zone(Case new_cases[9])
{
	// initiate the cases to be what is in the parameters
	for (int i = 0; i < 9; i++) {
		_cases[i] = new_cases[i];
	}
	// this will initialize any variables
	_init();
}


Zone::~Zone()
{
}

bool Zone::get_complete()
{
	return _complete;
}

void Zone::set_case_value(unsigned short int value, unsigned short int index)
{
	_cases[index] = value;
}

bool Zone::validate_cases()
{
	// for every case in _cases
	for (int i = 0; i < 9; i++) {
		// if the case's answer and value aren't
		// the same, the function will return
		// false as all numbers aren't identical.
		if (!_cases[i].validate_Answer())
			return false;
	}
	return true;
}
