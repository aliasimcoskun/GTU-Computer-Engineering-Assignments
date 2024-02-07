#ifndef TETROMINO_H
#define TETROMINO_H

#include <vector>
#include <iostream>
#include <string>
#include "tetris.h"
#include <chrono>
#include <thread>
class Tetromino;
using namespace std;

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
    vector<vector<char>> shape; //2d vector that holding shapes

public:
    static vector <Tetromino> vect_tetro; //2d vector where tetrominos are placed as chars after being processed in the constructor

    Tetromino(Shapes tetroShape); //constructor

    Tetromino(); //constructor

    void print()const; //it prints the tetrominos

    void rotate(string); //it rotates the tetrominos

    bool canFit(Tetris x); //it checks if the tetromino can fit in the board

    void init(Shapes tetroShape); //it fills the 2d shape vector with constructor.
};


#endif