#include <iostream>
#include <ctime>
#include <string>
#include <Windows.h>

using namespace std;

short mainMenuChoise, settingsChoise, gridChoise = 1, firstTurnChoise = 1, gameModeChoise, playerXChoise, playerOChoise, turnCPU, fieldOverflowStatus = 0, xColor = 2, oColor = 5;
/*half - made realisation of CHANGING WHOLE SYSTEM COLORS
string color, backgroundColorChoise, foregroundColorChoise;
short menuColorChoise;*/
char gameField[5][5] = { { '#', '#', '#', '#', '#' }, {'#', '#', '#', '#', '#'}, {'#', '#', '#', '#', '#'}, {'#', '#', '#', '#', '#'} , {'#', '#', '#', '#', '#'} };
char winner = ' ';

string clrRed = "\033[31m", clrGreen = "\033[32m", clrYellow = "\033[33m", clrBlue = "\033[34m", clrPurple = "\033[35m", clrCyan = "\033[36m", clrRst = "\033[0m";

void clearConsole()
{
	system("cls");
}

void howToPlay()
{
	cout << " [r] How to play\n\n";
	cout << " - One player is X and other is O (Computer can be a player as well).\n";
	cout << " - Players take turns putting their marks in empty spaces.\n";
	cout << " - The first player to get a straight vertical, horizontal or diagonal line wins.\n";
	cout << " - When all spaces are full and there is no winner, the game is over.\n";
	cout << " - To put a mark type 1-9 for 3x3, 1-16 for 4x4 and 1-25 for 5x5.\n\n";
	cout << " [!] Take note, while playing with CPU Dummy, player is always X\n\n";
	cout << " [3] Field 3x3\n 1 2 3\n 4 5 6\n 7 8 9\n\n";
	cout << " [4] Field 4x4\n  1  2  3  4\n  5  6  7  8\n  9 10 11 12\n 13 14 15 16\n\n";
	cout << " [5] Field 5x5\n  1  2  3  4  5\n  6  7  8  9 10\n 11 12 13 14 15\n 16 17 18 19 20\n 21 22 23 24 25\n\n";
	system("pause");
	cout << "\n\n";
}

/*void changeColor()
{	//half-made realisation of CHANGING WHOLE SYSTEM COLORS
	cout << " [c] Available colors for console: \n\n";
	cout << " [0] - Black\n";
	cout << " [1] - Sapphirine\n";
	cout << " [2] - Green\n";
	cout << " [3] - Blue\n";
	cout << " [4] - Red\n";
	cout << " [5] - Magenta\n";
	cout << " [6] - Yellow\n";
	cout << " [7] - White\n";
	cout << " [8] - Gray\n";
	cout << " [9] - Light sapphirine\n";
	cout << " [A] - Light green\n";
	cout << " [B] - Light blue\n";
	cout << " [C] - Light red\n";
	cout << " [D] - Light magenta\n";
	cout << " [E] - Light yellow\n";
	cout << " [F] - Bright white\n";

	cout << "\n [?] Choose your background color: ";
	cin >> backgroundColorChoise;
	cout << "\n [?] Choose your text color: ";
	cin >> foregroundColorChoise;
	cout << "\n\n";

	color = "color " + backgroundColorChoise + foregroundColorChoise;
	const char* userColor = color.c_str();
	system(userColor);
}*/

void xoColor()
{
	cout << " [c] Available colors for marks: \n\n";
	cout << " [1] - Red\n";
	cout << " [2] - Green\n";
	cout << " [3] - Yellow\n";
	cout << " [4] - Blue\n";
	cout << " [5] - Purple\n";
	cout << " [6] - Cyan\n";
	cout << " [7] - Default\n";

	cout << "\n [?] Choose your X color: ";
	cin >> xColor;
	while (xColor < 1 || xColor > 7)
	{
		cout << "\n [!]Error! There`s no such color.\n [?] Try again: ";
		cin >> xColor;
		cout << endl;
	}
	cout << "\n [?] Choose your O color: ";
	cin >> oColor;
	while (oColor < 1 || oColor > 7)
	{
		cout << "\n [!]Error! There`s no such color.\n [?] Try again: ";
		cin >> oColor;
		cout << endl;
	}
	cout << "\n\n";
}

void changeGrid()
{
	cout << " [g] Grid\n\n";
	cout << " [1] - 3x3\n [2] - 4x4\n [3] - 5x5\n\n";
	cout << " [?] Choose game grid: ";
	cin >> gridChoise;
	while (gridChoise < 1 || gridChoise > 3)
	{
		cout << "\n [!]Error! Invalid game grid.\n [?] Try again: ";
		cin >> gridChoise;
	}
	cout << "\n\n";
}

