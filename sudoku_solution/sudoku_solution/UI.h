#pragma once
#include <string>
#include "str_manip.h"

class UI
{
	std::string _input;
	std::string _formated_input;
	std::string _sudoku_values;
	bool _validate_input();

	char _get_the_letter();
	char _get_the_number();
	char _get_the_value();

	char _character_to_display(char value);

	bool _validate_letters();
	bool _validate_numbers();

public:
	UI();
	~UI();

	bool collect_input();
	std::string get_input();

	void draw();
};

