// Maze.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h> 
#include <iostream> 
#include <cmath> 
#include <array>
#include <iomanip>
#include <string>
#include <windows.h>


#define TIME 500
using namespace std;

enum direction { RIGHT, LEFT, UP, DOWN };
struct position
{
	int raw;
	int column;
	direction currentDirection;
};
position startingPosition = { 2, 0, RIGHT };
const size_t labSize = 12;
void mazeTraverse(array<array <char, labSize>, labSize>, position);
bool iFree(array<array<char, labSize>, labSize> maze, position currentPosition);
bool iFinish(position currentPosition);
bool RoflanPominki(array<array<char, labSize>, labSize> maze, position currentPosition);
bool iRightPositionFree(array<array<char, labSize>, labSize> maze, position currentPosition);
bool iRightRoflanPominki(array<array<char, labSize>, labSize> maze, position currentPosition);
void outputMaze(array<array<char, labSize>, labSize>& maze);
void ClearScreen();

int main()
{
	array< array< char, labSize >, labSize > startingMaze = {
		'#','#','#','#','#','#','#','#','#','#','#','#',
		'#','.','.','.','#','.','.','.','.','.','.','#',
		'.','.','#','.','#','.','#','#','#','#','.','#',
		'#','#','#','.','#','.','.','.','.','#','.','#',
		'#','.','.','.','.','#','#','#','.','#','.','.',
		'#','#','#','#','.','#','.','#','.','#','.','#',
		'#','.','.','#','.','#','.','#','.','#','.','#',
		'#','#','.','#','.','#','.','#','.','#','.','#',
		'#','.','.','.','.','.','.','.','.','#','.','#',
		'#','#','#','#','#','#','.','#','#','#','.','#',
		'#','.','.','.','.','.','.','#','.','.','.','#',
		'#','#','#','#','#','#','#','#','#','#','#','#'
	};
	outputMaze(startingMaze);
	array< array< char, labSize >, labSize > maze = startingMaze;
	//position startingPosition;
	//startingPosition.raw = 2;
	//startingPosition.column = 0;
	//startingPosition.currentDirection = RIGHT;
	mazeTraverse(maze, startingPosition);
	system("pause");
	return 0;
}