void changeFirstTurn()
{
	cout << " [f] First turn\n\n";
	cout << " [1] - X\n [2] - O\n\n";
	cout << " [?] Choose who has the first turn: ";
	cin >> firstTurnChoise;
	while (firstTurnChoise < 1 || firstTurnChoise > 2)
	{
		cout << "\n [!]Error! There`s no such mark.\n [?] Try again: ";
		cin >> firstTurnChoise;
	}
	cout << "\n\n";
}

void mainMenu()
{
	cout << " [#] TicTacToe\n\n";
	cout << " [1] - Start game\n [2] - Settings\n [3] - How to play\n [4] - Quit game\n\n";
	cout << " [?] Choose button: ";
	cin >> mainMenuChoise;
	cout << "\n\n";
}

void settingsMenu()
{
	cout << " [s] Settings\n\n";
	cout << " [1] - Colors\n [2] - First move\n [3] - Grid\n [4] - Back to main menu\n\n";
	cout << " [?] Choose button: ";
	cin >> settingsChoise;
	cout << "\n\n";
}

void startMenu()
{
	cout << " [#] Start game\n\n";
	cout << " [1] - Player VS CPU Dummy\n [2] - Player VS Player\n [3] - Back to main menu\n\n";
	cout << " [?] Choose button: ";
	cin >> gameModeChoise;
	while (gameModeChoise < 1 || gameModeChoise > 3)
	{
		cout << "\n [!]Error!  No such button.\n [?] Try again: ";
		cin >> gameModeChoise;
	}
	cout << "\n\n";
}

/*void menuColors()
{   //half-made realisation of CHANGING WHOLE SYSTEM COLORS
	cout << " [s] Choose what colors to change\n\n";
	cout << " [1] - X and O colors\n [2] - Whole console colors\n [3] - Back to main menu\n\n";
	cout << " [?] Choose button: ";
	cin >> menuColorChoise;
	while (menuColorChoise < 1 || menuColorChoise > 3)
	{
		cout << "\n [!]Error! There`s no such button.\n [?] Try again: ";
		cin >> menuColorChoise;
	}
	cout << "\n\n";
}*/

void printGameField()
{
	cout << " [#] TicTacToe\n";
	short i = 0;
	switch (gridChoise)
	{
	case 1: i = 3; break;
	case 2: i = 4; break;
	case 3: i = 5; break;
	}
	for (short y = 0; y < i; y++)
	{
		for (short x = 0; x < i; x++)
		{
			if (gameField[x][y] == 'X' && xColor == 1)
			{
				cout << " " << clrRed + gameField[x][y] + clrRst;
			}
			else if (gameField[x][y] == 'X' && xColor == 2)
			{
				cout << " " << clrGreen + gameField[x][y] + clrRst;
			}
			else if (gameField[x][y] == 'X' && xColor == 3)
			{
				cout << " " << clrYellow + gameField[x][y] + clrRst;
			}
			else if (gameField[x][y] == 'X' && xColor == 4)
			{
				cout << " " << clrBlue + gameField[x][y] + clrRst;
			}
			else if (gameField[x][y] == 'X' && xColor == 5)
			{
				cout << " " << clrPurple + gameField[x][y] + clrRst;
			}
			else if (gameField[x][y] == 'X' && xColor == 6)
			{
				cout << " " << clrCyan + gameField[x][y] + clrRst;
			}
			else if (gameField[x][y] == 'O' && oColor == 1)
			{
				cout << " " << clrRed + gameField[x][y] + clrRst;
			}
			else if (gameField[x][y] == 'O' && oColor == 2)
			{
				cout << " " << clrGreen + gameField[x][y] + clrRst;
			}
			else if (gameField[x][y] == 'O' && oColor == 3)
			{
				cout << " " << clrYellow + gameField[x][y] + clrRst;
			}
			else if (gameField[x][y] == 'O' && oColor == 4)
			{
				cout << " " << clrBlue + gameField[x][y] + clrRst;
			}
			else if (gameField[x][y] == 'O' && oColor == 5)
			{
				cout << " " << clrPurple + gameField[x][y] + clrRst;
			}
			else if (gameField[x][y] == 'O' && oColor == 6)
			{
				cout << " " << clrCyan + gameField[x][y] + clrRst;
			}
			else
			{
				cout << " " << gameField[x][y];
			}
		}
		cout << endl;
	}
	cout << "\n";
}

