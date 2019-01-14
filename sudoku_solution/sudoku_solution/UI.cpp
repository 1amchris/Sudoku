#include "UI.h"
#include <iostream>


bool UI::_validate_input()
{
	// it HAS_LETTER as the 1st character
	bool has_letter = false;
	if (_validate_letter(_input[0]))
		has_letter = true;

	// it HAS_NUMBER as the 2nd character
	bool has_number = false;
	if (_validate_number(_input[1]))
		has_number = true;

	// it HAS_EQUAL_SIGN as the 3rd character
	bool has_equal_sign = false;
	if (_input[2] == '=')
		has_equal_sign = true;
	
	// it HAS_VALUE as the 4th character
	bool has_value = false;
	if (_validate_number(_input[3]))
		has_value = true;

	// it has more than 4 character (it's too long, must be invalid)
	bool has_left_over = 4 < _input.length();

	// this function returns that the input
	//		has a letter, a number, a '=' and a value
	//		but does not have anything else
	///		Note  that the function also checks for order
	return has_letter && has_number && has_equal_sign && has_value && !has_left_over;
}


void UI::_init()
{
	_input = "";
	_formated_input = "";
	_console_spaces_before_sudoku = 3;
	// There should be 81 white spaces in an empty sudoku
	for (int i = 0; i < 81; i++)
		_sudoku_values.push_back(' ');
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
		if (_validate_number(_input[i]))
			continue;
		// it's an equal sign
		if (_input[i] == '=')
			continue;
		// it's a letter [A, I]
		if (_validate_letter(_input[i]))
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

// validates that the input is within the [A, I] range
bool UI::_validate_letter(char character) {
	return 'A' <= character && character <= 'I';
}

bool UI::_validate_numbers()
{
	bool numbers_ok = true;
	for (unsigned int i = 0; i < _input.length(); i++) {
		// it's a letter
		if (_validate_letter(_input[i]))
			continue;
		// it's an equal sign
		if (_input[i] == '=')
			continue;
		// it's a number [1, 9]
		if (_validate_number(_input[i]))
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

// validates that the input is within the [A, I] range
bool UI::_validate_number(char character) {
	return '1' <= character && character <= '9';
}

UI::UI()
{
	_init();
}

UI::UI(std::string _sudoku)
{
	_init();
	_sudoku_values = _sudoku;
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
/*
This is a representation of what will be shown in the console

     ------- ------- -------
   || X X X | X X X | X X X ||
   || X X X | X X X | X X X ||
   || X X X | X X X | X X X ||
     ------- ------- -------
   || X X X | X X X | X X X ||
   || X X X | X X X | X X X ||
   || X X X | X X X | X X X ||
     ------- ------- -------
   || X X X | X X X | X X X ||
   || X X X | X X X | X X X ||
   || X X X | X X X | X X X ||
     ------- ------- -------
*/
	// draw the 9 lines
	for (int i = 0; i < 9; i++) {
		std::string line = "";
		// how many spaces to the left of the sudoku
		for (int j = 0; j < _console_spaces_before_sudoku; j++) {
			line.push_back(' ');
		}
		// this is the outer left border
		line += "|| ";

		// for each 9 numbers in the row
		for (int j = 0; j < 9; j++) {
			// where is it?
			unsigned short index = i * 9 + j;
			// add the character to the line (the function returns what character to show)
			//						e.g.: can easily be turned in to an alphabet-based sudoku
			line += _character_to_display(_sudoku_values[index]);
			line += " ";
			// if we've added 3 character, add a separation as there are 3 "blocks"
			if ((j + 1) % 3 == 0)
				line += " | ";
		}
		// this is the outer right border
		line += " ||";
		std::cout << line << std::endl;

		// if we've added 3 rows, add a separation
		if ((i + 1) % 3 == 0) {
			// how many spaces to the left of the sudoku
			for (int j = 0; j < _console_spaces_before_sudoku; j++) {
				std::cout << ' ';
			}

			// there are 3 "blocks"
			for (int j = 0; j < 3; j++) {
				// add a space for each '|'
				std::cout << "  ";
				for (int k = 0; k < 9; k++) {
					std::cout << "-";
				}

				// we've met a '|'
				std::cout << " ";
			}
		}
	}
}