void mazeTraverse(array<array<char, labSize>, labSize> maze, position currentPosition)
{
	int counter = 0;
	do {
		
		/*while (counter != 4) {*/
			switch (currentPosition.currentDirection)
			{
			case RIGHT:
			{
				if (!iFree(maze, currentPosition))
					counter++;
				else counter = 0;
				while (RoflanPominki(maze, currentPosition)&& (!iRightPositionFree(maze, currentPosition) ))
				{
						maze[currentPosition.raw][currentPosition.column] = 'X';
						if (!iFree(maze, currentPosition) && iRightRoflanPominki(maze, currentPosition) && counter <=4)
							break;
						currentPosition.column++;
						ClearScreen();
						outputMaze(maze);
						Sleep(TIME);
				}
				currentPosition.currentDirection = DOWN;
				break;
			}
			case LEFT:
			{
				if (!iFree(maze, currentPosition))
					counter++;
				else counter = 0;
				while (RoflanPominki(maze, currentPosition) && (!iRightPositionFree(maze, currentPosition)))
				{
						maze[currentPosition.raw][currentPosition.column] = 'X';
						if (!iFree(maze, currentPosition) && iRightRoflanPominki(maze, currentPosition) && counter <=4)
							break;
						currentPosition.column--;
						ClearScreen();
						outputMaze(maze);
						Sleep(TIME);
				}
				currentPosition.currentDirection = UP;
				break;
			}
			case UP:
			{
				if (!iFree(maze, currentPosition))
					counter++;
				else counter = 0;
				while (RoflanPominki(maze, currentPosition) && (!iRightPositionFree(maze, currentPosition)))
				{
						maze[currentPosition.raw][currentPosition.column] = 'X';
						if (!iFree(maze, currentPosition) && iRightRoflanPominki(maze, currentPosition) && counter <=4)
							break;
						currentPosition.raw--;
						ClearScreen();
						outputMaze(maze);
						Sleep(TIME);
				}
				currentPosition.currentDirection = RIGHT;
				break;
			}
			case DOWN:
			{
				if (!iFree(maze, currentPosition))
					counter++;
				else counter = 0;
				while (RoflanPominki(maze, currentPosition) && (!iRightPositionFree(maze, currentPosition)))
				{
						maze[currentPosition.raw][currentPosition.column] = 'X';
						if (!iFree(maze, currentPosition) && iRightRoflanPominki(maze, currentPosition) && counter <=4)
							break;
						currentPosition.raw++;
						ClearScreen();
						outputMaze(maze);
						Sleep(TIME);
				}
				currentPosition.currentDirection = LEFT;
				break;
			}
			default:
				break;
			}
		/*}*/
		/*while (counter == 4)
		{
			switch (currentPosition.currentDirection)
			{
			case RIGHT:
			{
				while (RoflanPominki(maze, currentPosition) && !iRightRoflanPominki(maze, currentPosition))
				{
					if (iFree(maze, currentPosition)|| iRightPositionFree(maze, currentPosition))
					{
						counter = 0;
						break;
					}
					maze[currentPosition.raw][currentPosition.column] = 'X';
					currentPosition.column++;
					
				}
				currentPosition.currentDirection = DOWN;
				break;
			}
			case LEFT:
			{
				while (RoflanPominki(maze, currentPosition) && !iRightRoflanPominki(maze, currentPosition))
				{
					if (iFree(maze, currentPosition) || iRightPositionFree(maze, currentPosition))
					{
						counter = 0;
						break;
					}
					maze[currentPosition.raw][currentPosition.column] = 'X';
					currentPosition.column--;
				}
					currentPosition.currentDirection = UP;
				break;
			}
			case UP:
			{
				while (RoflanPominki(maze, currentPosition) && !iRightRoflanPominki(maze, currentPosition))
				{
					if (iFree(maze, currentPosition) || iRightPositionFree(maze, currentPosition))
					{
						counter = 0;
						break;
					}
					maze[currentPosition.raw][currentPosition.column] = 'X';
					currentPosition.raw--;
				}
					currentPosition.currentDirection = RIGHT;
				break;
			}
			case DOWN:
			{
				while (RoflanPominki(maze, currentPosition) && !iRightRoflanPominki(maze, currentPosition))
				{
					if (iFree(maze, currentPosition) || iRightPositionFree(maze, currentPosition))
					{
						counter = 0;
						break;
					}
					maze[currentPosition.raw][currentPosition.column] = 'X';
					currentPosition.raw++;
				}
					currentPosition.currentDirection = LEFT;
				break;
			}
			default:
				break;
			}
			outputMaze(maze);
		}*/

	} while (!iFinish(currentPosition));
	ClearScreen();
	maze[currentPosition.raw][currentPosition.column] = 'O';
	outputMaze(maze);
}
bool iFree(array<array<char, labSize>, labSize> maze, position currentPosition)
{
	switch (currentPosition.currentDirection)
	{
	case RIGHT:
	{
		position nextPosition = currentPosition;
		nextPosition.column++;
		return (!iFinish(currentPosition) && maze[nextPosition.raw][nextPosition.column] != '#' && maze[nextPosition.raw][nextPosition.column] != 'X');
		break;
	}
	case LEFT:
	{
		position nextPosition = currentPosition;
		nextPosition.column--;
		return (!iFinish(currentPosition) && maze[nextPosition.raw][nextPosition.column] != '#' && maze[nextPosition.raw][nextPosition.column] != 'X');
		break;
	}
	case UP:
	{
		position nextPosition = currentPosition;
		nextPosition.raw--;
		return (!iFinish(currentPosition) && maze[nextPosition.raw][nextPosition.column] != '#' && maze[nextPosition.raw][nextPosition.column] != 'X');
		break;
	}
	case DOWN:
	{
		position nextPosition = currentPosition;
		nextPosition.raw++;
		return (!iFinish(currentPosition) && maze[nextPosition.raw][nextPosition.column] != '#' && maze[nextPosition.raw][nextPosition.column] != 'X');
		break;
	}
	default:
		return 0;
		break;
	}
}
bool iFinish(position currentPosition)
{
	position nextPosition = currentPosition;
	if (nextPosition.column == 11|| nextPosition.raw == 11)
	{
		nextPosition.raw++;
		nextPosition.column++;
	}
	else if (nextPosition.column == 0 || nextPosition.raw == 0)
	{
		nextPosition.column--;
		nextPosition.raw--;
	}
	return ((nextPosition.column >= labSize || nextPosition.raw >= labSize || nextPosition.column < 0|| nextPosition.raw  < 0)&& (startingPosition.column != currentPosition.column && startingPosition.raw != currentPosition.raw));
}

