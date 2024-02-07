#include "tetris.h"

using namespace std;

namespace NS_tetris
{
	Tetris::Tetris(const int row, const int column)
	{//constructor with size of row and column
	    this->row=row;
	    this->column=column;
	    creating_board();
	    creating_animate_arr();
	}

	Tetris::Tetris()
	{//constructor

	}

	Tetris::~Tetris()
	{//destructor
		for (int i = 0; i < row; i++)
		{
			delete[] board[i];
			delete[] animate_arr[i];
		}

		delete[] board;
		delete[] animate_arr;

		board=nullptr;
		animate_arr=nullptr;
	}

	/*
	 * Function:    creating_board
	 * ----------------------
	 * It does: it creates a 2D board based on the input the user enters.
	 *
	 *
	 *
	 * returns: it doesn't return anything.
	 *
	 */
	void Tetris::creating_board()
	{
		board = new char*[row];

		for (int i = 0; i < row; i++) {
	        board[i] = new char[column];
	    }

	    for(int i=0; i<row; i++)
	    {
	        for(int k=0; k<column; k++)
	        {
	            board[i][k]=' ';
	        }
	    }
	}

	/*
	 * Function:    draw
	 * ----------------------
	 * It does: it prints the 2D board based on the input the user enters.
	 *
	 *
	 *
	 * returns: it doesn't return anything.
	 *
	 */
	void Tetris::draw()
	{
	    cout << "\e[1;1H\e[2J";
	    this_thread::sleep_for(chrono::milliseconds(500));

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
	            cout << board[i][x];
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
	bool Tetris::operator+=(const Tetromino& obj)
	{
		this->animate_row=obj.getShapeRow()-1;
		this->animate_column=column/2-1;

		for(int i=0; i<row; i++)
	    {
	        for(int k=0; k<column; k++)
	        {
	            animate_arr[i][k]=board[i][k]; //clearing previous move
	        }
	    }

		for (int i = 0; i < obj.getShapeRow(); i++)
		{
			for (int j = 0; j < obj.getShapeColumn(); j++)
			{
				//checks top of the board is suitable for this tetromino
				if(board[0+i][column/2-1+j]!=' ' && obj.getShape()[i][j]!=' '){
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
				animate_arr[0+i][column/2-1+j]=obj.getShape()[i][j];
			}
		}
		draw_animate_arr();
		return 1;
	}

	/*
	 * Function:    creating_animate_arr
	 * ----------------------
	 * It does: it creates a 2D board which is using while animate process
	 *
	 *
	 *
	 * returns: it doesn't return anything.
	 *
	 */
	void Tetris::creating_animate_arr()
	{
		animate_arr = new char*[row];

		for (int i = 0; i < row; i++) {
	        animate_arr[i] = new char[column];
	    }

	    for(int i=0; i<row; i++)
	    {
	        for(int k=0; k<column; k++)
	        {
	            animate_arr[i][k]=' ';
	        }
	    }
	}

	/*
	 * Function:    draw_animate_arr
	 * ----------------------
	 * It does: it prints the 2D animate board while animate process
	 *
	 *
	 *
	 * returns: it doesn't return anything.
	 *
	 */
	void Tetris::draw_animate_arr()
	{
		cout << "\e[1;1H\e[2J";
	    this_thread::sleep_for(chrono::milliseconds(500));
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
	            cout << animate_arr[i][x];
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
	void Tetris::animate(const Tetromino& obj)
	{
		int placed=0;
		int temp_move=move_count;
		while(placed==0 && temp_move>0) //left-right
		{
			if(animate_column==0) break; //checks for left side of board
			if((animate_column+obj.getShapeColumn())==column) break; //checks for right side of board
			
			for(int i=0; i<row; i++)
		    {
		        for(int k=0; k<column; k++)
		        {
		            animate_arr[i][k]=board[i][k]; //clearing previous move
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
								if(animate_column+j+1<column && animate_arr[animate_row-(obj.getShapeRow()-1)+i][animate_column+j+1]!=' ')
								{
									placed=1;
								}
							}
							else if(obj.getShape()[i][j-1]!=' ')
							{
								if(animate_column+j-1+1<column && animate_arr[animate_row-(obj.getShapeRow()-1)+i][animate_column+j-1+1]!=' ')
								{
									placed=1;
								}
							}
							else if(obj.getShape()[i][j-2]!=' ')
							{
								if(animate_column+j-2+1<column && animate_arr[animate_row-(obj.getShapeRow()-1)+i][animate_column+j-2+1]!=' ')
								{
									placed=1;
								}
							}
						}
					}
				}
				if(placed==0) this->animate_column++;
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
								if(animate_column+j-1>0 && animate_arr[animate_row-(obj.getShapeRow()-1)+i][animate_column+j-1]!=' ')
								{
									placed=1;
								}
							}
							else if(obj.getShape()[i][j+1]!=' ')
							{
								if(animate_column+j-1+1<column && animate_arr[animate_row-(obj.getShapeRow()-1)+i][animate_column+j+1-1]!=' ')
								{
									placed=1;
								}
							}
							else if(obj.getShape()[i][j+2]!=' ')
							{
								if(animate_column+j-2+1<column && animate_arr[animate_row-(obj.getShapeRow()-1)+i][animate_column+j+2-1]!=' ')
								{
									placed=1;
								}
							}
						}
					}
				}
				if(placed==0) this->animate_column--;
			}

			for (int i = 0; i < obj.getShapeRow(); i++)
			{
				for (int j = 0; j < obj.getShapeColumn(); j++)
				{
					//animating shape
					if(obj.getShape()[i][j]==' ') continue;
					animate_arr[animate_row-(obj.getShapeRow()-1)+i][animate_column+j]=obj.getShape()[i][j];
				}
			}

			draw_animate_arr();
			temp_move--;
		}
		placed=0;

		while(true) //GOING DOWN
		{
			if(animate_row==row) break; //the condition which is the bottom of board

			for(int i=0; i<row; i++)
		    {
		        for(int k=0; k<column; k++)
		        {
		            animate_arr[i][k]=board[i][k]; //clearing previous move
		        }
		    }

		    for (int i = 0; i < obj.getShapeRow(); i++)
			{
				for (int j = 0; j < obj.getShapeColumn(); j++)
				{
					if (obj.getShape()[i][j]!=' ')
					{
						if(animate_row-(obj.getShapeRow()-1)+i+1<row && animate_arr[animate_row-(obj.getShapeRow()-1)+i+1][animate_column+j]!=' ')
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
					animate_arr[animate_row-(obj.getShapeRow()-1)+i][animate_column+j]=obj.getShape()[i][j];
				}
			}
			draw_animate_arr();
			if(placed==1) break;
			this->animate_row++;
		}

		for(int i=0; i<row; i++)
	    {
	        for(int k=0; k<column; k++)
	        {
	            board[i][k]=animate_arr[i][k]; //assigning to board
	        }
	    }
	}
}