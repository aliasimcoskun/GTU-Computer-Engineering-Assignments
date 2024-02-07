#ifndef ABSTRACT_H
#define ABSTRACT_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "tetromino.h"

class Abstract
{
public:
    // Constructors and destructors
    Abstract() {};
    virtual ~Abstract() {};

    // Member functions
    virtual bool operator+=(const Tetromino& obj) = 0; //it adds a Tetromino to top of the board by using operator overloading.

    virtual void creating_board() = 0; //it creates a board based on the input the user enters.
    virtual void draw() = 0; //it prints the board based on the input the user enters.

    virtual void creating_animate_arr() = 0; //it creates a board which is using while animate process
    virtual void draw_animate_arr() = 0;	//it prints the animate board while animate process

    virtual void animate(const Tetromino& obj) = 0; //This function takes care of every step of the animate process.

    virtual inline int getRow()const  = 0; //it is the getter that returns the value of row
    virtual inline int getColumn()const  = 0; //it is the getter that returns the value of column
    virtual inline void setMove(const char movedir, const int movecount) = 0; //it is the setter that sets the value of movement informations.

    virtual int numberOfMoves()const = 0; // Returns the number of moves made on the board
    virtual void lastMove(Tetromino& lastObject)const = 0; // Fills the given Tetromino object with the data for the last move made on the board
    
    virtual void writeToFile(string filename) = 0; // Writes the board data and moves to the specified file
    virtual void readFromFile(string filename) = 0; // Reads the board data and moves from the specified file

protected:
    int numberofstep; //that is using for numberOfMoves function.
};


#endif