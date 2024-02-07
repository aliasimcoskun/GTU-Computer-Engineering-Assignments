#include "tetris.h"

using namespace std;
using namespace NS_tetris;

int main()
{
    int random;
    srand(time(NULL));

    int row;
    int column;

    cout << "Please enter the row size of board\n(For example: 7)" << endl;
    cin >> row;
    while(true) //checking validity of row
    {
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "INVALID! Please enter valid value: " << endl;
            cin >> row;
        }
        if(!cin.fail()) break;
    }
    cout << "Please enter the column size of board\n(For example: 10)" << endl;
    cin >> column;
    while(true) //checking validity of column
    {
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "INVALID! Please enter valid value: " << endl;
            cin >> column;
        }
        if(!cin.fail()) break;
    }

    Tetris board(row, column); //creating board with given size
    cout << "Board has been created!" << endl;

    string check_rotation;
    char rotation_direction;
    int rotation_count;

    string check_move;
    char move_direction;
    int move_count;

    string check_type;
    char* type;
    bool over;

    while(true)
    {
        random=9;
        cout << "\n\nPlease select shape of the Tetromino\n(I, J, L, O, S, T, Z)" << endl;
        cout << "If you want to quit, press Q." << endl;
        cin >> check_type;
        type = &check_type[0];

        if((type[0]=='Q' || type[0]=='q') && type[1]=='\0')
        {
            cout << "You want to quit. Goodbye!" << endl;
            break;
        }

        if(type[0]=='R' || type[0]=='r')
        {
            random=rand()%7+1;
        }

        if(((type[0]=='j' || type[0]=='J') && type[1]=='\0') || random==1){
            Tetromino y(Shapes::J);
            over=(board+=y);
            if(over==0) break;

            cout << "rotation direction?\n(Enter 'L' for Left, 'R' for Right): ";
            cin >> check_rotation;
            while(!((check_rotation[0]=='R' && check_rotation[1]=='\0') || (check_rotation[0]=='L' && check_rotation[1]=='\0')))
            {
                cout << "INVALID! Please try again: " << endl;
                cin >> check_rotation;
            }
            rotation_direction=check_rotation[0];
            cout << "rotation count?\n(Enter a number): ";
            cin >> rotation_count;
            while(true) //checking validity of rotation count
            {
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "INVALID! Please enter valid value: " << endl;
                    cin >> rotation_count;
                }
                if(!cin.fail()) break;
            }
            cout << "move_direction?\n(Enter 'L' for Left, 'R' for Right): ";
            cin >> check_move;
            while(!((check_move[0]=='R' && check_move[1]=='\0') || (check_move[0]=='L' && check_move[1]=='\0')))
            {
                cout << "INVALID! Please try again: " << endl;
                cin >> check_move;
            }
            move_direction=check_move[0];
            
            cout << "move count?\n(Enter a number): ";
            cin >> move_count;
            while(true) //checking validity of move count
            {
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "INVALID! Please enter valid value: " << endl;
                    cin >> move_count;
                }
                if(!cin.fail()) break;
            }
            board.setMove(move_direction, move_count);
            int temp=rotation_count;

            while(temp>0)
            {
                over=(board+=y);
                if(over==0) break;
                y.rotate(rotation_direction, y.getShapeRow(), y.getShapeColumn());
                temp--;
            }
            if(over==0) break;
            board+=y;
            board.animate(y);
        }
        else if(((type[0]=='i' || type[0]=='I') && type[1]=='\0') || random==2){
            Tetromino y(Shapes::I);
            over=(board+=y);
            if(over==0) break;

            cout << "rotation direction?\n(Enter 'L' for Left, 'R' for Right): ";
            cin >> check_rotation;
            while(!((check_rotation[0]=='R' && check_rotation[1]=='\0') || (check_rotation[0]=='L' && check_rotation[1]=='\0')))
            {
                cout << "INVALID! Please try again: " << endl;
                cin >> check_rotation;
            }
            rotation_direction=check_rotation[0];
            cout << "rotation count?\n(Enter a number): ";
            cin >> rotation_count;
            while(true) //checking validity of rotation count
            {
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "INVALID! Please enter valid value: " << endl;
                    cin >> rotation_count;
                }
                if(!cin.fail()) break;
            }
            cout << "move_direction?\n(Enter 'L' for Left, 'R' for Right): ";
            cin >> check_move;
            while(!((check_move[0]=='R' && check_move[1]=='\0') || (check_move[0]=='L' && check_move[1]=='\0')))
            {
                cout << "INVALID! Please try again: " << endl;
                cin >> check_move;
            }
            move_direction=check_move[0];
            
            cout << "move count?\n(Enter a number): ";
            cin >> move_count;
            while(true) //checking validity of move count
            {
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "INVALID! Please enter valid value: " << endl;
                    cin >> move_count;
                }
                if(!cin.fail()) break;
            }
            board.setMove(move_direction, move_count);
            int temp=rotation_count;

            while(temp>0)
            {
                over=(board+=y);
                if(over==0) break;
                y.rotate(rotation_direction, y.getShapeRow(), y.getShapeColumn());
                temp--;
            }
            if(over==0) break;
            board+=y;
            board.animate(y);
        }
        else if(((type[0]=='o' || type[0]=='O') && type[1]=='\0') || random==3){
            Tetromino y(Shapes::O);
            over=(board+=y);
            if(over==0) break;

            cout << "rotation direction?\n(Enter 'L' for Left, 'R' for Right): ";
            cin >> check_rotation;
            while(!((check_rotation[0]=='R' && check_rotation[1]=='\0') || (check_rotation[0]=='L' && check_rotation[1]=='\0')))
            {
                cout << "INVALID! Please try again: " << endl;
                cin >> check_rotation;
            }
            rotation_direction=check_rotation[0];
            cout << "rotation count?\n(Enter a number): ";
            cin >> rotation_count;
            while(true) //checking validity of rotation count
            {
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "INVALID! Please enter valid value: " << endl;
                    cin >> rotation_count;
                }
                if(!cin.fail()) break;
            }
            cout << "move_direction?\n(Enter 'L' for Left, 'R' for Right): ";
            cin >> check_move;
            while(!((check_move[0]=='R' && check_move[1]=='\0') || (check_move[0]=='L' && check_move[1]=='\0')))
            {
                cout << "INVALID! Please try again: " << endl;
                cin >> check_move;
            }
            move_direction=check_move[0];
            
            cout << "move count?\n(Enter a number): ";
            cin >> move_count;
            while(true) //checking validity of move count
            {
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "INVALID! Please enter valid value: " << endl;
                    cin >> move_count;
                }
                if(!cin.fail()) break;
            }
            board.setMove(move_direction, move_count);
            int temp=rotation_count;

            while(temp>0)
            {
                over=(board+=y);
                if(over==0) break;
                y.rotate(rotation_direction, y.getShapeRow(), y.getShapeColumn());
                temp--;
            }
            if(over==0) break;
            board+=y;
            board.animate(y);
        }
        else if(((type[0]=='t' || type[0]=='T') && type[1]=='\0') || random==4){
            Tetromino y(Shapes::T);
            over=(board+=y);
            if(over==0) break;

            cout << "rotation direction?\n(Enter 'L' for Left, 'R' for Right): ";
            cin >> check_rotation;
            while(!((check_rotation[0]=='R' && check_rotation[1]=='\0') || (check_rotation[0]=='L' && check_rotation[1]=='\0')))
            {
                cout << "INVALID! Please try again: " << endl;
                cin >> check_rotation;
            }
            rotation_direction=check_rotation[0];
            cout << "rotation count?\n(Enter a number): ";
            cin >> rotation_count;
            while(true) //checking validity of rotation count
            {
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "INVALID! Please enter valid value: " << endl;
                    cin >> rotation_count;
                }
                if(!cin.fail()) break;
            }
            cout << "move_direction?\n(Enter 'L' for Left, 'R' for Right): ";
            cin >> check_move;
            while(!((check_move[0]=='R' && check_move[1]=='\0') || (check_move[0]=='L' && check_move[1]=='\0')))
            {
                cout << "INVALID! Please try again: " << endl;
                cin >> check_move;
            }
            move_direction=check_move[0];
            
            cout << "move count?\n(Enter a number): ";
            cin >> move_count;
            while(true) //checking validity of move count
            {
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "INVALID! Please enter valid value: " << endl;
                    cin >> move_count;
                }
                if(!cin.fail()) break;
            }
            board.setMove(move_direction, move_count);
            int temp=rotation_count;

            while(temp>0)
            {
                over=(board+=y);
                if(over==0) break;
                y.rotate(rotation_direction, y.getShapeRow(), y.getShapeColumn());
                temp--;
                if(temp==0) board+=y;
            }
            if(over==0) break;
            board.animate(y);
        }
        else if(((type[0]=='l' || type[0]=='L') && type[1]=='\0') || random==5){
            Tetromino y(Shapes::L);
            over=(board+=y);
            if(over==0) break;

            cout << "rotation direction?\n(Enter 'L' for Left, 'R' for Right): ";
            cin >> check_rotation;
            while(!((check_rotation[0]=='R' && check_rotation[1]=='\0') || (check_rotation[0]=='L' && check_rotation[1]=='\0')))
            {
                cout << "INVALID! Please try again: " << endl;
                cin >> check_rotation;
            }
            rotation_direction=check_rotation[0];
            cout << "rotation count?\n(Enter a number): ";
            cin >> rotation_count;
            while(true) //checking validity of rotation count
            {
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "INVALID! Please enter valid value: " << endl;
                    cin >> rotation_count;
                }
                if(!cin.fail()) break;
            }
            cout << "move_direction?\n(Enter 'L' for Left, 'R' for Right): ";
            cin >> check_move;
            while(!((check_move[0]=='R' && check_move[1]=='\0') || (check_move[0]=='L' && check_move[1]=='\0')))
            {
                cout << "INVALID! Please try again: " << endl;
                cin >> check_move;
            }
            move_direction=check_move[0];
            
            cout << "move count?\n(Enter a number): ";
            cin >> move_count;
            while(true) //checking validity of move count
            {
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "INVALID! Please enter valid value: " << endl;
                    cin >> move_count;
                }
                if(!cin.fail()) break;
            }
            board.setMove(move_direction, move_count);
            int temp=rotation_count;

            while(temp>0)
            {
                over=(board+=y);
                if(over==0) break;
                y.rotate(rotation_direction, y.getShapeRow(), y.getShapeColumn());
                temp--;
                if(temp==0) board+=y;
            }
            if(over==0) break;
            board.animate(y);
        }
        else if(((type[0]=='s' || type[0]=='S') && type[1]=='\0') || random==6){
            Tetromino y(Shapes::S);
            over=(board+=y);
            if(over==0) break;

            cout << "rotation direction?\n(Enter 'L' for Left, 'R' for Right): ";
            cin >> check_rotation;
            while(!((check_rotation[0]=='R' && check_rotation[1]=='\0') || (check_rotation[0]=='L' && check_rotation[1]=='\0')))
            {
                cout << "INVALID! Please try again: " << endl;
                cin >> check_rotation;
            }
            rotation_direction=check_rotation[0];
            cout << "rotation count?\n(Enter a number): ";
            cin >> rotation_count;
            while(true) //checking validity of rotation count
            {
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "INVALID! Please enter valid value: " << endl;
                    cin >> rotation_count;
                }
                if(!cin.fail()) break;
            }
            cout << "move_direction?\n(Enter 'L' for Left, 'R' for Right): ";
            cin >> check_move;
            while(!((check_move[0]=='R' && check_move[1]=='\0') || (check_move[0]=='L' && check_move[1]=='\0')))
            {
                cout << "INVALID! Please try again: " << endl;
                cin >> check_move;
            }
            move_direction=check_move[0];
            
            cout << "move count?\n(Enter a number): ";
            cin >> move_count;
            while(true) //checking validity of move count
            {
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "INVALID! Please enter valid value: " << endl;
                    cin >> move_count;
                }
                if(!cin.fail()) break;
            }
            board.setMove(move_direction, move_count);
            int temp=rotation_count;

            while(temp>0)
            {
                over=(board+=y);
                if(over==0) break;
                y.rotate(rotation_direction, y.getShapeRow(), y.getShapeColumn());
                temp--;
                if(temp==0) board+=y;
            }
            if(over==0) break;
            board.animate(y);
        }
        else if(((type[0]=='z' || type[0]=='Z') && type[1]=='\0') || random==7){
            Tetromino y(Shapes::Z);
            over=(board+=y);
            if(over==0) break;

            cout << "rotation direction?\n(Enter 'L' for Left, 'R' for Right): ";
            cin >> check_rotation;
            while(!((check_rotation[0]=='R' && check_rotation[1]=='\0') || (check_rotation[0]=='L' && check_rotation[1]=='\0')))
            {
                cout << "INVALID! Please try again: " << endl;
                cin >> check_rotation;
            }
            rotation_direction=check_rotation[0];
            cout << "rotation count?\n(Enter a number): ";
            cin >> rotation_count;
            while(true) //checking validity of rotation count
            {
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "INVALID! Please enter valid value: " << endl;
                    cin >> rotation_count;
                }
                if(!cin.fail()) break;
            }
            cout << "move_direction?\n(Enter 'L' for Left, 'R' for Right): ";
            cin >> check_move;
            while(!((check_move[0]=='R' && check_move[1]=='\0') || (check_move[0]=='L' && check_move[1]=='\0')))
            {
                cout << "INVALID! Please try again: " << endl;
                cin >> check_move;
            }
            move_direction=check_move[0];
            
            cout << "move count?\n(Enter a number): ";
            cin >> move_count;
            while(true) //checking validity of move count
            {
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "INVALID! Please enter valid value: " << endl;
                    cin >> move_count;
                }
                if(!cin.fail()) break;
            }
            board.setMove(move_direction, move_count);
            int temp=rotation_count;

            while(temp>0)
            {
                over=(board+=y);
                if(over==0) break;
                y.rotate(rotation_direction, y.getShapeRow(), y.getShapeColumn());
                temp--;
                if(temp==0) board+=y;
            }
            if(over==0) break;
            board.animate(y);
        }
        else{
            cout << "Invalid Input!" << endl;
        }
    }
    if(over==0)
    {
        cout << "GAME OVER!" << endl;
    }

    return 0;
}