void turnPlayerX()
{
	cout << " [X] Player X`s turn: ";
	cin >> playerXChoise;
	if (gridChoise == 1)
	{
		switch (playerXChoise)
		{
		case 1:
			if (gameField[0][0] == '#') { gameField[0][0] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 2:
			if (gameField[1][0] == '#') { gameField[1][0] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 3:
			if (gameField[2][0] == '#') { gameField[2][0] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 4:
			if (gameField[0][1] == '#') { gameField[0][1] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 5:
			if (gameField[1][1] == '#') { gameField[1][1] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 6:
			if (gameField[2][1] == '#') { gameField[2][1] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 7:
			if (gameField[0][2] == '#') { gameField[0][2] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 8:
			if (gameField[1][2] == '#') { gameField[1][2] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 9:
			if (gameField[2][2] == '#') { gameField[2][2] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		default:
			cout << " [!] Error!\n";
			turnPlayerX();
			break;
		}
	}
	else if (gridChoise == 2)
	{
		switch (playerXChoise)
		{
		case 1:
			if (gameField[0][0] == '#') { gameField[0][0] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 2:
			if (gameField[1][0] == '#') { gameField[1][0] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 3:
			if (gameField[2][0] == '#') { gameField[2][0] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 4:
			if (gameField[3][0] == '#') { gameField[3][0] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 5:
			if (gameField[0][1] == '#') { gameField[0][1] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 6:
			if (gameField[1][1] == '#') { gameField[1][1] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 7:
			if (gameField[2][1] == '#') { gameField[2][1] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 8:
			if (gameField[3][1] == '#') { gameField[3][1] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 9:
			if (gameField[0][2] == '#') { gameField[0][2] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 10:
			if (gameField[1][2] == '#') { gameField[1][2] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 11:
			if (gameField[2][2] == '#') { gameField[2][2] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 12:
			if (gameField[3][2] == '#') { gameField[3][2] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 13:
			if (gameField[0][3] == '#') { gameField[0][3] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 14:
			if (gameField[1][3] == '#') { gameField[1][3] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 15:
			if (gameField[2][3] == '#') { gameField[2][3] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 16:
			if (gameField[3][3] == '#') { gameField[3][3] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		default:
			cout << " [!] Error!\n";
			turnPlayerX();
			break;
		}
	}
	else if (gridChoise == 3)
	{
		switch (playerXChoise)
		{
		case 1:
			if (gameField[0][0] == '#') { gameField[0][0] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 2:
			if (gameField[1][0] == '#') { gameField[1][0] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 3:
			if (gameField[2][0] == '#') { gameField[2][0] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 4:
			if (gameField[3][0] == '#') { gameField[3][0] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 5:
			if (gameField[4][0] == '#') { gameField[4][0] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 6:
			if (gameField[0][1] == '#') { gameField[0][1] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 7:
			if (gameField[1][1] == '#') { gameField[1][1] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 8:
			if (gameField[2][1] == '#') { gameField[2][1] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 9:
			if (gameField[3][1] == '#') { gameField[3][1] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 10:
			if (gameField[4][1] == '#') { gameField[4][1] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 11:
			if (gameField[0][2] == '#') { gameField[0][2] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 12:
			if (gameField[1][2] == '#') { gameField[1][2] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 13:
			if (gameField[2][2] == '#') { gameField[2][2] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 14:
			if (gameField[3][2] == '#') { gameField[3][2] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 15:
			if (gameField[4][2] == '#') { gameField[4][2] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 16:
			if (gameField[0][3] == '#') { gameField[0][3] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 17:
			if (gameField[1][3] == '#') { gameField[1][3] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 18:
			if (gameField[2][3] == '#') { gameField[2][3] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 19:
			if (gameField[3][3] == '#') { gameField[3][3] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 20:
			if (gameField[4][3] == '#') { gameField[4][3] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 21:
			if (gameField[0][4] == '#') { gameField[0][4] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 22:
			if (gameField[1][4] == '#') { gameField[1][4] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 23:
			if (gameField[2][4] == '#') { gameField[2][4] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 24:
			if (gameField[3][4] == '#') { gameField[3][4] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		case 25:
			if (gameField[4][4] == '#') { gameField[4][4] = 'X'; }
			else { cout << " [!] Already taken!\n"; turnPlayerX(); }
			break;
		default:
			cout << " [!] Error!\n";
			turnPlayerX();
			break;
		}
	}
	cout << endl;
}

void turnPlayerO()
{
	cout << " [O] Player O`s turn: ";
	cin >> playerOChoise;
	if (gridChoise == 1)
	{
		switch (playerOChoise)
		{
		case 1:
			if (gameField[0][0] == '#') { gameField[0][0] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 2:
			if (gameField[1][0] == '#') { gameField[1][0] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 3:
			if (gameField[2][0] == '#') { gameField[2][0] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 4:
			if (gameField[0][1] == '#') { gameField[0][1] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 5:
			if (gameField[1][1] == '#') { gameField[1][1] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 6:
			if (gameField[2][1] == '#') { gameField[2][1] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 7:
			if (gameField[0][2] == '#') { gameField[0][2] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 8:
			if (gameField[1][2] == '#') { gameField[1][2] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 9:
			if (gameField[2][2] == '#') { gameField[2][2] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		default:
			cout << " [!] Error!\n";
			turnPlayerO();
			break;
		}
	}
	else if (gridChoise == 2)
	{
		switch (playerOChoise)
		{
		case 1:
			if (gameField[0][0] == '#') { gameField[0][0] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 2:
			if (gameField[1][0] == '#') { gameField[1][0] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 3:
			if (gameField[2][0] == '#') { gameField[2][0] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 4:
			if (gameField[3][0] == '#') { gameField[3][0] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 5:
			if (gameField[0][1] == '#') { gameField[0][1] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 6:
			if (gameField[1][1] == '#') { gameField[1][1] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 7:
			if (gameField[2][1] == '#') { gameField[2][1] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 8:
			if (gameField[3][1] == '#') { gameField[3][1] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 9:
			if (gameField[0][2] == '#') { gameField[0][2] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 10:
			if (gameField[1][2] == '#') { gameField[1][2] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 11:
			if (gameField[2][2] == '#') { gameField[2][2] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 12:
			if (gameField[3][2] == '#') { gameField[3][2] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 13:
			if (gameField[0][3] == '#') { gameField[0][3] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 14:
			if (gameField[1][3] == '#') { gameField[1][3] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 15:
			if (gameField[2][3] == '#') { gameField[2][3] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 16:
			if (gameField[3][3] == '#') { gameField[3][3] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		default:
			cout << " [!] Error!\n";
			turnPlayerO();
			break;
		}
	}
	else if (gridChoise == 3)
	{
		switch (playerOChoise)
		{
		case 1:
			if (gameField[0][0] == '#') { gameField[0][0] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 2:
			if (gameField[1][0] == '#') { gameField[1][0] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 3:
			if (gameField[2][0] == '#') { gameField[2][0] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 4:
			if (gameField[3][0] == '#') { gameField[3][0] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 5:
			if (gameField[4][0] == '#') { gameField[4][0] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 6:
			if (gameField[0][1] == '#') { gameField[0][1] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 7:
			if (gameField[1][1] == '#') { gameField[1][1] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 8:
			if (gameField[2][1] == '#') { gameField[2][1] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 9:
			if (gameField[3][1] == '#') { gameField[3][1] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 10:
			if (gameField[4][1] == '#') { gameField[4][1] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 11:
			if (gameField[0][2] == '#') { gameField[0][2] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 12:
			if (gameField[1][2] == '#') { gameField[1][2] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 13:
			if (gameField[2][2] == '#') { gameField[2][2] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 14:
			if (gameField[3][2] == '#') { gameField[3][2] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 15:
			if (gameField[4][2] == '#') { gameField[4][2] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 16:
			if (gameField[0][3] == '#') { gameField[0][3] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 17:
			if (gameField[1][3] == '#') { gameField[1][3] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 18:
			if (gameField[2][3] == '#') { gameField[2][3] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 19:
			if (gameField[3][3] == '#') { gameField[3][3] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 20:
			if (gameField[4][3] == '#') { gameField[4][3] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 21:
			if (gameField[0][4] == '#') { gameField[0][4] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 22:
			if (gameField[1][4] == '#') { gameField[1][4] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 23:
			if (gameField[2][4] == '#') { gameField[2][4] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 24:
			if (gameField[3][4] == '#') { gameField[3][4] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		case 25:
			if (gameField[4][4] == '#') { gameField[4][4] = 'O'; }
			else { cout << " [!] Already taken!\n"; turnPlayerO(); }
			break;
		default:
			cout << " [!] Error!\n";
			turnPlayerO();
			break;
		}
	}
	cout << endl;
}

void gameWinnerCheck()
{
	if (gridChoise == 1 && winner == ' ')
	{
		if (gameField[0][0] != '#' && ((gameField[0][0] == gameField[1][0] && gameField[0][0] == gameField[2][0]) || (gameField[0][0] == gameField[0][1] && gameField[0][0] == gameField[0][2]) || (gameField[0][0] == gameField[1][1] && gameField[0][0] == gameField[2][2])))
		{/*1st hor row 1st ver row and diag \*/
			winner = gameField[0][0];
		}
		if (gameField[2][0] != '#' && ((gameField[2][0] == gameField[2][1] && gameField[2][0] == gameField[2][2]) || (gameField[2][0] == gameField[1][1] && gameField[2][0] == gameField[0][2])))
		{/*3rd ver row and diag /*/
			winner = gameField[2][0];
		}
		if (gameField[1][1] != '#' && ((gameField[1][1] == gameField[1][0] && gameField[1][1] == gameField[1][2]) || (gameField[1][1] == gameField[0][1] && gameField[1][1] == gameField[2][1])))
		{/*2nd ver and 2nd hor row*/
			winner = gameField[1][1];
		}
		if (gameField[1][2] != '#' && ((gameField[1][2] == gameField[0][2] && gameField[1][2] == gameField[2][2])))
		{/*3rd hor row*/
			winner = gameField[1][2];
		}
	}
	else if (gridChoise == 2 && winner == ' ')
	{
		if (gameField[0][0] != '#' && ((gameField[0][0] == gameField[1][0] && gameField[0][0] == gameField[2][0] && gameField[0][0] == gameField[3][0]) || (gameField[0][0] == gameField[1][1] && gameField[0][0] == gameField[2][2] && gameField[0][0] == gameField[3][3]) || (gameField[0][0] == gameField[0][1] && gameField[0][0] == gameField[0][2] && gameField[0][0] == gameField[0][3])))
		{/*1st hor and 1st ver rows and diag \*/
			winner = gameField[0][0];
		}
		if (gameField[3][0] != '#' && ((gameField[3][0] == gameField[3][1] && gameField[3][0] == gameField[3][2] && gameField[3][0] == gameField[3][3]) || (gameField[3][0] == gameField[2][1] && gameField[3][0] == gameField[1][2] && gameField[3][0] == gameField[0][3])))
		{/*4th ver row and diag /*/
			winner = gameField[3][0];
		}
		if (gameField[1][1] != '#' && ((gameField[1][1] == gameField[1][0] && gameField[1][1] == gameField[1][2] && gameField[1][1] == gameField[1][3]) || (gameField[1][1] == gameField[0][1] && gameField[1][1] == gameField[2][1] && gameField[1][1] == gameField[3][1])))
		{/*2nd ver and 2nd hor rows*/
			winner = gameField[1][1];
		}
		if (gameField[2][2] != '#' && ((gameField[2][2] == gameField[0][2] && gameField[2][2] == gameField[1][2] && gameField[2][2] == gameField[3][2]) || (gameField[2][2] == gameField[2][3] && gameField[2][2] == gameField[2][1] && gameField[2][2] == gameField[2][0])))
		{/*3rd hor and 3rd ver rows*/
			winner = gameField[0][0];
		}
		if (gameField[3][3] != '#' && ((gameField[3][3] == gameField[2][3] && gameField[3][3] == gameField[1][3] && gameField[3][3] == gameField[0][3])))
		{/*4th hor row*/
			winner = gameField[3][3];
		}
	}
	else if (gridChoise == 3 && winner == ' ')
	{
		if (gameField[0][0] != '#' && ((gameField[0][0] == gameField[1][0] && gameField[0][0] == gameField[2][0] && gameField[0][0] == gameField[3][0] && gameField[0][0] == gameField[4][0]) || (gameField[0][0] == gameField[1][1] && gameField[0][0] == gameField[2][2] && gameField[0][0] == gameField[3][3] && gameField[0][0] == gameField[4][4]) || (gameField[0][0] == gameField[0][1] && gameField[0][0] == gameField[0][2] && gameField[0][0] == gameField[0][3] && gameField[0][0] == gameField[0][4])))
		{/*1st hor and 1st ver rows and diag \*/
			winner = gameField[0][0];
		}
		if (gameField[4][0] != '#' && ((gameField[4][0] == gameField[4][1] && gameField[4][0] == gameField[4][2] && gameField[4][0] == gameField[4][3] && gameField[4][0] == gameField[4][4]) || (gameField[4][0] == gameField[3][1] && gameField[4][0] == gameField[2][2] && gameField[4][0] == gameField[1][3] && gameField[4][0] == gameField[0][4])))
		{/*5th ver row and diag /*/
			winner = gameField[4][0];
		}
		if (gameField[1][1] != '#' && ((gameField[1][1] == gameField[1][0] && gameField[1][1] == gameField[1][2] && gameField[1][1] == gameField[1][3] && gameField[1][1] == gameField[1][4]) || (gameField[1][1] == gameField[0][1] && gameField[1][1] == gameField[2][1] && gameField[1][1] == gameField[3][1] && gameField[1][1] == gameField[4][1])))
		{/*2nd ver and 2nd hor rows*/
			winner = gameField[1][1];
		}
		if (gameField[2][2] != '#' && ((gameField[2][2] == gameField[2][0] && gameField[2][2] == gameField[2][1] && gameField[2][2] == gameField[2][3] && gameField[2][2] == gameField[2][4]) || (gameField[2][2] == gameField[0][2] && gameField[2][2] == gameField[1][2] && gameField[2][2] == gameField[3][2] && gameField[2][2] == gameField[4][2])))
		{/*3rd hor and 3rd ver rows*/
			winner = gameField[2][2];
		}
		if (gameField[3][3] != '#' && ((gameField[3][3] == gameField[3][0] && gameField[3][3] == gameField[3][1] && gameField[3][3] == gameField[3][2] && gameField[3][3] == gameField[3][4]) || (gameField[3][3] == gameField[0][3] && gameField[3][3] == gameField[1][3] && gameField[3][3] == gameField[2][3] && gameField[3][3] == gameField[4][3])))
		{/*4th ver and 4th hor rows*/
			winner = gameField[3][3];
		}
		if (gameField[4][4] != '#' && ((gameField[4][4] == gameField[0][4] && gameField[4][4] == gameField[1][4] && gameField[4][4] == gameField[2][4] && gameField[4][4] == gameField[3][4])))
		{/*5th hor row*/
			winner = gameField[4][4];
		}
	}
}

void gameFieldOverflowCheck()
{
	short i = 0;
	short emptySpaceCount = 0;
	switch (gridChoise)
	{
	case 1: i = 3; break;
	case 2: i = 4; break;
	case 3: i = 5; break;
	}
	for (short y = 0; y < i; y++)
	{
		for (short x = 0; x < i; x++)
		{
			if (gameField[x][y] == '#')
			{
				emptySpaceCount++;
			}
		}
	}
	if (emptySpaceCount == 0)
	{
		fieldOverflowStatus = 1;
	}
	else
	{
		fieldOverflowStatus = 0;
	}
}

void turnCPUDummy()
{
	if (gridChoise == 1)
	{
		turnCPU = 1 + rand() % 9;
		switch (turnCPU)
		{
		case 1:
			if (gameField[0][0] == '#') { gameField[0][0] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 2:
			if (gameField[1][0] == '#') { gameField[1][0] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 3:
			if (gameField[2][0] == '#') { gameField[2][0] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 4:
			if (gameField[0][1] == '#') { gameField[0][1] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 5:
			if (gameField[1][1] == '#') { gameField[1][1] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 6:
			if (gameField[2][1] == '#') { gameField[2][1] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 7:
			if (gameField[0][2] == '#') { gameField[0][2] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 8:
			if (gameField[1][2] == '#') { gameField[1][2] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 9:
			if (gameField[2][2] == '#') { gameField[2][2] = 'O'; }
			else { turnCPUDummy(); }
			break;
		default:
			break;
		}
	}
	else if (gridChoise == 2)
	{
		turnCPU = 1 + rand() % 16;
		switch (turnCPU)
		{
		case 1:
			if (gameField[0][0] == '#') { gameField[0][0] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 2:
			if (gameField[1][0] == '#') { gameField[1][0] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 3:
			if (gameField[2][0] == '#') { gameField[2][0] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 4:
			if (gameField[3][0] == '#') { gameField[3][0] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 5:
			if (gameField[0][1] == '#') { gameField[0][1] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 6:
			if (gameField[1][1] == '#') { gameField[1][1] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 7:
			if (gameField[2][1] == '#') { gameField[2][1] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 8:
			if (gameField[3][1] == '#') { gameField[3][1] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 9:
			if (gameField[0][2] == '#') { gameField[0][2] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 10:
			if (gameField[1][2] == '#') { gameField[1][2] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 11:
			if (gameField[2][2] == '#') { gameField[2][2] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 12:
			if (gameField[3][2] == '#') { gameField[3][2] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 13:
			if (gameField[0][3] == '#') { gameField[0][3] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 14:
			if (gameField[1][3] == '#') { gameField[1][3] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 15:
			if (gameField[2][3] == '#') { gameField[2][3] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 16:
			if (gameField[3][3] == '#') { gameField[3][3] = 'O'; }
			else { turnCPUDummy(); }
			break;
		default:
			break;
		}
	}
	else if (gridChoise == 3)
	{
		turnCPU = 1 + rand() % 25;
		switch (turnCPU)
		{
		case 1:
			if (gameField[0][0] == '#') { gameField[0][0] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 2:
			if (gameField[1][0] == '#') { gameField[1][0] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 3:
			if (gameField[2][0] == '#') { gameField[2][0] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 4:
			if (gameField[3][0] == '#') { gameField[3][0] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 5:
			if (gameField[4][0] == '#') { gameField[4][0] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 6:
			if (gameField[0][1] == '#') { gameField[0][1] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 7:
			if (gameField[1][1] == '#') { gameField[1][1] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 8:
			if (gameField[2][1] == '#') { gameField[2][1] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 9:
			if (gameField[3][1] == '#') { gameField[3][1] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 10:
			if (gameField[4][1] == '#') { gameField[4][1] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 11:
			if (gameField[0][2] == '#') { gameField[0][2] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 12:
			if (gameField[1][2] == '#') { gameField[1][2] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 13:
			if (gameField[2][2] == '#') { gameField[2][2] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 14:
			if (gameField[3][2] == '#') { gameField[3][2] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 15:
			if (gameField[4][2] == '#') { gameField[4][2] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 16:
			if (gameField[0][3] == '#') { gameField[0][3] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 17:
			if (gameField[1][3] == '#') { gameField[1][3] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 18:
			if (gameField[2][3] == '#') { gameField[2][3] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 19:
			if (gameField[3][3] == '#') { gameField[3][3] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 20:
			if (gameField[4][3] == '#') { gameField[4][3] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 21:
			if (gameField[0][4] == '#') { gameField[0][4] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 22:
			if (gameField[1][4] == '#') { gameField[1][4] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 23:
			if (gameField[2][4] == '#') { gameField[2][4] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 24:
			if (gameField[3][4] == '#') { gameField[3][4] = 'O'; }
			else { turnCPUDummy(); }
			break;
		case 25:
			if (gameField[4][4] == '#') { gameField[4][4] = 'O'; }
			else { turnCPUDummy(); }
			break;
		default:;
			break;
		}
	}
	cout << endl;
}

void clearGameField()
{
	for (short y = 0; y < 5; y++)
	{
		for (short x = 0; x < 5; x++)
		{
			gameField[x][y] = '#';
		}
	}
}

int main()
{
	setlocale(0, "");

	clearConsole();
	mainMenu();

	srand(time(NULL));

	switch (mainMenuChoise)
	{
	case 1:
		clearConsole();
		startMenu();
		clearConsole();
		if (gameModeChoise == 1) //Player is always X against CPU Dummy
		{
			if (firstTurnChoise == 1) // When X is choosed to make 1st turn
			{
				while (winner != 'X' && winner != 'O' && fieldOverflowStatus == 0)
				{
					clearConsole();
					printGameField();
					turnPlayerX();
					gameWinnerCheck();
					gameFieldOverflowCheck();
					if (winner != 'X' && winner != 'O' && fieldOverflowStatus == 0)
					{
						clearConsole();
						printGameField();
						turnCPUDummy();
						gameWinnerCheck();
						gameFieldOverflowCheck();
					}
				}
				if (winner == 'X')
				{
					clearConsole();
					cout << " [w] YOU WON THE GAME AGAINST Dummy! Great Job!\n\n";
					winner = ' ';
				}
				else if (winner == 'O')
				{
					clearConsole();
					cout << " [l] YOU LOST THE GAME AGAINST Dummy! Don`t worry, you will get him next time!\n\n";
					winner = ' ';
				}
				else
				{
					clearConsole();
					cout << " [d] THE GAME FIELD HAS NO MORE EMPLY SLOTS. THE GAME IS OVER! Good luck next time!\n\n";
					fieldOverflowStatus = 0;
				}
				clearGameField();
			}
			if (firstTurnChoise == 2) // When O is choosed to make 1st turn
			{
				while (winner != 'X' && winner != 'O' && fieldOverflowStatus == 0)
				{
					clearConsole();
					printGameField();
					turnCPUDummy();
					gameWinnerCheck();
					gameFieldOverflowCheck();
					if (winner != 'X' && winner != 'O' && fieldOverflowStatus == 0)
					{
						clearConsole();
						printGameField();
						turnPlayerX();
						gameWinnerCheck();
						gameFieldOverflowCheck();
					}
				}
				if (winner == 'X')
				{
					clearConsole();
					cout << " [w] YOU WON THE GAME AGAINST Dummy! Great Job!\n\n";
					winner = ' ';
				}
				else if (winner == 'O')
				{
					clearConsole();
					cout << " [l] YOU LOST THE GAME AGAINST Dummy! Don`t worry, you will get him next time!\n\n";
					winner = ' ';
				}
				else
				{
					clearConsole();
					cout << " [d] THE GAME FIELD HAS NO MORE EMPLY SLOTS. THE GAME IS OVER! Good luck next time!\n\n";
					fieldOverflowStatus = 0;
				}
				clearGameField();
			}
		}
		else if (gameModeChoise == 2)
		{
			if (firstTurnChoise == 1) // When X is choosed to make 1st turn
			{
				while (winner != 'X' && winner != 'O' && fieldOverflowStatus == 0)
				{
					clearConsole();
					printGameField();
					turnPlayerX();
					gameWinnerCheck();
					gameFieldOverflowCheck();
					if (winner != 'X' && winner != 'O' && fieldOverflowStatus == 0)
					{
						clearConsole();
						printGameField();
						turnPlayerO();
						gameWinnerCheck();
						gameFieldOverflowCheck();
					}
				}
				if (winner == 'X')
				{
					clearConsole();
					cout << " [x] Player X WON THE GAME! Great Job!\n\n";
					winner = ' ';
				}
				else if (winner == 'O')
				{
					clearConsole();
					cout << " [o] Player O WON THE GAME! Well done!\n\n";
					winner = ' ';
				}
				else
				{
					clearConsole();
					cout << " [d] THE GAME FIELD HAS NO MORE EMPLY SLOTS. THE GAME IS OVER! Good luck next time!\n\n";
					fieldOverflowStatus = 0;
				}
				clearGameField();
			}
			if (firstTurnChoise == 2) // When O is choosed to make 1st turn
			{
				while (winner != 'X' && winner != 'O' && fieldOverflowStatus == 0)
				{
					clearConsole();
					printGameField();
					turnPlayerO();
					gameWinnerCheck();
					gameFieldOverflowCheck();
					if (winner != 'X' && winner != 'O' && fieldOverflowStatus == 0)
					{
						clearConsole();
						printGameField();
						turnPlayerX();
						gameWinnerCheck();
						gameFieldOverflowCheck();
					}
				}
				if (winner == 'X')
				{
					clearConsole();
					cout << " [x] Player X WON THE GAME! Great Job!\n\n";
					winner = ' ';
				}
				else if (winner == 'O')
				{
					clearConsole();
					cout << " [o] Player O WON THE GAME! Well done!\n\n";
					winner = ' ';
				}
				else
				{
					clearConsole();
					cout << " [d] THE GAME FIELD HAS NO MORE EMPLY SLOTS. THE GAME IS OVER! Good luck next time!\n\n";
					fieldOverflowStatus = 0;
				}
				clearGameField();
			}
		}
		else if (gameModeChoise == 3)
		{
			main();
		}
		system("pause");
		main();
	case 2:
		clearConsole();
		settingsMenu();
		switch (settingsChoise)
		{
		case 1:
			clearConsole();
			//half-made realisation of CHANGING WHOLE SYSTEM COLORS
			/*menuColors();
			if (menuColorChoise == 1)
			{
				clearConsole();
				xoColor();
			}
			else if (menuColorChoise == 2)
			{
				clearConsole();
				changeColor();
			}*/
			xoColor();
			clearConsole();
			main();
		case 2:
			clearConsole();
			changeFirstTurn();
			clearConsole();
			main();
		case 3:
			clearConsole();
			changeGrid();
			clearConsole();
			main();
		case 4:
			clearConsole();
			main();
		default:
			cout << "\nUnknown menu button!";
			short _; cin >> _;
			main();
		}
	case 3:
		clearConsole();
		howToPlay();
		clearConsole();
		main();
	case 4:
		clearConsole();
		cout << " [T_T] IT WAS HONOR TO SERVE YOU! GOODBYE!\n\n";
		exit(777);
	default:
		main();
	}

	system("pause");

	return 777;
}