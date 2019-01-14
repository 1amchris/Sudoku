#pragma once
#include <string>
#include "str_manip.h"

class UI
{
	void _init();

	std::string _input;
	std::string _formated_input;
	std::string _sudoku_values;
	unsigned int _console_spaces_before_sudoku;

	char _get_the_letter();
	char _get_the_number();
	char _get_the_value();

	char _character_to_display(char value);

	bool _validate_input();						// validates the whole input
	bool _validate_letters();					// validates all characters
	bool _validate_letter(char character);		// validates only a character [A, I]
	bool _validate_numbers();					// validates all characters
	bool _validate_number(char character);		// validates only a character [1, 9]

public:
	UI();
	UI(std::string _sudoku);
	~UI();

	bool collect_input();
	std::string get_input();

	void draw();
};

