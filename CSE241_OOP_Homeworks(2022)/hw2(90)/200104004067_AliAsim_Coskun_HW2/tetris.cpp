#include "tetromino.h"
#include "tetris.h"

using namespace std;

Tetris::Tetris(int row, int column)
{//constructor
	myboard(row, column);
    animatingshape(row, column);
    this->row=row;
    this->column=column;
}

Tetris::Tetris()
{//constructor

}

/*
 * Function:    myboard
 * ----------------------
 * It does: it creates a 2D board based on the input the user enters.
 *
 *
 *
 * returns: it doesn't return anything.
 *
 */
void Tetris::myboard(int row, int column)
{
	board = {};
    board.resize(row, vector<char>(column));
    for(int i=0; i<row; i++)
    {
        for(int k=0; k<column; k++)
        {
            board[i][k]=' ';
        }
    }
}

/*
 * Function:    printmyboard
 * ----------------------
 * It does: it prints the 2D board based on the input the user enters.
 *
 *
 *
 * returns: it doesn't return anything.
 *
 */
void Tetris::printmyboard(int row, int column)
{
    cout << "\e[1;1H\e[2J";
    this_thread::sleep_for(chrono::milliseconds(500));

    for(int t=0; t<column+2; t++)
    {
        cout << "@";
    }
	cout << endl;
	for(auto x:board)
    {
    	cout << "@";
        for(auto i:x)
        {
            cout << i;
        }
        cout << "@";
        cout << endl;
    }
    for(int t=0; t<column+2; t++)
    {
        cout << "@";
    }
}

/*
 * Function:    animatingshape
 * ----------------------
 * It does: it creates a 2D vector with the same sizes as the 'board' to do the animate process.
 *
 *
 *
 * returns: it doesn't return anything.
 *
 */
void Tetris::animatingshape(int row, int column)
{
    animate_vector = {};
    animate_vector.resize(row, vector<char>(column));
    for(int i=0; i<row; i++)
    {
        for(int k=0; k<column; k++)
        {
            animate_vector[i][k]=' ';
        }
    }
}

/*
 * Function:    printanimatingshape
 * ----------------------
 * It does: it prints every step of the animate process.
 *
 *
 *
 * returns: it doesn't return anything.
 *
 */
void Tetris::printanimatingshape()
{
    cout << "\e[1;1H\e[2J";
    this_thread::sleep_for(chrono::milliseconds(500));

    int column = animate_vector[0].size();
    cout << endl;
    for(int t=0; t<column+2; t++)
    {
        cout << "@";
    }
    cout << endl;
    for(auto t:animate_vector)
    {
        cout << "@";
        for(auto x:t)
        {
            cout << x;
        }
        cout << "@" << endl;
    }
    for(int t=0; t<column+2; t++)
    {
        cout << "@";
    }
    cout << endl;
    cout << endl;
}

/*
 * Function:    add
 * ----------------------
 * It does: it adds the input shape to the top of the 'board' to start the animate process
 *
 *
 *
 * returns: it doesn't return anything.
 *
 */
void Tetris::add(int column, vector <vector<char>> shape)
{
    int shaperow = shape.size();
    int flag=0;
    for (int i = 0; i < shaperow; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (shape[0][0]=='L' && shape[0][1]=='L' && shape[1][1]=='L')
            {
                column-=1;
                flag=1;
                break;
            }
            if (shape[1][0]=='L' && shape[1][1]=='L' && shape[0][1]!='L')
            {
                column-=1;
                flag=1;
                break;
            }
            if (shape[0][0]=='I' && column==1)
            {
                column=column-1;
                flag=1;
                break;
            }
            if (shape[0][1]=='I' && shape[0][0]=='I')
            {
                column=column-1;
                flag=1;
                break;
            }
            if (shape[1][1]=='T')
            {
                column=column-1;
                if (shape[0][1]=='T' && shape[1][1]=='T' && shape[1][0]=='T')
                {
                    column+=1;
                }
                flag=1;
                break;
            }
        }
        if (flag==1)
        {
            break;
        }
    }
    for (int i = 0; i < shaperow; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (shape[i][j]=='\0')
            {
                continue;
            }
            if (shape[i][j]==' ')
            {
                continue;
            }
            animate_vector[i][column+j]=shape[i][j];
        }
    }
}

/*
 * Function:    animate
 * ----------------------
 * It does: This function takes care of every step of the animate process. It calls the necessary functions (such as add, print) in it.
 *
 *
 *
 * returns: it doesn't return anything.
 *
 */
void Tetris::animate(int row, int column, vector <vector<char>> shape)
{
    int shaperow= shape.size();
    int shapecolumn = shape[0].size();

    animate_vector=board;
    add(column, shape);
    printanimatingshape();
    animate_vector=board;

    int flag=0;
    for (int i = 0; i < shaperow; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (shape[0][0]=='L' && shape[0][1]=='L' && shape[1][1]=='L')
            {
                column-=1;
                flag=1;
                break;
            }
            if (shape[1][0]=='L' && shape[1][1]=='L' && shape[0][1]!='L')
            {
                column-=1;
                flag=1;
                break;
            }
            if (shape[0][0]=='I' && column==1)
            {
                column=column-1;
                flag=1;
                break;
            }
            if (shape[0][1]=='I' && shape[0][0]=='I')
            {
                column=column-1;
                flag=1;
                break;
            }
            if (shape[1][1]=='T')
            {
                column=column-1;
                if (shape[0][1]=='T' && shape[1][1]=='T' && shape[1][0]=='T')
                {
                    column+=1;
                }
                flag=1;
                break;
            }
        }
        if (flag==1)
        {
            break;
        }
    }

    int x=0;
    for (int t = 1; t < row-2; t++)
    {
        x=0;
        for (int i = t; i < t+3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if(shaperow==2 && x==2)
                {
                    if (animate_vector[i][column+j]!=' ')
                    {
                        
                    }
                    else animate_vector[i][column+j]=' ';
                }
                else if(shapecolumn==2 && j==2)
                {
                    if(animate_vector[i][column+j]!=' ')
                    {
                        
                    }
                    else animate_vector[i][column+j]=' ';
                }
                else if (shape[x][j]=='#')
                {
                    if (animate_vector[i][column+j]!=' ')
                    {
                        
                    }
                    else animate_vector[i][column+j]=' ';
                    continue;
                }
                else
                {
                    if(shape[x][j]==' ');
                    else animate_vector[i][column+j]=shape[x][j];                    
                }
            }
            x++;
        }
        printanimatingshape();
        animate_vector=board;
    }
}