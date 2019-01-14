#pragma once
#include "str_manip.h"

// This ups any lower characters in the input string and returns it 
std::string str_manip::to_upper(std::string input) {
	for (int i = 0; i < input.length(); i++)
	{
		if ('a' <= input[i] && input[i] <= 'z') {
			input[i] = input[i] += 'A' - 'a';
		}
	}
	return input;
}

// This removes every space in the input string and returns it
std::string str_manip::remove_spaces(std::string input) {
	short int index = input.find(' ');
	while (-1 < index) {
		input.erase(input.begin() + index);
		index = input.find(' ');
	}
	return input;
}

// This only accepts one character int [0, 9]
char str_manip::int_to_char(int _integer) {
	std::stringstream ss;
	char _char;
	if (_integer != 0) {
		ss << _integer;
		ss >> _char;
	}
	else
		_char = '0';
	
	return _char;
}

// This takes in any int and returns an identical string
std::string str_manip::int_to_string(int _integer) {
	std::string _string = "";
	do {
		int single_char = _integer % 10;
		_integer /= 10;
		_string.insert(_string.begin(), int_to_char(single_char));
	} while (_integer != 0);

	return _string;
}