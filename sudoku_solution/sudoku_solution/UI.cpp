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
	bool has_left_over;

	// this function returns that the input
	//		has a letter, a number, a '=' and a value
	//		but does not have anything else
	///		Note  that the function also checks for order
	return has_letter && has_number && has_equal_sign && has_value && !has_left_over;
}

char UI::_get_the_letter(std::string this_input)
{
	// TODO _get_the_letter(std::string)
	return 0;
}

char UI::_get_the_number(std::string this_input)
{
	// TODO _get_the_number(std::string)
	return 0;
}

char UI::_get_the_value(std::string this_input)
{
	// TODO _get_the_value(std::string)
	return 0;
}

UI::UI()
{
}


UI::~UI()
{
}

void UI::collect_input()
{
	// get the input
	std::cout << "Solution : ";
	std::string getline_value;
	getline(std::cin, getline_value);

	// TODO remove any spaces

	// TODO format the value to [A,I][1,9]=[1,9] : LetterNumber=Value
	char the_letter = _get_the_letter();
	char the_number = _get_the_number();
	char the_value = _get_the_value();
	
}

std::string UI::get_input()
{
	return _input;
}

void UI::draw()
{
	// TODO draw the grid
	std::cout << "Sudoku/UI.cpp/TODO draw the grid" << std::endl;
}
