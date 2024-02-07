#ifndef TETROMINO_H
#define TETROMINO_H

#include <vector>
#include <iostream>
#include <string>

using namespace std;

enum class Shapes
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
    vector<vector<char>> shape;


public:
    static vector<vector<char>> board;

    static vector <Tetromino> vect_tetro;

    Tetromino(Shapes tetroShape);

    Tetromino();

    void print()const;

    void rotate(string);

    bool canFit();

    void init(Shapes tetroShape);

    static void print_board();

    static void create_board();
};

#endif