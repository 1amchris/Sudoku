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

