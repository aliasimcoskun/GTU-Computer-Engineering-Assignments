#include "tetromino.h"

using namespace std;

vector <Tetromino> Tetromino:: vect_tetro; //1D Tetromino vector for shapes
vector<vector<char>>Tetromino:: board; //2D char vector for board

int main()
{
    int tetrominoNumber;
    vector <char> tetrominos;

    cout << "How many tetrominos?" << endl;
    cin >> tetrominoNumber;


    cout << "\n\nWhat are the types?" << endl;
    for (int i=0; i<tetrominoNumber; i++)
    {
        char type;
        cin >> type;
        tetrominos.push_back(type);
    }

    
    for (int k=0; k<tetrominoNumber; k++){
        if(tetrominos[k]=='j' || tetrominos[k]=='J'){
            Tetromino:: vect_tetro.push_back(Tetromino(Shapes::J));
        }
        if(tetrominos[k]=='i' || tetrominos[k]=='I'){
           Tetromino:: vect_tetro.push_back(Tetromino(Shapes::I));
        }
        if(tetrominos[k]=='o' || tetrominos[k]=='O'){
          Tetromino::  vect_tetro.push_back(Tetromino(Shapes::O));
        }
        if(tetrominos[k]=='t' || tetrominos[k]=='T'){
            Tetromino::vect_tetro.push_back(Tetromino(Shapes::T));
        }
        if(tetrominos[k]=='l' || tetrominos[k]=='L'){
           Tetromino:: vect_tetro.push_back(Tetromino(Shapes::L));
        }
        if(tetrominos[k]=='s' || tetrominos[k]=='S'){
           Tetromino:: vect_tetro.push_back(Tetromino(Shapes::S));
        }
        if(tetrominos[k]=='z' || tetrominos[k]=='Z'){
          Tetromino::  vect_tetro.push_back(Tetromino(Shapes::Z));
        }
    }

    cout << "\n\nYour tetrominos"<< endl;
    for (int i=0; i<tetrominoNumber; i++)
    {
        Tetromino::vect_tetro[i].print();
        cout << endl;
    }

    
    cout << "Horizantally best-fit tetrominos" << endl;
    Tetromino::create_board();
    for (int i=0; i<tetrominoNumber; i++)
    {
        Tetromino::vect_tetro[i].canFit();
    }
    Tetromino::print_board();
}