#pragma once
#include <string>
#include "str_manip.h"

class UI
{
	std::string _input;
	std::string _formated_input;
	bool _validate_input();

	char _get_the_letter();
	char _get_the_number();
	char _get_the_value();

public:
	UI();
	~UI();

	void collect_input();
	std::string get_input();

	void draw();
};

