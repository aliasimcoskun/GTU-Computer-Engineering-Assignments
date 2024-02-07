#include "Tetris1Darray.h"
#include "tetromino.h"

Tetris1Darray::Tetris1Darray(const int row, const int column)
{
    this->row=row;
    this->column=column;
    creating_board();
    creating_animate_arr();    
}

// Tetris1Darray::Tetris1Darray()
// {//constructor

// }

Tetris1Darray::~Tetris1Darray()
{//destructor
	delete[] board;
	delete[] animate_arr;

	board=nullptr;
	animate_arr=nullptr;
}

/*
 * Function:    creating_board
 * ----------------------
 * It does: it creates a 1D array board based on the input the user enters.
 *
 *
 *
 * returns: it doesn't return anything.
 *
 */
void Tetris1Darray::creating_board()
{
	board = new char[row*column];

	int counter=0;

    for(int i=0; i<row; i++)
    {
        for(int k=0; k<column; k++)
        {
            board[counter]=' ';
			counter++;
        }
    }
}

/*
 * Function:    draw
 * ----------------------
 * It does: it prints the 1D array board based on the input the user enters.
 *
 *
 *
 * returns: it doesn't return anything.
 *
 */
void Tetris1Darray::draw()
{
    cout << "\e[1;1H\e[2J";
    this_thread::sleep_for(chrono::milliseconds(500));

	int counter=0;

    for(int t=0; t<column+2; t++)
    {
        cout << "@";
    }
	cout << endl;
	for(int i=0; i<row; i++)
    {
    	cout << "@";
        for(int x=0; x<column; x++)
        {
            cout << board[counter];
			counter++;
        }
        cout << "@";
        cout << endl;
    }
    for(int t=0; t<column+2; t++)
    {
        cout << "@";
    }
    cout << endl;
}

/*
 * Function: operator+=
 * ----------------------
 * It does: it adds a Tetromino to top of the board by using operator overloading.
 *
 *
 *
 * returns: it returns boolean value(0 or 1) according to if tetromino placed on board or not.
 *
 */
bool Tetris1Darray::operator+=(const Tetromino& obj)
{
	this->animate_row=obj.getShapeRow()-1;
	this->animate_column=column/2-1;

	int counter=0;

	for(int i=0; i<row; i++)
    {
        for(int k=0; k<column; k++)
        {
            animate_arr[counter]=board[counter]; //clearing previous move
			counter++;
        }
    }

	for (int i = 0; i < obj.getShapeRow(); i++)
	{
		for (int j = 0; j < obj.getShapeColumn(); j++)
		{
			//checks top of the board is suitable for this tetromino
			if(board[(0+i)*column + column/2-1+j]!=' ' && obj.getShape()[i][j]!=' '){
				// cout << "RETURN!" << endl;
				return 0;
			}
		}
	}

	for (int i = 0; i < obj.getShapeRow(); i++)
	{
		for (int j = 0; j < obj.getShapeColumn(); j++)
		{
			if(obj.getShape()[i][j]==' ') continue;
			animate_arr[(0+i)*column + column/2-1+j]=obj.getShape()[i][j];
		}
	}
	draw_animate_arr();
	return 1;
}

/*
 * Function:    creating_animate_arr
 * ----------------------
 * It does: it creates a 1D array board which is using while animate process
 *
 *
 *
 * returns: it doesn't return anything.
 *
 */
void Tetris1Darray::creating_animate_arr()
{
	animate_arr = new char[row*column];

	int counter=0;

    for(int i=0; i<row; i++)
    {
        for(int k=0; k<column; k++)
        {
            animate_arr[counter]=' ';
			counter++;
        }
    }
}

/*
 * Function:    draw_animate_arr
 * ----------------------
 * It does: it prints the 1D array animate board while animate process
 *
 *
 *
 * returns: it doesn't return anything.
 *
 */
void Tetris1Darray::draw_animate_arr()
{
	cout << "\e[1;1H\e[2J";
    this_thread::sleep_for(chrono::milliseconds(500));

	int counter=0;

	for(int t=0; t<column+2; t++)
    {
        cout << "@";
    }
	cout << endl;
	for(int i=0; i<row; i++)
    {
    	cout << "@";
        for(int x=0; x<column; x++)
        {
            cout << animate_arr[counter];
			counter++;
        }
        cout << "@";
        cout << endl;
    }
    for(int t=0; t<column+2; t++)
    {
        cout << "@";
    }
    cout << endl;
}

/*
 * Function:    animate
 * ----------------------
 * It does: This function takes care of every step of the animate process.
 *
 *
 *
 * returns: it doesn't return anything.
 *
 */
