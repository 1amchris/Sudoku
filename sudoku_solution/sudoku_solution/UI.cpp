#include "UI.h"
#include <iostream>


bool UI::_validate_input()
{
	// TODO _validate_input()
	// The four things that's needed
	bool has_letter = false;
	bool has_number = false;
	bool has_equal_sign = false;
	bool has_value = false;




	// if the string contains to much information
	bool has_left_over = true;

	// this function returns that the input
	//		has a letter, a number, a '=' and a value
	//		but does not have anything else
	///		Note  that the function also checks for order
	return has_letter && has_number && has_equal_sign && has_value && !has_left_over;
}


char UI::_get_the_letter()
{
	// Will return the first letter it finds in the first two characters
	for (unsigned short int i = 0; i < 2; i++) {
		if ('A' <= _input[i] && _input[i] <= 'I')
			return _input[i];
	}

	// This function returns '0' to signal an error
	return '0';
}

char UI::_get_the_number()
{
	// Will return the first number it finds in the first two characters
	for (unsigned short int i = 0; i < 2; i++) {
		if ('1' <= _input[i] && _input[i] <= '9')
			return _input[i];
	}

	// This function returns '0' to signal an error
	return '0';
}

char UI::_get_the_value()
{
	// Will return the last character if it is a number [1, 9]
	unsigned short int index = unsigned short(_input.length() - 1);
	if ('1' <= _input[index] && _input[index] <= '9')
		return _input[index];

	// This function returns '0' to signal an error
	return '0';
}

char UI::_character_to_display(char value)
{
	return '0' < value ? value : ' ';
}

bool UI::_validate_letters()
{
	bool letters_ok = true;
	for (unsigned int i = 0; i < _input.length(); i++) {
		// it's a number
		if ('0' <= _input[i] && _input[i] <= '9')
			continue;
		// it's an equal sign
		if (_input[i] == '=')
			continue;
		// it's a letter [A, I]
		if ('A' <= _input[i] && _input[i] <= 'I')
			continue;
		// it's something else
		else
		{
			letters_ok = false;
			break;
		}
	}

	return letters_ok;
}

bool UI::_validate_numbers()
{
	bool numbers_ok = true;
	for (unsigned int i = 0; i < _input.length(); i++) {
		// it's a letter
		if ('A' <= _input[i] && _input[i] <= 'Z')
			continue;
		// it's an equal sign
		if (_input[i] == '=')
			continue;
		// it's a number [1, 9]
		if ('1' <= _input[i] && _input[i] <= '9')
			continue;
		// it's something else
		else
		{
			numbers_ok = false;
			break;
		}
	}

	return numbers_ok;
}

UI::UI()
{
}


UI::~UI()
{
}

bool UI::collect_input()
{
	// get the input
	std::cout << "Solution : ";
	getline(std::cin, _input);

	// up any lower cases in _input
	_input = str_manip::to_upper(_input);
	// remove any spaces in _input
	_input = str_manip::remove_spaces(_input);

	/// The letters must be within [A, I]
	/// The numbers must be within [1, 9]
	if (!_validate_letters()
		|| !_validate_numbers()) {
		return false;
	}

	// format the value to [A,I][1,9]=[1,9] : LetterNumber=Value
	char the_letter = _get_the_letter();
	char the_number = _get_the_number();
	char the_value = _get_the_value();
	// if either one of theses values is incorrect, return false
	if (the_letter == '0' || the_number == '0' || the_value == '0')
		return false;

	return true;
}

std::string UI::get_input()
{
	return _input;
}

void UI::draw()
{
	// TODO draw the grid
	std::cout << "Sudoku/UI.cpp/TODO draw the grid" << std::endl;

	// The input is a string of 81 characters
	for (int i = 0; i < 9; i++) {
		std::string line = " || ";
		for (int j = 0; j < 9; j++) {
			unsigned short index = i * 9 + j;
			line += _character_to_display(_sudoku_values[index]);
			line += " ";
			if ((j+1) % 3 == 0)
				line += " | ";
		}
		std::cout << line << std::endl;
	}
}
