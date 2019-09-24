/*
Purpose: Program tells user the maxmimum number of jumps they can make with their first red checker piece.

Program Input:  The user enters the number of test cases, the number of red pieces and black pieces with
their corresponding locations on the board.

Program Output: The program outputs the maxmimum number of jumps the first red piece can make
as well as prints the board to the developer if needed

Variables, Function, and Classes Used (Description): The checkers board is delcared in a class and is a two dimensional array.
The various functions in this program are also created in the class and  are able to create the board, clear the board,
print the board, add checkers to the board and find out the maximum number of jumps the first piece can make on the board.

Limiatations: Cannot put a checker piece out side of the 8 x 8 board.
*/

#include "checkersPath.h"
#include <iostream>
using namespace std;

int main()
{
	Board TheBoard;

	TheBoard.reset();

	char red = 'r'; //red piece

	char black = 'b'; //black piece

	char red1 = 'R'; //first red piece

	int testCaseVal;

	cout << "Enter number of test cases: ";
	cin >> testCaseVal;

	while (testCaseVal < 0)
	{
		cout << "ERROR, cannot have a test case value less than 0" << endl;
		cout << "Re-enter test case value: ";
		cin >> testCaseVal;
	}

	Board boardArray[100]; //array of boards

	int num_red; //number of red pieces

	int num_black; //number of black pieces

	int red_row;

	int red_col;

	int black_row;

	int black_col;

	int red_row_1;

	int red_col_1;

	int maxJumps[100]; //array to hold maxJump values for each case/board

	for (int index = 0; index < testCaseVal; index++)
	{
		cout << "Enter number of red checkers and black checkers: ";
		cin >> num_red >> num_black;


		cout << "Enter first red piece position: ";
		cin >> red_row_1 >> red_col_1;

		while (red_row_1 < 0 || red_row_1 > 7 || red_col_1 < 0 || red_col_1 > 7)
		{
			cout << "ERROR, location out of range" << endl;
			cout << "Enter first red piece position: ";
			cin >> red_row_1 >> red_col_1;
		}

		boardArray[index].addChecker(red1, red_row_1, red_col_1);

		for (int redIndex = 0; redIndex < num_red - 1; redIndex++)
		{
			cout << "Enter red piece position: ";
			cin >> red_row >> red_col;


			while (red_row < 0 || red_row > 7 || red_col < 0 || red_col > 7)
			{
				cout << "ERROR, location out of range" << endl;
				cout << "Enter red piece position: ";
				cin >> red_row >> red_col;
			}

			boardArray[index].addChecker(red, red_row, red_col);
		}

		for (int blackIndex = 0; blackIndex < num_black; blackIndex++)
		{
			cout << "Enter black piece position: ";
			cin >> black_row >> black_col;



			while (black_row < 0 || black_row > 7 || black_col < 0 || black_col > 7)
			{
				cout << "ERROR, location out of range" << endl;
				cout << "Enter black piece position: ";
				cin >> black_row >> black_col;
			}

			boardArray[index].addChecker(black, black_row, black_col);

		}
		maxJumps[index] = boardArray[index].numJumps(red_row_1, red_col_1);
	}

	for (int index2 = 0; index2 < testCaseVal; index2++)
	{
		cout << "Max number of possible jumps: " << maxJumps[index2] << endl;
	}



	for (int index3 = 0; index3 < testCaseVal; index3++)
	{
		cout << endl;
		cout << "Board " << index3 + 1 << endl;
		boardArray[index3].print();
		cout << endl;
	}


	system("pause");
	return 0;
}