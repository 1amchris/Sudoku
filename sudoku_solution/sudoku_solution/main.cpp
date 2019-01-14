/*
	Sudoku/sudoku_solution/sudoku_solution/main.cpp
	Created by	Beaulieu,	Christophe
				Brière,		Alexandre

	Date : 2019-01-10
*/



int main() {

	/*
	 ------------- INTRODUCTION ------------- 

	We  will begin by importing an existing sudoku.
	Sudokus can be imported from anywhere, but must 
	be formatted to the format used here. This program
	uses JSON files format.

	First, the file's direct path must be added in the 
	"Settings" tab. This path will be used to read the
	sudokus. Note that the path must include the JSON
	file name.


	 ------------- THE JSON FILE ------------- 

	The .JSON arguments are "sudoku", "solution",
	"time" and "level". The following is an example for 
	2 different sudokus. It will be possible to choose 
	which sudoku to play in the main menu

	.../example1.JSON
	{
		"1" : 
		{ 
		  "sudoku": "103...890",
		  "solution": "123...789",
		  "time" : "0:0:0:0",
		  "level": "easy"
		},
		"2" : 
		{
		  "sudoku": "400...098",
		  "solution": "467...198",
		  "time": "0:0:12:24",
		  "level": "easy"
		}
	}
	
	
	------------- FOR THE SUDOKU ------------- 

	1. All values must be listed in a 81 characters long string.
	2. All values must be 0 through 9 values.	[0, 9]
	3. All values BUT 0 will be displayed.
	4. The values of the unsolved sudoku must be listed under
	the "sudoku" argument in the json file.

	.../example2.json
	{
	"1" : 
		{ 
		  "sudoku": "1234567890ABCDEFGHI01234567890ABCDEFGHI01234567890ABCDEFGHI01234567890ABCDEFGHI01",
		  "solution": "123456789KABCDEFGHIK123456789KABCDEFGHIK123456789KABCDEFGHIK123456789KABCDEFGHIKK",
		  "time" : "0:0:0:0",
		  "level": "easy"
		}
	}

	 ---------------------
	| 1 2 3  4 5 6  7 8 9 |
	|   A B  C D E  F G H |
	| I   1  2 3 4  5 6 7 |

	| 8 9    A B C  D E F |
	| G H I    1 2  3 4 5 |
	| 6 7 8  9   A  B C D |
	
	| E F G  H I    1 2 3 |
	| 4 5 6  7 8 9    A B |
	| C D E  F G H  I   1 |
	 ---------------------
	
	What's above is an example of what will be displayed
	for the corresponding example2.json file


	------------- FOR THE SOLUTION -------------

	The same thing applies for the solution. Only, this
	time, the 0 value is no longer accepted. Only values
	ranging from [1,9] must be used under the "solution"
	argument

	.../example2.json
	{
	"1" :
		{
		  "sudoku": "1234567890ABCDEFGHI01234567890ABCDEFGHI01234567890ABCDEFGHI01234567890ABCDEFGHI01",
		  "solution": "123456789KABCDEFGHIK123456789KABCDEFGHIK123456789KABCDEFGHIK123456789KABCDEFGHIKK",
		  "time" : "0:0:0:0",
		  "level": "easy"
		}
	}


	------------- FOR THE TIME -------------

	The "time": "0:0:0:0" stands for "[days]:[hours]:[minutes]:[seconds]"
	The time is listed as 0:0:0:0 when the sudoku has
	never been attempted.


	------------- FOR THE LEVEL -------------

	The "level" is arbitrary, anything can be written
	there. It is solely as reference.
	anything is valid; please be nice ;P
	
	------------- CONCLUSION -------------

	Congratulations on reaching the bottom, hope you
	enjoy this your sudokus


	For further programs and fun stuff, check out
	our github pages:
		github.com/1amchris/
		github.com//
	*/

	return 0;
}



