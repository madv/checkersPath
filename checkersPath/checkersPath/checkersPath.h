/*
Purpose: Class declared as board and holds prototypes in public and variable in private.
*/
#pragma once
class Board
{

public:

	Board(); //creates an empty board      
	void reset(); //clears the board    
	void addChecker(char who, int row, int col); //adds a checker to the board
	int numJumps(int row, int col); // num of jumps possible from row, col    
	void print(); // print the board for debugging only


private:

	char board[8][8];
	int counter;
	int max;


};
