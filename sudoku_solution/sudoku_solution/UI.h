#pragma once
#include <string>

class UI
{
	std::string _input; 
	bool _validate_input();

	char _get_the_letter(std::string);
	char _get_the_number(std::string);
	char _get_the_value(std::string);

public:
	UI();
	~UI();

	void collect_input();
	std::string get_input();

	void draw();
};

