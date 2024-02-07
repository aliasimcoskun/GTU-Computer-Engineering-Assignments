#include "Tetris1Darray.h"
#include "TetrisVectorArray.h"
#include "TetrisAdapter.h"
#include "TetrisAdapter.cpp"
#include "tetromino.h"

using namespace std;

int main()
{
    cout << "-----------------------------------------" << endl;
	cout << "Functions of Tetromino Class:\n\n\n";
	cout << "Creating object of Tetromino...(Shape J)\n" << endl;
	Tetromino tetro(Shapes::J); //constructor use init() Function.

	cout << "print() Function:" << endl;
	tetro.print();

	cout << "And we are printing shape again by using getShape(): " << endl;
	for (int i = 0; i < tetro.getShapeRow(); i++)
	{
		for (int j = 0; j < tetro.getShapeColumn(); j++)
		{
			cout << tetro.getShape()[i][j];
		}
		cout << endl;
	}
	
	cout << "\nWe are rotating by using rotate() Function" << endl;
	cout << "Rotating to Right once:" << endl;
	tetro.rotate('R', 3, 2);
	tetro.print();







    cout << "-----------------------------------------" << endl;
	cout << "Functions of Tetris1Darray Class:\n\n\n";
	cout << "Creating object of Tetris1Darray...(10x10 Board)\n" << endl;
	Tetris1Darray board1(10, 10); 

    char check;
	cout << "If you want to see 'draw' function, enter A character: ";
	cin >> check;

	board1.draw();
    cout << "Printed empty board by using draw() Function." << endl;

	cout << "If you want to see 'operator+=' function, enter A character: ";
	cin >> check;

	board1+=tetro;
    cout << "operator+= Function that is printed above." << endl;

	char move_direction='R';
	int move_count=3;
	cout << "\n\nAlso, setting information of move by using setter..." << endl;
	board1.setMove(move_direction, move_count);

	cout << "\nIf you want to see 'animate' function, enter A character: ";
	cin >> check;

	board1.animate(tetro);
    cout << "\nAnd animated according to given information by using 'animate' Function. " << endl;

    cout << "\nIf you want to see 'numberOfMoves' function, enter A character: ";
	cin >> check;

    cout << "\nThe moves number of last animate function: ";
    cout << board1.numberOfMoves();

    cout << "\nAnd, we find shape of last move by using 'lastMove' Function: " << endl;
    board1.lastMove(tetro);
    
    cout << "\nIf you want to see file functions, enter A character: ";
	cin >> check;

    cout << "\nWe wrote the board to the file." << endl;
    board1.writeToFile("output.txt");
    cout << "\nFinally, we read and printed the board from the file:" << endl;
    board1.readFromFile("output.txt");

	cout << "\n\nTetris1Darray functions are done!" << endl;






    Tetromino tetro1(Shapes::O);
    cout << "-----------------------------------------" << endl;
	cout << "Functions of TetrisVectorArray Class:\n\n\n";
	cout << "Creating object of TetrisVectorArray...(10x10 Board)\n" << endl;
	TetrisVectorArray board2(10, 10); 

	cout << "If you want to see 'draw' function, enter A character: ";
	cin >> check;

	board2.draw();
    cout << "Printed empty board by using draw() Function." << endl;

	cout << "If you want to see 'operator+=' function, enter A character: ";
	cin >> check;

	board2+=tetro1;
    cout << "operator+= Function that is printed above." << endl;

	move_direction='R';
	move_count=3;
	cout << "\n\nAlso, setting information of move by using setter..." << endl;
	board2.setMove(move_direction, move_count);

	cout << "\nIf you want to see 'animate' function, enter A character: ";
	cin >> check;

	board2.animate(tetro1);
    cout << "\nAnd animated according to given information by using 'animate' Function. " << endl;

    cout << "\nIf you want to see 'numberOfMoves' function, enter A character: ";
	cin >> check;

    cout << "\nThe moves number of last animate function: ";
    cout << board2.numberOfMoves();

    cout << "\nAnd, we find shape of last move by using 'lastMove' Function: " << endl;
    board2.lastMove(tetro1);

    cout << "\nIf you want to see file functions, enter A character: ";
	cin >> check;

    cout << "\nWe wrote the board to the file." << endl;
    board2.writeToFile("output.txt");
    cout << "\nFinally, we read and printed the board from the file:" << endl;
    board2.readFromFile("output.txt");
    
	cout << "\n\nTetrisVectorArray functions are done!" << endl;






    Tetromino tetro2(Shapes::T);
    cout << "-----------------------------------------" << endl;
	cout << "Functions of TetrisAdapter Class:\n\n\n";
	cout << "Creating object of TetrisAdapter...(10x10 Board)\n" << endl;
	TetrisAdapter<vector<char>> board3(10, 10); 

	cout << "If you want to see 'draw' function, enter A character: ";
	cin >> check;

	board3.draw();
    cout << "Printed empty board by using draw() Function." << endl;

	cout << "If you want to see 'operator+=' function, enter A character: ";
	cin >> check;

	board3+=tetro2;
    cout << "operator+= Function that is printed above." << endl;

	move_direction='R';
	move_count=3;
	cout << "\n\nAlso, setting information of move by using setter..." << endl;
	board3.setMove(move_direction, move_count);

	cout << "\nIf you want to see 'animate' function, enter A character: ";
	cin >> check;

	board3.animate(tetro2);
    cout << "\nAnd animated according to given information by using 'animate' Function. " << endl;

    cout << "\nIf you want to see 'numberOfMoves' function, enter A character: ";
	cin >> check;

    cout << "\nThe moves number of last animate function: ";
    cout << board3.numberOfMoves();

    cout << "\nAnd, we find shape of last move by using 'lastMove' Function: " << endl;
    board3.lastMove(tetro2);

    cout << "\nIf you want to see file functions, enter A character: ";
	cin >> check;

    cout << "\nWe wrote the board to the file." << endl;
    board3.writeToFile("output.txt");
    cout << "\nFinally, we read and printed the board from the file:" << endl;
    board3.readFromFile("output.txt");

	cout << "\n\nTetrisAdapter functions are done!" << endl;


	cout << "\n\n---------------------------------------------------------------\n";
	cout << "driver1 is over!";
	cout << "\n---------------------------------------------------------------\n";
	cout << "driver2 will start.";
	cout << "\n---------------------------------------------------------------\n\n";

    return 0;
}