#ifndef TETRISADAPTER_H
#define TETRISADAPTER_H

#include "Abstract.h"
#include <vector>

template <typename temp>
class TetrisAdapter : public Abstract
{
private:
    int row; //row size of board
    int column; //column size of board

    int animate_row; //row size of the animate board
    int animate_column; //column size of the animate column

    char move_direction; //the direction of the tetromino
    int move_count; //the count of the move times of tetromino

    temp board;
    temp animate_arr;

public:
    TetrisAdapter() = delete; //constructor
    TetrisAdapter(const int new_row, const int new_column); //constructor with size of row and column
    virtual ~TetrisAdapter(); //destructor

    virtual bool operator+=(const Tetromino& obj)override; //it adds a Tetromino to top of the board by using operator overloading.

    virtual void creating_board()override; //it creates a 2D board based on the input the user enters.
    virtual void draw()override; //it prints the 2D board based on the input the user enters.

    virtual void creating_animate_arr()override; //it creates a 2D board which is using while animate process
    virtual void draw_animate_arr()override;	//it prints the 2D animate board while animate process

    virtual void animate(const Tetromino& obj)override; //This function takes care of every step of the animate process.

    virtual inline int getRow()const override{return row;} //it is the getter that returns the value of row
    virtual inline int getColumn()const override{return column;} //it is the getter that returns the value of column
    virtual inline void setMove(const char movedir, const int movecount)override{move_direction=movedir; move_count=movecount;} //it is the setter that sets the value of movement informations.

    virtual int numberOfMoves()const override; // Returns the number of moves made on the board
    virtual void lastMove(Tetromino& lastObject)const override; // Fills the given Tetromino object with the data for the last move made on the board
    virtual void writeToFile(string filename)override; // Writes the board data and moves to the specified file
    virtual void readFromFile(string filename)override; // Reads the board data and moves from the specified file
};

#endif