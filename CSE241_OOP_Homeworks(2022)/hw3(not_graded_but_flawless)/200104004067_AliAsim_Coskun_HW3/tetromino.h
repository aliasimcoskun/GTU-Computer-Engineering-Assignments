#ifndef TETROMINO_H
#define TETROMINO_H

#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

namespace NS_tetris
{
    enum class Shapes //enum class of the tetromino shapes
    {
        I,

        J,

        L,

        O,

        S,

        T,

        Z
    };

    class Tetromino
    {
    private:
        char** shape; //2d array that holding shapes

        int shape_row; //the integer value that holding row size of shape
        int shape_column; //the integer value that holding column size of shape

    public:
        char** getShape()const{return shape;}; //the getter which provide us to get 2d shape array
        
        int getShapeRow()const{return shape_row;}; //the getter which provide us to get value of row size of shape
        int getShapeColumn()const{return shape_column;}; //the getter which provide us to get value of column size of shape
        
        Tetromino(Shapes tetroShape); //constructor

        Tetromino(); //constructor

        ~Tetromino(); //destructor

        void print()const; //it prints the tetrominos

        void rotate(char direction, int row, int column); //it rotates the tetrominos with given direction

        void init(Shapes tetroShape); //it fills the 2d shape array with constructor.
    };
}

#endif