bool RoflanPominki(array<array<char, labSize>, labSize> maze, position currentPosition)
{
	switch (currentPosition.currentDirection)
	{
	case RIGHT:
	{
		position nextPosition = currentPosition;
		nextPosition.column++;
		return (!iFinish(currentPosition) && maze[nextPosition.raw][nextPosition.column] != '#');
		break;
	}
	case LEFT:
	{
		position nextPosition = currentPosition;
		nextPosition.column--;
		return (!iFinish(currentPosition) && maze[nextPosition.raw][nextPosition.column] != '#');
		break;
	}
	case UP:
	{
		position nextPosition = currentPosition;
		nextPosition.raw--;
		return (!iFinish(currentPosition) && maze[nextPosition.raw][nextPosition.column] != '#');
		break;
	}
	case DOWN:
	{
		position nextPosition = currentPosition;
		nextPosition.raw++;
		return (!iFinish(currentPosition) && maze[nextPosition.raw][nextPosition.column] != '#');
		break;
	}
	default:
		return 0;
		break;
	}
}
bool iRightPositionFree(array<array<char, labSize>, labSize> maze, position currentPosition)
{
	position rightPosition = currentPosition;
	switch (currentPosition.currentDirection)
	{
	case RIGHT:
	{
		rightPosition.raw++;
		return (maze[rightPosition.raw][rightPosition.column] == '.' /*|| maze[rightPosition.raw][rightPosition.column] == 'X'*/);
		break;
	}
	case LEFT:
	{
		rightPosition.raw--;
		return (maze[rightPosition.raw][rightPosition.column] == '.' /*|| maze[rightPosition.raw][rightPosition.column] == 'X'*/);
		break;
	}
	case UP:
	{
		rightPosition.column++;
		return (maze[rightPosition.raw][rightPosition.column] == '.' /*|| maze[rightPosition.raw][rightPosition.column] == 'X'*/);
		break;
	}
	case DOWN:
	{
		rightPosition.column--;
		return (maze[rightPosition.raw][rightPosition.column] == '.'/* || maze[rightPosition.raw][rightPosition.column] == 'X'*/);
		break;
	}
	default:
		return 0;
		break;
	}
}
void outputMaze(array<array<char, labSize>, labSize>& maze)
{
	for (auto const& row : maze) {
		for (auto const &element : row)
			cout << element << ' ';
		cout << endl;
	}
	cout << endl;
}
bool iRightRoflanPominki(array<array<char, labSize>, labSize> maze, position currentPosition)
{
	position rightPosition = currentPosition;
	switch (currentPosition.currentDirection)
	{
	case RIGHT:
	{
		rightPosition.raw++;
		return (maze[rightPosition.raw][rightPosition.column] == 'X' );
		break;
	}
	case LEFT:
	{
		rightPosition.raw--;
		return (maze[rightPosition.raw][rightPosition.column] == 'X' );
		break;
	}
	case UP:
	{
		rightPosition.column++;
		return (maze[rightPosition.raw][rightPosition.column] == 'X' );
		break;
	}
	case DOWN:
	{
		rightPosition.column--;
		return (maze[rightPosition.raw][rightPosition.column] == 'X');
		break;
	}
	default:
		return 0;
		break;
	}
}
void ClearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}