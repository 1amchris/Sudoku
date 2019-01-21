/*
	Sudoku/sudoku_solution/sudoku_solution/main.cpp
	Created by	Beaulieu,	Christophe
				Brière,		Alexandre

	Date : 2019-01-10
*/
#define PAUSE system("pause")

#include <deque>
#include <string>
#include <iostream>

#include "Sudoku.h"
#include "files.h"

//#include "Grille.h"
#include "UI.h"




int main() {

	// load information in the program
	files::load_settings();
	std::deque <Sudoku> list_of_sudokus = files::read_sudokus();

	if (0 == list_of_sudokus.size()) {
		std::cout << "There is no sudoku in the file" << std::endl;
		PAUSE;
		return 1;
	}

	unsigned int choice = 0;
	Sudoku * this_game_sudoku = &list_of_sudokus[choice];
	UI this_UI(this_game_sudoku);

	while (this_game_sudoku->puzzle != this_game_sudoku->solution) {
		do
		{
			system("cls");
			this_UI.draw();
	
		} while (!this_UI.collect_input());

		std::string _input = this_UI.get_input();
		char _value = UI::parse_value(_input);
		unsigned int _index = UI::parse_index(_input);
		this_game_sudoku->puzzle[_index] = _value;
	}



	PAUSE;
	return 0;
}



