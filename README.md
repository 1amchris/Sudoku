Sudoku/README.md

	Special thanks to nholmann for sharing his JSON library.
	it is an MIT open sourced project which can be downloaded
	at the following link: github.com/nholmann/json


	 ------------- INTRODUCTION ------------- 

	We  will begin by importing an existing sudoku.
	Sudokus can be imported from anywhere, but must 
	be formatted to the format used here. This program
	uses JSON files format.

	First, the file's direct path must be added in the 
	"Settings" tab. This path will be used to read the
	sudokus. Note that the path must include the JSON
	file name.

	 ------------- HOW TO PLAY ------------- 
	
	In order to play the game at the original settings,
	simply launch the Suduko executable and you'll reach
	the Main menu.
	
	In order to start the game, select "Play game". 
	If a game has already been started, the game will 
	display "Resume game".
	
	If you wish to learn how to play the game, select 
	the "How to play" option. This option will go
	through the fundamentals and the goals of the game.
	
	For any modifications and extra options, select the
	"Settings" option. The settings option will contain
	options that can be modified to best suit your game-
	play. In this settings, you can also find advanced
	settings such as the file directory where the sudokus
	are saved and from where to read the next sudokus.
	
	Note that a few sudokus are included with the download
	but if you wish to add your own sudokus you can do so
	by following the guide below. The files supported to
	this date are :
		- JSON
	Any files listed above can be read and the sudokus
	will be played in the game. To make and add your
	own sudokus, keep reading. :)
	
	If you wish to exit the game, select "Exit".


	 ------------- THE JSON FILE ------------- 

	The .JSON arguments are "sudoku", "solution",
	"time" and "level". The following is an example for 
	2 different sudokus. It will be possible to choose 
	which sudoku to play in the main menu

	.../example1.JSON
	{
		"1" : 
		{ 
		  "puzzle": "103...890",
		  "solution": "123...789",
		  "time" : "0:0:0:0",
		  "level": "easy"
		},
		"2" : 
		{
		  "puzzle": "400...098",
		  "solution": "467...198",
		  "time": "0:0:12:24",
		  "level": "easy"
		}
	}
	
	
	------------- FOR THE SUDOKU ------------- 

	1. All values must be listed in a 81 characters 
	long string.
	2. All values must be 0 through 9 values. [0, 9]
	3. All values BUT 0 will be displayed.
	4. The values of the unsolved sudoku must be listed 
	under the "puzzle" argument in the json file.

	.../example2.json
	{
	"1" : 
		{ 
		  "puzzle": "1234567890ABCDEFGHI01234567890ABCDEFGHI01234567890ABCDEFGHI01234567890ABCDEFGHI01",
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
	Note that the letters are not an appropriate value 
	and are used for demonstration only


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

	The "time": "0:0:0:0" reads "[days]:[hours]:[minutes]:[seconds]"
	The time is listed as 0:0:0:0 when the sudoku 
	has never been attempted.


	------------- FOR THE LEVEL -------------

	The "level" is arbitrary, anything can be 
	written there. It is solely as reference.
	anything is valid; please be nice ;P
	
	------------- CONCLUSION -------------

	Congratulations on reaching the bottom, hope 
	you enjoy your sudokus in the command prompt.


	For further programs and fun stuff, check out
	our github pages:
		github.com/1amchris/
		github.com//
	
	