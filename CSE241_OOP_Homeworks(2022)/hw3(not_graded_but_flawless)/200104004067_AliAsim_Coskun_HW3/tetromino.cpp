#include "tetromino.h"

using namespace std;

namespace NS_tetris
{
    Tetromino::Tetromino(Shapes tetroShape)
    {// constructor
        init(tetroShape);
    }
    
    Tetromino::Tetromino()
    {// constructor
        init(Shapes::I);
    }

    Tetromino::~Tetromino()
    {// destructor
        for (int i = 0; i < shape_row; i++)
        {
            delete[] shape[i];
        }
        delete[] shape;

        shape=nullptr;
    }
    
    /*
     * Function:    print
     * ----------------------
     * It does: it prints the tetrominos
     *
     *
     *
     * returns: it doesn't return anything.
     *
     */
    void Tetromino::print()const
    {
        cout << endl;
        cout << "Selected Tetromino: " << endl;
        for(int k=0; k<shape_row ; k++)
        {
            for(int i=0; i<shape_column; i++)
            {
                cout << shape[k][i];
            }
            cout << endl;
        }
        cout << endl;
    }

    /*
     * Function:    rotate
     * ----------------------
     * It does: it rotates the tetrominos with given direction
     *
     *
     *
     * returns: it doesn't return anything.
     *
     */
    void Tetromino::rotate(char direction, int row, int column)
    {
        char** rotate = new char*[column]; //column and row swapped

        for (int i = 0; i < column; i++) {
            rotate[i] = new char[row]; //column and row swapped
        }

        if (direction=='L') //left
        {
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    rotate[j][i] = shape[i][j]; //transpose
                }
            }
            for (int i = 0; i < row; i++) {//row and column swapped
                int begin = 0;
                int end = column - 1;
                while (begin < end) {//row and column swapped
                    swap(rotate[begin][i], rotate[end][i]);
                    begin++;
                    end--;
                }
            }
        }
        if (direction=='R') //right
        {
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    rotate[j][i] = shape[i][j]; //transpose
                }
            }
            for (int i = 0; i < column; i++) {
                int begin = 0;
                int end = row - 1;
                while (begin < end) {
                    swap(rotate[i][begin], rotate[i][end]);
                    begin++;
                    end--;
                }
            }
        }
        
        this->shape_row=column;
        this->shape_column=row;
        this->shape=rotate;
    }

    /*
     * Function:    init
     * ----------------------
     * It does: it fills the 2d shape array with constructor.
     *
     *
     *
     * returns: it doesn't return anything.
     *
     */
    void Tetromino::init(Shapes tetroShape)
    {
        shape = new char*[3];

        for (int i = 0; i < 3; i++) {
            shape[i] = new char[3];
        }

        if (tetroShape == Shapes::I)
        {
            // {'I'}
            // {'I'}
            // {'I'}
            // {'I'}

            this->shape_row=4;
            this->shape_column=1;
            shape = new char*[shape_row];

            for (int i = 0; i < 4; i++) {
                shape[i] = new char[shape_column];
            }

            for (int i = 0; i < 4; i++)
            {
                for (int k = 0; k < 1; k++)
                {
                    shape[i][k]='I';
                }
            }
        }
        else if (tetroShape == Shapes::J)
        {
            //  {' ', 'J'}
            //  {' ', 'J'}
            //  {'J', 'J'}
            this->shape_row=3;
            this->shape_column=2;
            shape = new char*[shape_row];

            for (int i = 0; i < 3; i++) {
                shape[i] = new char[shape_column];
            }

            for (int i = 0; i < 3; i++)
            {
                for (int k = 0; k < 2; k++)
                {
                    if(i==0 && k==0) shape[i][k]=' ';
                    else if(i==1 && k==0) shape[i][k]=' ';
                    else shape[i][k]='J';
                }
            }
            
        }
        else if (tetroShape == Shapes::L)
        {
            // {'L', ' '}
            // {'L', ' '}
            // {'L', 'L'}

            this->shape_row=3;
            this->shape_column=2;
            shape = new char*[shape_row];

            for (int i = 0; i < 3; i++) {
                shape[i] = new char[shape_column];
            }

            for (int i = 0; i < 3; i++)
            {
                for (int k = 0; k < 2; k++)
                {
                    if(i==0 && k==1) shape[i][k]=' ';
                    else if(i==1 && k==1) shape[i][k]=' ';
                    else shape[i][k]='L';
                }
            }
            
        }
        else if (tetroShape == Shapes::O)
        {
            // {'O', 'O'}
            // {'O', 'O'}

            this->shape_row=2;
            this->shape_column=2;
            shape = new char*[shape_row];

            for (int i = 0; i < 2; i++) {
                shape[i] = new char[shape_column];
            }

            for (int i = 0; i < 2; i++)
            {
                for (int k = 0; k < 2; k++)
                {
                    shape[i][k]='O';
                }
            }
        }
        else if (tetroShape == Shapes::S)
        {
            // {' ', 'S', 'S'}
            // {'S', 'S', ' '}
            this->shape_row=2;
            this->shape_column=3;
            shape = new char*[shape_row];

            for (int i = 0; i < 2; i++) {
                shape[i] = new char[shape_column];
            }

            for (int i = 0; i < 2; i++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if(i==0 && k==0) shape[i][k]=' ';
                    else if(i==1 && k==2) shape[i][k]=' ';
                    else shape[i][k]='S';
                }
            }
        }
        else if (tetroShape == Shapes::T)
        {
            // {'T', 'T', 'T'}
            // {' ', 'T', ' '}

            this->shape_row=2;
            this->shape_column=3;
            shape = new char*[shape_row];

            for (int i = 0; i < 2; i++) {
                shape[i] = new char[shape_column];
            }

            for (int i = 0; i < 2; i++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if(i==1 && k==0) shape[i][k]=' ';
                    else if(i==1 && k==2) shape[i][k]=' ';
                    else shape[i][k]='T';
                }
            }
        }
        else if (tetroShape == Shapes::Z)
        {
            // {'Z', 'Z', ' '}
            // {' ', 'Z', 'Z'}

            this->shape_row=2;
            this->shape_column=3;
            shape = new char*[shape_row];

            for (int i = 0; i < 2; i++) {
                shape[i] = new char[shape_column];
            }

            for (int i = 0; i < 2; i++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if(i==1 && k==0) shape[i][k]=' ';
                    else if(i==0 && k==2) shape[i][k]=' ';
                    else shape[i][k]='Z';
                }
            }
        }
    }
}
