#pragma once
#include <string>

class UI
{
	std::string input(); 
	void validate_input();

public:
	UI();
	~UI();

	void collect_input();
	std::string get_input();

	void draw();
};

