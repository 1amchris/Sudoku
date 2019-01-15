#include "files.h"

json files::read_json(std::string source)
{
	// This loads the file.json in a json variable
	std::fstream file_reading(source.c_str());
	json _json;
	file_reading >> _json;

	return _json;
}

std::deque<Sudoku> files::read_sudokus()
{	
	// Read in the Sudokus
	json sudokus_json = read_json(Settings::sudokus_path);

	// We should parse the data in to a structure
	std::deque <Sudoku> my_sudokus;
	for (int i = 0; i < sudokus_json.size(); i++) {
		std::string i_to_string = str_manip::int_to_string(i);
		Sudoku new_sudoku;

		// ------------ SOLUTION ------------
		std::string solution = sudokus_json[i_to_string]["solution"];
		if (solution[0] == '"' && solution[solution.length() - 1] == '"') solution = solution.substr(1, solution.length() - 1 - 2);	// if both first and last characters are ' " ', remove them
		new_sudoku.solution = solution;
		
		// ------------ PUZZLE ------------
		std::string puzzle = sudokus_json[i_to_string]["puzzle"];
		if (puzzle[0] == '"' && puzzle[puzzle.length() - 1] == '"') puzzle = puzzle.substr(1, puzzle.length() - 1 - 2);	// if both first and last characters are ' " ', remove them
		new_sudoku.puzzle = puzzle;

		// ------------ LEVEL ------------
		std::string level = sudokus_json[i_to_string]["level"];
		if (level[0] == '"' && level[level.length() - 1] == '"') level = level.substr(1, level.length() - 1 - 2);	// if both first and last characters are ' " ', remove them
		new_sudoku.level = level;
		
		// ------------ TIME ------------
		std::string time = sudokus_json[i_to_string]["time"];
		if (time[0] == '"' && time[time.length() - 1] == '"') time = time.substr(1, time.length() - 1 - 2);	// if both first and last characters are ' " ', remove them
		new_sudoku.time = Time::format_string(time);

		// ------------ ADD IT ------------
		my_sudokus.push_back(new_sudoku);
	}

	return my_sudokus;
}

void files::load_settings()
{
	json settings_json = read_json(Settings::settings_path.c_str());
	Settings::sudokus_path = settings_json["sudoku_path"];
}
