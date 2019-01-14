#pragma once
#include <string>
#include <sstream>


namespace str_manip {

	std::string to_upper(std::string input);
	std::string remove_spaces(std::string input);

	char int_to_char(int _integer);
	std::string int_to_string(int _integer);
}