void Tetris1Darray::animate(const Tetromino& obj)
{
	numberofstep=0;
	int placed=0;
	int temp_move=move_count;
	int counter=0;
	while(placed==0 && temp_move>0) //left-right
	{
		if(animate_column==0) break; //checks for left side of board
		if((animate_column+obj.getShapeColumn())==column) break; //checks for right side of board
		counter=0;
		for(int i=0; i<row; i++)
	    {
	        for(int k=0; k<column; k++)
	        {
	            animate_arr[counter]=board[counter]; //clearing previous move
				counter++;
	        }
	    }
		
	    if(move_direction=='R' || move_direction=='r') //checks moving right
	    {
			for (int i = 0; i < obj.getShapeRow(); i++)
			{
				for (int j = 0; j < obj.getShapeColumn(); j++)
				{
					if(j==obj.getShapeColumn()-1)
					{
						if(obj.getShape()[i][j]!=' ')
						{
							if(animate_column+j+1<column && animate_arr[(animate_row-(obj.getShapeRow()-1)+i)*column + animate_column+j+1]!=' ')
							{
								placed=1;
							}
						}
						else if(obj.getShape()[i][j-1]!=' ')
						{
							if(animate_column+j-1+1<column && animate_arr[(animate_row-(obj.getShapeRow()-1)+i)*column + animate_column+j-1+1]!=' ')
							{
								placed=1;
							}
						}
						else if(obj.getShape()[i][j-2]!=' ')
						{
							if(animate_column+j-2+1<column && animate_arr[(animate_row-(obj.getShapeRow()-1)+i)*column + animate_column+j-2+1]!=' ')
							{
								placed=1;
							}
						}
					}
				}
			}
			if(placed==0){
                this->animate_column++;
                numberofstep++;
            }
		}
		if(move_direction=='L' || move_direction=='l') //checks moving left
		{
			for (int i = 0; i < obj.getShapeRow(); i++)
			{
				for (int j = 0; j < obj.getShapeColumn(); j++)
				{
					if(j==0)
					{
						if(obj.getShape()[i][j]!=' ') //burda da
						{
							if(animate_column+j-1>0 && animate_arr[(animate_row-(obj.getShapeRow()-1)+i)*column + animate_column+j-1]!=' ')
							{
								placed=1;
							}
						}
						else if(obj.getShape()[i][j+1]!=' ')
						{
							if(animate_column+j-1+1<column && animate_arr[(animate_row-(obj.getShapeRow()-1)+i)*column + animate_column+j+1-1]!=' ')
							{
								placed=1;
							}
						}
						else if(obj.getShape()[i][j+2]!=' ')
						{
							if(animate_column+j-2+1<column && animate_arr[(animate_row-(obj.getShapeRow()-1)+i)*column + animate_column+j+2-1]!=' ')
							{
								placed=1;
							}
						}
					}
				}
			}
			if(placed==0){
                this->animate_column--;
                numberofstep++;
            }
		}

		for (int i = 0; i < obj.getShapeRow(); i++)
		{
			for (int j = 0; j < obj.getShapeColumn(); j++)
			{
				//animating shape
				if(obj.getShape()[i][j]==' ') continue;
				animate_arr[(animate_row-(obj.getShapeRow()-1)+i)*column + animate_column+j]=obj.getShape()[i][j];
			}
		}

		draw_animate_arr();
		temp_move--;
	}
	placed=0;

	while(true) //GOING DOWN
	{
		if(animate_row==row) break; //the condition which is the bottom of board
		counter=0;
		for(int i=0; i<row; i++)
	    {
	        for(int k=0; k<column; k++)
	        {
	            animate_arr[counter]=board[counter]; //clearing previous move
	        	counter++;
			}
	    }

	    for (int i = 0; i < obj.getShapeRow(); i++)
		{
			for (int j = 0; j < obj.getShapeColumn(); j++)
			{
				if (obj.getShape()[i][j]!=' ')
				{
					if(animate_row-(obj.getShapeRow()-1)+i+1<row && animate_arr[(animate_row-(obj.getShapeRow()-1)+i+1)*column + animate_column+j]!=' ')
					{
						placed=1;
						break;
					}
				}
			}
			if(placed==1) break;
		}

		for (int i = 0; i < obj.getShapeRow(); i++)
		{
			for (int j = 0; j < obj.getShapeColumn(); j++)
			{
				//animating shape
				if(obj.getShape()[i][j]==' ') continue;
				animate_arr[(animate_row-(obj.getShapeRow()-1)+i)*column + animate_column+j]=obj.getShape()[i][j];
			}
		}
		draw_animate_arr();
		if(placed==1) break;
		numberofstep++;
		this->animate_row++;
	}
	counter=0;
	for(int i=0; i<row; i++)
    {
        for(int k=0; k<column; k++)
        {
            board[counter]=animate_arr[counter]; //assigning to board
			counter++;
        }
    }
	if(placed==0)numberofstep--;
}

int Tetris1Darray::numberOfMoves()const
{
    return numberofstep;
}

void Tetris1Darray::lastMove(Tetromino& lastObject)const
{
    lastObject.print();
}

void Tetris1Darray::writeToFile(string filename)
{
    int counter=0;
    // Open the output file
    ofstream outFile(filename);
    if (!outFile)
    {
        throw runtime_error("Unable to open file for writing");
    }
    
    // Write the board data to the file
    for(int i=0; i<row; i++)
    {
        for(int x=0; x<column; x++)
        {
            outFile << board[counter];
			counter++;
        }
        outFile << endl;
    }

    // Close the output file
    outFile.close();
}

void Tetris1Darray::readFromFile(string filename)
{
    // Open the input file
    ifstream inFile(filename);
    if (!inFile)
    {
        throw runtime_error("Unable to open file for reading");
    }

    vector<char> readboard;
    readboard.resize(row*column);

	string cursor;
	int counter=0;

    for(int x=0; x<row; x++)
    {
        getline(inFile, cursor);
        for (int i  = 0; i < column; i++){
            readboard[counter]=cursor[i];
            counter++;
        }
    }
    inFile.close();

    counter=0;
    for(int t=0; t<column+2; t++)
    {
        cout << "@";
    }
	cout << endl;
	for(int i=0; i<row; i++)
    {
    	cout << "@";
        for(int x=0; x<column; x++)
        {
            cout << readboard[counter];
            counter++;
        }
        cout << "@";
        cout << endl;
    }
    for(int t=0; t<column+2; t++)
    {
        cout << "@";
    }
    cout << endl;
}