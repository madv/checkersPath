
#include "checkersPath.h"
#include <iostream>
using namespace std;

/*
Purpose: Creates constructor and uses the reset function to create an empty board
*/

Board::Board()
{
	reset();
}

/*
Purpose: Function creates an empty board

Pre-condition: Board must be created

Post-condition: Board will be made up of space characters, board[row][col] = ' ';
*/

void Board::reset()
{
	for (int row = 0; row < 8; row++)
	{

		for (int col = 0; col < 8; col++)
		{

			board[row][col] = ' ';

		}
	}
	counter = 0;
	max = 0;
}


/*
Purpose: Function assigns character depending on parameter input.
If first piece, assigns as 'R', if a normal red piece, assigns as 'r',
if a normal black pieceassigns as 'b'

Pre-condition: Checker space is a blank space

Post-condition: Desired checker goes on dersired space
*/
void Board::addChecker(char who, int row, int col)
{
	char red = 'r';
	char black = 'b';
	char red1 = 'R';

	if (board[row][col] != ' ')
	{
		cout << "ERROR, you've already put a checker on this space" << endl;
	}

	if (who == red)
	{
		board[row][col] = red;
	}
	else if (who == red1)
	{
		board[row][col] = red1;
	}
	else if (who == black)
	{
		board[row][col] = black;

	}

}

/*
Purpose: Function calculates the maximum number of jumps the first red piece can make.

Pre-condition: Board must be 8 X 8 , Checkers cannot jump off board.

Post-condition: After each corner is checked, function returns the maxmium number of jumps
*/
int Board::numJumps(int row, int col)
{
	if (board[row][col] == 'R' && board[row + 1][col + 1] == 'b' && board[row + 2][col + 2] == ' ' && row < 6 && col < 6)
	{

		board[row + 2][col + 2] = board[row][col];
		board[row + 1][col + 1] = ' ';
		board[row][col] = ' ';
		counter++;

		numJumps(row + 2, col + 2);


		if (counter > max)
		{
			max = counter;
		}


		board[row][col] = 'R';
		board[row + 1][col + 1] = 'b';
		board[row + 2][col + 2] = ' ';
		counter--;
	}
	if (board[row][col] == 'R' && board[row - 1][col + 1] == 'b' && board[row - 2][col + 2] == ' ' && row > 1 && col < 6)
	{
		board[row - 2][col + 2] = board[row][col];
		board[row - 1][col + 1] = ' ';
		board[row][col] = ' ';
		counter++;

		numJumps(row - 2, col + 2);

		if (counter > max)
		{
			max = counter;
		}


		board[row][col] = 'R';
		board[row - 1][col + 1] = 'b';
		board[row - 2][col + 2] = ' ';
		counter--;
	}
	if (board[row][col] == 'R' && board[row - 1][col - 1] == 'b' && board[row - 2][col - 2] == ' ' && row > 1 && col > 1)
	{
		board[row - 2][col - 2] = board[row][col];
		board[row - 1][col - 1] = ' ';
		board[row][col] = ' ';
		counter++;

		numJumps(row - 2, col - 2);

		if (counter > max)
		{
			max = counter;
		}


		board[row][col] = 'R';
		board[row - 1][col - 1] = 'b';
		board[row - 2][col - 2] = ' ';
		counter--;
	}
	if (board[row][col] == 'R' && board[row + 1][col - 1] == 'b' && board[row + 2][col - 2] == ' ' && row < 6 && col > 1)
	{
		board[row + 2][col - 2] = board[row][col];
		board[row + 1][col - 1] = ' ';
		board[row][col] = ' ';
		counter++;

		numJumps(row + 2, col - 2);

		if (counter > max)
		{
			max = counter;
		}

		board[row][col] = 'R';
		board[row + 1][col - 1] = 'b';
		board[row + 2][col - 2] = ' ';
		counter--;
	}


	return max;

}

/*
Purpose: Function prints the checker board

Pre-condition: None

Post-condition: None
*/

void Board::print()
{

	cout << "  ---------------------------------" << endl;
	for (int row = 7; row >= 0; row--)
	{
		cout << row << " ";
		for (int col = 0; col < 8; col++)
		{
			cout << "| " << board[row][col] << " ";

		}
		cout << "| ";

		cout << endl;
		cout << "  ---------------------------------" << endl;

	}

	cout << "    0   1   2   3   4   5   6   7" << endl;
}

