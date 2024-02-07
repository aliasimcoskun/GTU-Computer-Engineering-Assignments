#include "tetris.h"

using namespace std;
using namespace NS_tetris;

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
	cout << "Functions of Tetris Class:\n\n\n";
	cout << "Creating object of Tetris...(10x10 Board)\n" << endl;
	Tetris board(10, 10); 
	//constructor use creating_board() Function
	//and creating_animate_arr() Function.

	char check;
	cout << "If you want to see 'draw' function, enter any character: ";
	cin >> check;

	cout << "Printing empty board by using draw() Function:" << endl;
	board.draw();

	cout << "If you want to see 'operator+=' function, enter any character: ";
	cin >> check;

	cout << "operator+= Function:" << endl;
	board+=tetro;

	char move_direction='R';
	int move_count=3;
	cout << "Setting information of move..." << endl;
	board.setMove(move_direction, move_count);

	cout << "\nIf you want to see 'operator+=' function, enter any character: ";
	cin >> check;

	cout << "\nAnd animating according to given information by using animate Function: " << endl;
	board.animate(tetro);

	cout << "all is done!" << endl;
	return 0;
}