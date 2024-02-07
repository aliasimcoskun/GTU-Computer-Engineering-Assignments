import java.util.Scanner;
import java.util.Random;
import java.util.TimeZone;

/**
 * This class is the driver class for the Tetris game, which allows the user to play the game and test the functionality of the Tetris and Tetromino classes.
 * The driver class uses a Scanner object to take input from the user and a Random object to generate random values for the game.
 * It creates a Tetris board and Tetromino objects, and uses the various methods from the Tetris and Tetromino classes to play the game.
 * The user can select a shape of Tetromino, rotate and move it on the board, and see the animation of the Tetromino falling and filling the board.
 * The user can also quit the game by pressing the 'Q' key.
 * The class also includes 5 different test runs to test the functionality of the game with different board sizes and Tetromino shapes.
*/
public class driver2 {
    /**
     * The main method of the driver2 class. It runs 5 different test cases,
     * each with different board sizes and Tetromino shapes.
     *
     * @param args command line arguments (not used)
     */
    public static void main(String[] args) {

    System.out.println("DRIVER2\n\n\n\n");

    int random;
    Random rand = new Random();
    rand.setSeed(System.currentTimeMillis());

    int row;
    int column;

    Scanner sc = new Scanner(System.in);

    System.out.println("Please enter the row size of board\n(For example: 7)");
    row = sc.nextInt();

    System.out.println("Please enter the column size of board\n(For example: 10)");
    column = sc.nextInt();

    Tetris board = new Tetris(row, column);
    System.out.println("Board has been created!");

    char rotation_direction;
    int rotation_count;

    char move_direction;
    int move_count;

    boolean over=true;
    char check;

    Random rand2 = new Random();
    rand2.setSeed(System.currentTimeMillis());
    int random_for_rotate;

    Random rand3 = new Random();
    rand3.setSeed(System.currentTimeMillis());
    int random_for_move;
    
    Random rand4 = new Random();
    rand4.setSeed(System.currentTimeMillis());
    int random_for_rotation_direction;
    
    Random rand5 = new Random();
    rand5.setSeed(System.currentTimeMillis());
    int random_for_move_direction;

    if(sc.hasNextLine()){
        sc.nextLine();
    }
    while(true) {
        random=9;
        System.out.println("\n\nPlease select shape of the Tetromino\n(I, J, L, O, S, T, Z)\nor 'R' for Random.");
        System.out.println("If you want to quit, press Q.");
        check = sc.nextLine().charAt(0);

        random_for_rotate = rand.nextInt(4);
        random_for_move = rand.nextInt(column/2);
        random_for_rotation_direction = rand.nextInt(2);
        random_for_move_direction = rand.nextInt(2);

        // System.out.println(check);
        // check='J';

        if(check=='Q') {
            System.out.println("You want to quit. Goodbye!");
            break;
        }

        if(check=='R') {
            random = rand.nextInt(7) + 1;
        }

        if(check=='J' || random==1) {
            Tetromino y = new Tetromino(Shapes.J);
            over = (board.addTetromino(y));
            if(over == false) break;

            if(random_for_rotation_direction==0) rotation_direction ='L';
            else rotation_direction ='R';
            rotation_count=random_for_rotate;

            if(random_for_move_direction==0) move_direction='L';
            else move_direction='R';
            move_count=random_for_move;
            
            board.setMove(move_direction, move_count);
            int temp=rotation_count;
            while(temp>0) {
                over = (board.addTetromino(y));
                if(over==false) {
                    break;
                }
                y.rotate(rotation_direction, y.getShapeRow(), y.getShapeColumn());
                temp--;
            }
            if(over==false) {
                break;
            }
            board.addTetromino(y);
            board.animate(y);
        }
        else if((check=='L') || random==2) {
            Tetromino y = new Tetromino(Shapes.L);
            over = (board.addTetromino(y));
            if(over == false) break;

            if(random_for_rotation_direction==0) rotation_direction ='L';
            else rotation_direction ='R';
            rotation_count=random_for_rotate;

            if(random_for_move_direction==0) move_direction='L';
            else move_direction='R';
            move_count=random_for_move;
            
            board.setMove(move_direction, move_count);
            int temp=rotation_count;
            while(temp>0) {
                over = (board.addTetromino(y));
                if(over==false) {
                    break;
                }
                y.rotate(rotation_direction, y.getShapeRow(), y.getShapeColumn());
                temp--;
            }
            if(over==false) {
                break;
            }
            board.addTetromino(y);
            board.animate(y);
        }
        else if((check=='O') || random==3) {
            Tetromino y = new Tetromino(Shapes.O);
            over = (board.addTetromino(y));
            if(over == false) break;

            if(random_for_rotation_direction==0) rotation_direction ='L';
            else rotation_direction ='R';
            rotation_count=random_for_rotate;

            if(random_for_move_direction==0) move_direction='L';
            else move_direction='R';
            move_count=random_for_move;
            
            board.setMove(move_direction, move_count);
            int temp=rotation_count;
            while(temp>0) {
                over = (board.addTetromino(y));
                if(over==false) {
                    break;
                }
                y.rotate(rotation_direction, y.getShapeRow(), y.getShapeColumn());
                temp--;
            }
            if(over==false) {
                break;
            }
            board.addTetromino(y);
            board.animate(y);
        }
        else if((check=='S') || random==4) {
            Tetromino y = new Tetromino(Shapes.S);
            over = (board.addTetromino(y));
            if(over == false) break;

            if(random_for_rotation_direction==0) rotation_direction ='L';
            else rotation_direction ='R';
            rotation_count=random_for_rotate;

            if(random_for_move_direction==0) move_direction='L';
            else move_direction='R';
            move_count=random_for_move;
            
            board.setMove(move_direction, move_count);
            int temp=rotation_count;
            while(temp>0) {
                over = (board.addTetromino(y));
                if(over==false) {
                    break;
                }
                y.rotate(rotation_direction, y.getShapeRow(), y.getShapeColumn());
                temp--;
            }
            if(over==false) {
                break;
            }
            board.addTetromino(y);
            board.animate(y);
        }
        else if((check=='T') || random==5) {
            Tetromino y = new Tetromino(Shapes.T);
            over = (board.addTetromino(y));
            if(over == false) break;

            if(random_for_rotation_direction==0) rotation_direction ='L';
            else rotation_direction ='R';
            rotation_count=random_for_rotate;

            if(random_for_move_direction==0) move_direction='L';
            else move_direction='R';
            move_count=random_for_move;
            
            board.setMove(move_direction, move_count);
            int temp=rotation_count;
            while(temp>0) {
                over = (board.addTetromino(y));
                if(over==false) {
                    break;
                }
                y.rotate(rotation_direction, y.getShapeRow(), y.getShapeColumn());
                temp--;
            }
            if(over==false) {
                break;
            }
            board.addTetromino(y);
            board.animate(y);
        }
        else if((check=='Z') || random==6) {
            Tetromino y = new Tetromino(Shapes.Z);
            over = (board.addTetromino(y));
            if(over == false) break;

            if(random_for_rotation_direction==0) rotation_direction ='L';
            else rotation_direction ='R';
            rotation_count=random_for_rotate;

            if(random_for_move_direction==0) move_direction='L';
            else move_direction='R';
            move_count=random_for_move;
            
            board.setMove(move_direction, move_count);
            int temp=rotation_count;
            while(temp>0) {
                over = (board.addTetromino(y));
                if(over==false) {
                    break;
                }
                y.rotate(rotation_direction, y.getShapeRow(), y.getShapeColumn());
                temp--;
            }
            if(over==false) {
                break;
            }
            board.addTetromino(y);
            board.animate(y);
        }
        else if((check=='I') || random==7) {
            Tetromino y = new Tetromino(Shapes.I);
            over = (board.addTetromino(y));
            if(over == false) break;

            if(random_for_rotation_direction==0) rotation_direction ='L';
            else rotation_direction ='R';
            rotation_count=random_for_rotate;

            if(random_for_move_direction==0) move_direction='L';
            else move_direction='R';
            move_count=random_for_move;
            
            board.setMove(move_direction, move_count);
            int temp=rotation_count;
            while(temp>0) {
                over = (board.addTetromino(y));
                if(over==false) {
                    break;
                }
                y.rotate(rotation_direction, y.getShapeRow(), y.getShapeColumn());
                temp--;
            }
            if(over==false) {
                break;
            }
            board.addTetromino(y);
            board.animate(y);
        }
        else{
            System.out.println("Invalid Input! \n");
        }
    }
    if(over==false)
    {
        System.out.println("GAME OVER! \n");
    }

    sc.close();
    }
}