#include "tetromino.h"
#include "tetris.h"

Tetromino::Tetromino(Shapes tetroShape)
{// constructor
    init(tetroShape);
}
Tetromino::Tetromino()
{// constructor
    init(Shapes::I);
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
    for(int k=0; k<3 ; k++)
    {
        for(int i=0; i<3; i++)
        {
            cout << shape[k][i];
        }
        cout << endl;
    }
}

/*
 * Function:    rotate
 * ----------------------
 * It does: it rotates the tetromino
 *
 *
 *
 * returns: it doesn't return anything.
 *
 */
void Tetromino::rotate(string direction)
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

/*
 * Function:    init
 * ----------------------
 * It does: it fills the 2d shape vector with constructor.
 *
 *
 *
 * returns: it doesn't return anything.
 *
 */
void Tetromino::init(Shapes tetroShape)
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

/*
 * Function:    canFit
 * ----------------------
 * It does: it checks if the tetromino can fit in the board
 *
 *
 *
 * returns: if the tetromino is successfully placed on the board it will return 1, otherwise it will return 0.
 *
 */
bool Tetromino::canFit(Tetris myObject)
{
    int flag=0, flag1=0, a_flag=0, b_flag=0, c_flag=0, check_first_column=0, check_last_row=0, d_flag=0, last_flag=0;
    int endoftheboard=0, vertical_i_check=0, check_first_row=0, check_second_row=0;
    int gameover=0;

    int column=myObject.getColumn();
    int row=myObject.getRow();

    for(int p=row-1; p>=0; p--)
    {
        for(int k=0; k<column; k++) //for column
        {   
            for(int m=0; m<4; m++) //for rotate
            {
                flag=0;
                a_flag=0;
                b_flag=0;
                c_flag=0;
                check_first_column=0;
                check_last_row=0;
                check_second_row=0;
                check_first_row=0;
                endoftheboard=0;
                d_flag=0;
                last_flag=0;
                for(int t=0; t<3; t++)
                {
                    if(shape[t][0]!=' ')
                    {
                        check_first_column=1;
                    } //first column
                    if(shape[2][t]!=' ')
                    {
                        check_last_row=1;
                    } //last row
                    if (shape[1][t]!=' ')
                    {
                        check_second_row=1;
                    } //second row
                    if(shape[0][t]!=' ')
                    {
                        check_first_row=1;
                    } //first row
                }
                for (int i=0; i<3; i++) //3'e 3'lük alanda ' ' olmayan var mı diye bakıyor
                {
                    for (int j=0; j<3; j++)
                    {
                        if(p+1-3+i==-1 && check_first_row!=0)
                        {
                            if (check_first_row!=0 && check_last_row==0)
                            {
                                break;
                            }
                            gameover=1;
                            flag=1;
                            break;
                        }
                        else if(p+1-3+i==-2 && check_second_row!=0)
                        {
                            gameover=1;
                            flag=1;
                            break;
                        }
                        else if(p+1-3+i==-1 && check_first_row==0)
                        {
                            if(i==2) continue;
                            if(Tetris::board[p+1-3+2+i][k-1+j]!=' ' && shape[i+1][j]!=' ')
                            {
                                break;
                            }
                        }
                        else if(p+1-3+i==-2 && check_second_row==0 && check_first_row==0)
                        {
                            if(Tetris::board[p+1-3+2][k-1+j]!=' ' && shape[2][j]!=' ')
                            {
                                break;
                            }
                        }
                        else if (p+1-3+i<0 && (check_first_row!=0 || check_second_row!=0))
                        {
                            gameover=1;
                            flag=1;
                            break;
                        }
                        else if(check_first_column==0 || check_last_row==0)
                        {
                            if(check_first_column==0)
                            {
                                if(j==2) continue;
                                if(Tetris::board[p+1-3+i][k+j]!=' ' && shape[i][j+1]!=' ')
                                {
                                    flag=1;
                                    break;
                                }
                            }
                            if(check_last_row==0)
                            {
                                if (Tetris::board[p+1-3+i][k-1]=='\0')
                                {
                                    flag=1;
                                    break;
                                }
                                if(i==2) continue;
                                if(Tetris::board[p+1-3+i+1][k-1+j]!=' ' && shape[i][j]!=' ')
                                {
                                    flag=1;
                                    break;
                                }
                            }
                        }
                        else if(Tetris::board[p+1-3+i][k-1+2]=='\0') //Tetris::board[p+1-3+i][k-1+2]=='\0'
                        {
                            endoftheboard=1;
                            continue;
                        }
                        else if(Tetris::board[p+1-3+i][k-1+j]!=' ' && shape[i][j]!=' ')
                        {
                            flag=1;
                            break;
                        }
                    }
                    if(endoftheboard==1)
                    {
                        for(int t=0; t<3; t++)
                        {
                            if((shape[t][1]!=' ') || (shape[t][2]!=' '))
                            {
                                vertical_i_check=1;
                            }
                        }
                        for (int i = 0; i < 3; i++)
                        {
                            for (int j = 0; j < 2; j++)
                            {
                                if(p+1-3+i<0)
                                {
                                    /* code */
                                }
                                else if(Tetris::board[p+1-3+i][k-1+1+j]!=' ')
                                {
                                    last_flag=1;
                                }
                            }
                        }
                        for(int i=0; i<3; i++)
                        {
                            for(int j=0; j<2; j++)
                            {
                                if(vertical_i_check==0)
                                {
                                    if(j==1) continue;
                                    if(last_flag==0)
                                    {
                                        if (i==0 && j==0)
                                        {
                                            myObject.animate(p,k,shape);
                                        }
                                        Tetris::board[p+1-3+i][k-1+1+j]=shape[i][j];
                                    }
                                    else
                                    {
                                        flag=1;
                                    }
                                }
                                else if(p+1-3+i<0)
                                {
                                    /* code */
                                }
                                else if(Tetris::board[p+1-3+i][k-1+j]!=' ' && shape[i][j]!=' ')
                                {
                                    flag=1;
                                    break;
                                }
                                else if(Tetris::board[p+1-3+i][k-1+2]=='\0' && shape[i][2]!=' ')
                                {
                                    flag=1;
                                    break;
                                }
                            }
                        }
                        if(vertical_i_check==0)
                        {
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
                        if(Tetris::board[p][k-1+0+1]==' ' && shape[2][0+1]==' ')
                        {
                            flag=1;
                        }
                    }
                    if(check_last_row==0)
                    {
                        if(shape[0][1]=='I')
                        {
                            for (int x = 0; x < 3; x++)
                            {
                                if(p+1-3==-1 && Tetris::board[p+1-2][k-1+x]!=' ')
                                {
                                    flag=1;
                                }
                            }
                        }
                        else if(Tetris::board[p][k-1+0]==' ' && shape[2-1][0]==' ')
                        {
                            flag=1;
                        }
                    }
                }
                else if(Tetris::board[p][k-1+0]==' ' && shape[2][0]==' ')
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
                    gameover=0;
                    if(p+1-3==-1 && check_first_row==0)
                    {
                        myObject.animate(p,k,shape);
                        for (int i = 0; i < 2; i++)
                        {
                            for (int j = 0; j < 3; j++)
                            {
                                if(shape[0][2]=='I')
                                {
                                    if(i==1) continue;
                                    if(shape[i+2][j]==' ') continue;
                                    Tetris::board[p+1-2+i][k-1+j]=shape[i+2][j];
                                }
                                else
                                {
                                    if(shape[i+1][j]==' ') continue;
                                    Tetris::board[p+1-2+i][k-1+j]=shape[i+1][j];
                                }
                            }
                        }
                    }
                    if (p+1-3==-2 && check_second_row==0)
                    {
                        myObject.animate(p,k,shape);
                        for (int j = 0; j < 3; j++)
                        {
                            if(shape[1][j]==' ') continue;
                            if(shape[2][j]==' ') continue;
                            Tetris::board[p+1-2][k-1+j]=shape[2][j];
                        }
                    }
                    for(int t=0; t<3; t++)
                    {
                        if(shape[t][0]!=' ') a_flag=1; //first column
                        if(shape[2][t]!=' ') b_flag=1; //last row
                        if(shape[t][2]!=' ') c_flag=1; //last column
                        if(shape[1][t]!=' ') d_flag=1; //second row for i
                    }
                    
                    if(b_flag==0 || a_flag==0 || c_flag==0)
                    {
                        if(b_flag==0)
                        {
                            shape.erase(next(begin(shape), 2));
                            myObject.animate(p,k,shape);
                            for (int i = 0; i < 2; i++)
                            {
                                for (int j = 0; j < 3; j++)
                                {
                                    if(shape[i][j]==' ') continue;
                                    Tetris::board[p+1-3+i+1][k-1+j]=shape[i][j];
                                }
                            }
                        }
                        if(a_flag==0)
                        {
                            for(auto& row:shape) row.erase(next(row.begin(), 0));
                            myObject.animate(p,k,shape);
                            for (int i = 0; i < 3; i++)
                            {
                                for (int j = 0; j < 2; j++)
                                {
                                    if(shape[i][j]==' ') continue;
                                    Tetris::board[p+1-3+i][k+j]=shape[i][j];
                                }
                            }
                        }
                        if(c_flag==0)
                        {
                            if(endoftheboard==1 && vertical_i_check==0);
                            else
                            {
                                for(auto& row:shape) row.erase(next(row.begin(), 2));
                                
                                myObject.animate(p,k,shape);
                                for (int i = 0; i < 3; i++)
                                {
                                    for (int j = 0; j < 2; j++)
                                    {
                                        if(shape[i][j]==' ') continue;
                                        else Tetris::board[p+1-3+i][k-1+j]=shape[i][j];
                                    }
                                }
                            } 
                        }
                    }
                    else
                    {
                        myObject.animate(p,k,shape);
                        for (int i=0; i<3; i++)
                        {
                            for (int j=0; j<3; j++)
                            {                                
                                if(shape[i][j]==' ') continue;
                                Tetris::board[p+1-3+i][k-1+j]=shape[i][j];
                            }
                        }
                    }  
                    return 1; //True
                }
            }
        }
    }
    if(gameover==1)
    {
        return 0;
    }
    return 0;
}