#ifndef TETRIS_H
#define TETRIS_H

#include <vector>
#include <iostream>
#include <string>
#include "tetromino.h"
#include <chrono>
#include <thread>
class Tetris;
using namespace std;

class Tetris
{
private:
	int row; //row size of board
	int column; //column size of board
	
public:
	static vector<vector<char>> board; //2d vector that holding the board.
	static vector<vector<char>> animate_vector; //2d vector that helps the animate process.

	Tetris(int row, int column); //constructor

	Tetris(); //constructor

	static void myboard(int row, int column); //it creates a 2D board based on the input the user enters.
	static void printmyboard(int row, int column); //it prints the 2D board based on the input the user enters.
	static void animatingshape(int row, int column); //it creates a 2D vector with the same sizes as the 'board' to do the animate process.
	static void printanimatingshape(); //it prints every step of the animate process.

	int getRow(){return row;} //it is the getter that returns the value of row
	int getColumn(){return column;} //it is the getter that returns the value of column
	
	void animate(int row, int column, vector <vector<char>> shape); //This function takes care of every step of the animate process. It calls the necessary functions (such as add, print) in it.

	void add(int column, vector <vector<char>> shape); //it adds the input shape to the top of the 'board' to start the animate process
};

#endif