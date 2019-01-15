#pragma once
#include "../../nholmann/json.hpp"
using json = nlohmann::json;

#include <fstream>

#include <string>
#include <deque>

#include "Sudoku.h"
#include "Settings.h"

namespace files
{
	json read_json(std::string source);
	std::deque <Sudoku> read_sudokus();
	void load_settings();
};

