#include "tetromino.h"
#include "tetris.h"

using namespace std;

vector <Tetromino> Tetromino:: vect_tetro; //1D Tetromino vector for shapes
vector <vector<char>> Tetris:: board; //2D char vector for board
vector <vector<char>> Tetris:: animate_vector; //2D char vector for animating

int main()
{
    Tetris x; //object of Tetris class

    vector <char> tetrominos;
    int row, column;
    bool gameover=1;

    cout << "Enter the size of board(row column):" << endl;
    cin >> row;
    cin >> column;
    x=Tetris(row, column); //constructor

    char type;
    int i=0;

    while(1)
    {
        if(gameover==0) //checks the end of game according to the 'return' of canFit function
        {
            cout << endl;
            cout << "GAME OVER!\n" << endl;
            break;
        }
        cout << "\n\nEnter a Tetromino type (I, O, T, J, L, S, Z):" << endl;
        cin >> type;
        if(type=='Q' || type=='q')
        {
            cout << "You want to quit. Goodbye!" << endl;
            break;
        }
        if(type=='j' || type=='J'){
            Tetromino::vect_tetro.push_back(Tetromino(Shapes::J));
        }
        if(type=='i' || type=='I'){
            Tetromino::vect_tetro.push_back(Tetromino(Shapes::I));
        }
        if(type=='o' || type=='O'){
            Tetromino::vect_tetro.push_back(Tetromino(Shapes::O));
        }
        if(type=='t' || type=='T'){
            Tetromino::vect_tetro.push_back(Tetromino(Shapes::T));
        }
        if(type=='l' || type=='L'){
            Tetromino::vect_tetro.push_back(Tetromino(Shapes::L));
        }
        if(type=='s' || type=='S'){
            Tetromino::vect_tetro.push_back(Tetromino(Shapes::S));
        }
        if(type=='z' || type=='Z'){
            Tetromino::vect_tetro.push_back(Tetromino(Shapes::Z));
        }
        gameover=Tetromino::vect_tetro[i].canFit(x);
        i++;
        Tetris::printmyboard(row, column);
    }
}