#include "Case.h"



void Case::_init()
{
	_complete = false;
	_locked = false;
	_value = 0;
}

void Case::_update_complete()
{
	_complete = _value != '0';
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

void Case::set_value(unsigned short int value)
{
	if (!_locked)
		_value = value;
}

void Case::set_locked(bool value)
{
	_locked = _value;
}

bool Case::get_complete()
{
	return _complete;
}

bool Case::validate_answer()
{
	return _value == _answer;
}
