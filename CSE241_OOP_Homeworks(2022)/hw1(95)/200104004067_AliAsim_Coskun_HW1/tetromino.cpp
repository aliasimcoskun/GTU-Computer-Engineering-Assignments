#include "tetromino.h"

Tetromino::Tetromino(Shapes tetroShape)
{// constructor
    init(tetroShape);
}
Tetromino::Tetromino()
{// constructor
    init(Shapes::I);
}

void Tetromino::print()const //it prints the tetromino
{
    if(shape[0][0]=='I') cout << "I" << endl;
    for(int k=0; k<3 ; k++)
    {
        for(int i=0; i<3; i++)
        {
            cout << shape[k][i];
        }
        cout << endl;
    }
}

void Tetromino::rotate(string direction) //it rotate the tetromino
{
    vector<vector<char>> temp(shape[0].size(), vector<char>(shape.size()));

    int counter1 = 0;   // first counter variable
    int counter2 = 0;   // second counter variable

    for(counter1 = 0; counter1 < shape.size(); counter1++)
    {
        for(counter2 = 0; counter2 < shape[0].size(); counter2++)
        {
            // rotate of clockwise
            if(direction=="right") temp[counter2][temp[0].size()-counter1-1] = shape[counter1][counter2];
            // rotate of counter-clockwise
            else if(direction=="left") temp[temp.size()-counter2-1][counter1] = shape[counter1][counter2];
        }
    }

    shape = temp;  
}

void Tetromino::init(Shapes tetroShape) //it fills the 2d shape vector with constructor
{
    if (tetroShape == Shapes::I)
    {
        shape = {{'I', ' ', ' '},
                 {'I', ' ', ' '},
                 {'I', ' ', ' '}};
    }
    else if (tetroShape == Shapes::J)
    {
        shape = {{' ', 'J', ' '},
                 {' ', 'J', ' '},
                 {'J', 'J', ' '}};
    }
    else if (tetroShape == Shapes::L)
    {
        shape = {{' ', ' ', ' '},
                 {'L', 'L', 'L'},
                 {'L', ' ', ' '}};
    }
    else if (tetroShape == Shapes::O)
    {
        shape = {{' ', ' ', ' '},
                 {'O', 'O', ' '},
                 {'O', 'O', ' '}};
    }
    else if (tetroShape == Shapes::S)
    {
        shape = {{' ', ' ', ' '},
                 {' ', 'S', 'S'},
                 {'S', 'S', ' '}};
    }
    else if (tetroShape == Shapes::T)
    {
        shape = {{'T', ' ', ' '},
                 {'T', 'T', ' '},
                 {'T', ' ', ' '}};
    }
    else if (tetroShape == Shapes::Z)
    {
        shape = {{' ', ' ', ' '},
                 {'Z', 'Z', ' '},
                 {' ', 'Z', 'Z'}};
    }
}

void Tetromino::create_board() // it creates board 1 time.
{
    board = {};
    board.resize(5, vector<char>(25));
    for(int i=0; i<5; i++)
    {
        for(int k=0; k<25; k++)
        {
            board[i][k]=' ';
        }
    }

}

void Tetromino::print_board() // it prints board whenever you want.(in my code 1 time.)
{
    for(auto x:board)
    {
        for(auto i:x)
        {
            cout << i;
        }
        cout << endl;
    }
}

bool Tetromino::canFit( ) // check if the tetromino can fit in the board
{
    int flag=0, flag1=0, a_flag=0, b_flag=0, c_flag=0, check_first_column=0, check_last_row=0;
    for(int k=0; k<25; k++) //for column
    {
        if(board[4][k]!=' ') continue;
        else
        {
            for(int m=0; m<4; m++) //for rotate
            {
                flag=0;
                a_flag=0;
                b_flag=0;
                c_flag=0;
                check_first_column=0;
                check_last_row=0;

                for(int t=0; t<3; t++)
                {//first column //check
                    if(shape[t][0]!=' ')
                    {
                        check_first_column=1;
                    } 
                }
                for(int t=0; t<3; t++)
                {//last row //check
                    if(shape[2][t]!=' ')
                    {
                        check_last_row=1;
                    } 
                }
                
                for (int i=0; i<3; i++) //it checks if there is no ' ' in the 3 by 3 field
                {
                    for (int j=0; j<3; j++)
                    {
                        if(check_first_column==0 || check_last_row==0)
                        {   
                            if(check_first_column==0)
                            {
                                if(j==2) continue;
                                if(board[2+i][k+j]!=' ' && shape[i][j+1]!=' ')
                                {
                                    flag=1;
                                    break;
                                }
                            }
                            if(check_last_row==0)
                            {
                                if(i==2) continue;
                                if(board[2+i+1][k-1+j]!=' ' && shape[i][j]!=' ')
                                {
                                    flag=1;
                                    break;
                                }
                            }
                        }
                        else if(board[2+i][k-1+j]!=' ' && shape[i][j]!=' ')
                        {
                            flag=1;
                            break;
                        }
                    }
                    if(flag==1) //for break
                    {
                        break;
                    }
                }
                if(check_first_column==0 || check_last_row==0)
                {   
                    if(check_first_column==0)
                    {
                        if(board[4][k-1+0+1]==' ' && shape[2][0+1]==' ')
                        {
                            flag=1;
                        }
                    }
                    if(check_last_row==0)
                    {
                        if(board[4][k-1+0]==' ' && shape[2-1][0]==' ')
                        {
                            flag=1;
                        }
                    }
                }
                else if(board[4][k-1+0]==' ' && shape[2][0]==' ')
                {
                    flag=1;
                }
                if(flag==1)
                {
                    rotate("right");
                    continue;
                }
                if(flag==0)
                {
                    for(int t=0; t<3; t++)
                    {
                        if(shape[t][0]!=' ') a_flag=1; //first column
                        if(shape[2][t]!=' ') b_flag=1; //last row
                        if(shape[t][2]!=' ') c_flag=1; //last column
                        //first row?
                    }
                    
                    if(b_flag==0 || a_flag==0 || c_flag==0)
                    {
                        if(b_flag==0)
                        {
                            shape.erase(next(begin(shape), 2));
                            for (int i=0; i<2; i++)
                            {
                                for (int j=0; j<3; j++)
                                {
                                    if(shape[i][j]==' ') continue; //it skips the "spaces".
                                    board[2+i+1][k-1+j]=shape[i][j];
                                }
                            }
                        }
                        if(a_flag==0)
                        {
                            for(auto& row:shape) row.erase(next(row.begin(), 0)); //auto //range for loops
                            for (int i=0; i<3; i++)
                            {
                                for (int j=0; j<2; j++)
                                {
                                    if(shape[i][j]==' ') continue; //it skips the "spaces".
                                    board[2+i][k+j]=shape[i][j];
                                }
                            }
                        }
                        if(c_flag==0)
                        {
                            for(auto& row:shape) row.erase(next(row.begin(), 2)); //auto //range for loops
                            for (int i=0; i<3; i++)
                            {
                                for (int j=0; j<2; j++)
                                {
                                    if(shape[i][j]==' ') continue; //it skips the "spaces".
                                    board[2+i][k-1+j]=shape[i][j];
                                }
                            }
                        }
                    }
                    else
                    {
                        for (int i=0; i<3; i++)
                        {
                            for (int j=0; j<3; j++)
                            {                                
                                if(shape[i][j]==' ') continue; //it skips the "spaces".
                                board[2+i][k-1+j]=shape[i][j];
                            }
                        }
                    }  
                    return 1; //if process is succesfully done: True
                }
            }
        }
    }
    return 0; //if it is not done: False
}