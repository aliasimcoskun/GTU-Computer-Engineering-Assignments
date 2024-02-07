#ifndef TETRIS_H
#define TETRIS_H

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <time.h>
#include "tetromino.h"

using namespace std;

namespace NS_tetris
{
	class Tetris
	{
	private:
		int row; //row size of board
		int column; //column size of board

		int animate_row; //row size of the animate board
		int animate_column; //column size of the animate column

		char move_direction; //the direction of the tetromino
		int move_count; //the count of the move times of tetromino

		char** board; //the 2d array which holds board of tetris game
		char** animate_arr; //the 2d array which is using while animate process
		
	public:
		Tetris(const int row, const int column); //constructor with size of row and column

		Tetris(); //constructor

		~Tetris(); //destructor

		bool operator+=(const Tetromino& obj); //it adds a Tetromino to top of the board by using operator overloading.

		void creating_board(); //it creates a 2D board based on the input the user enters.
		void draw(); //it prints the 2D board based on the input the user enters.

		void creating_animate_arr(); //it creates a 2D board which is using while animate process
		void draw_animate_arr();	//it prints the 2D animate board while animate process

		void animate(const Tetromino& obj); //This function takes care of every step of the animate process.

		inline int getRow()const{return row;} //it is the getter that returns the value of row
		inline int getColumn()const{return column;} //it is the getter that returns the value of column
		inline void setMove(const char movedir, const int movecount){move_direction=movedir; move_count=movecount;} //it is the setter that sets the value of movement informations.
	};
}

#endif