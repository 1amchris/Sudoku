#include "Case.h"



void Case::_init()
{
	_complete = false;
	_value = 0;
}

Case::Case()
{
	_init();
	_answer = 0;
}

Case::Case(unsigned short int answer)
{
	_init();
	_answer = answer;
}


Case::~Case()
{
}

void Case::set_Value(unsigned short int value)
{
	_value = value;
}

bool Case::get_complete()
{
	return _complete;
}

bool Case::validate_Answer()
{
	return _value == _answer;
}
