import java.util.*;

/**
 * Class: Tetris
 * 
 * A class that creates Tetris game board and handles the game logic.
 * 
 * It creates a 2D char array as a board and provides methods to interact with the board,
 * 
 * such as adding tetromino, animating, moving and drawing the board.
*/
class Tetris {
    private int row; //row size of board
    private int column; //column size of board

    private int animate_row; //row size of the animate board
    private int animate_column; //column size of the animate column

    private char move_direction; //the direction of the tetromino
    private int move_count; //the count of the move times of tetromino

    private char[][] board; //the 2D array which holds board of tetris game
    private char[][] animate_arr; //the 2D array which is using while animate process

    /**
     * @param row row of the board
     * 
     * @param column column of the board
     */
    public Tetris(int row, int column) { //constructor with size of row and column
        this.row = row;
        this.column = column;
        creating_board();
        creating_animate_arr();
    }

    public Tetris() { //default constructor
    }

    /**
     * Function:    creating_board
     * ----------------------
     * It does: it creates a 2D board based on the input the user enters.
     *
     * returns: it doesn't return anything.
     *
     */
    private void creating_board() {
        board = new char[row][column];

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                board[i][j] = ' ';
            }
        }
    }

    /**
     * Function:    draw
     * ----------------------
     * It does: it prints the 2D board based on the input the user enters.
     *
     * returns: it doesn't return anything.
     *
     */
    public void draw() {
        
        try {
            Thread.sleep(500);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.print("\033[H\033[2J");

        for (int t = 0; t < column + 2; t++) {
            System.out.print("@");
        }
        System.out.println();
        for (int i = 0; i < row; i++) {
            System.out.print("@");
            for (int k = 0; k < column; k++) {
                System.out.print(board[i][k]);
            }
            System.out.println("@");
        }
        for (int t = 0; t < column + 2; t++) {
            System.out.print("@");
        }
        System.out.println();

    }

    /**
     * @param obj it takes tetromino as paramater that will print top of the board
     * 
     * @return if it can add returns true, if cannot returns false.
     */
    public boolean addTetromino(Tetromino obj) {
        this.animate_row = obj.getShapeRow() - 1;
        this.animate_column = column/2 - 1;
    
        for(int i = 0; i < row; i++) {
            for(int k = 0; k < column; k++) {
                animate_arr[i][k] = board[i][k]; //clearing previous move
            }
        }
    
        for (int i = 0; i < obj.getShapeRow(); i++) {
            for (int j = 0; j < obj.getShapeColumn(); j++) {
                //checks top of the board is suitable for this tetromino
                if(board[0+i][column/2-1+j] != ' ' && obj.getShape()[i][j] != ' '){
                    return false;
                }
            }
        }
    
        for (int i = 0; i < obj.getShapeRow(); i++) {
            for (int j = 0; j < obj.getShapeColumn(); j++) {
                if(obj.getShape()[i][j] == ' ') continue;
                animate_arr[0+i][column/2-1+j] = obj.getShape()[i][j];
            }
        }
        draw_animate_arr();
        return true;
    }

    
    /**
     * Function:    creating_animate_arr
     * ----------------------
     * It does: it creates a 2D board which is using while animate process
     *
     * returns: it doesn't return anything.
     *
     */
    private void creating_animate_arr() {
        animate_arr = new char[row][column];

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                animate_arr[i][j] = ' ';
            }
        }
    }

    /**
     * Function:    draw_animate_arr
     * ----------------------
     * It does: it prints the 2D animate board while animate process
     *
     * returns: it doesn't return anything.
     *
     */
    public void draw_animate_arr() {
        try {
            Thread.sleep(500);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.print("\033[H\033[2J");

        for (int t = 0; t < column + 2; t++) {
            System.out.print("@");
        }
        System.out.println();
        for (int i = 0; i < row; i++) {
            System.out.print("@");
            for (int k = 0; k < column; k++) {
                System.out.print(animate_arr[i][k]);
            }
            System.out.println("@");
        }
        for (int t = 0; t < column + 2; t++) {
            System.out.print("@");
        }
        System.out.println();

        
    }

    /**
     * Function:    animate
     * ----------------------
     * This function takes care of every step of the animate process.
     *
     * returns: it doesn't return anything.
     *
     * @param obj it takes tetromino as paramater that will make animate process.
     */
    public void animate(Tetromino obj) {
        int placed = 0;
        int temp_move = move_count;
        while (placed == 0 && temp_move > 0) { //left-right
            if (animate_column == 0) break; //checks for left side of board
            if ((animate_column + obj.getShapeColumn()) == column) break; //checks for right side of board
    
            for (int i = 0; i < row; i++) {
                for (int k = 0; k < column; k++) {
                    animate_arr[i][k] = board[i][k]; //clearing previous move
                }
            }
    
            if (move_direction == 'R' || move_direction == 'r') { //checks moving right
                for (int i = 0; i < obj.getShapeRow(); i++) {
                    for (int j = 0; j < obj.getShapeColumn(); j++) {
                        if (j == obj.getShapeColumn() - 1) {
                            if (obj.getShape()[i][j] != ' ') {
                                if (animate_column + j + 1 < column && animate_arr[animate_row - (obj.getShapeRow() - 1) + i][animate_column + j + 1] != ' ') {
                                    placed = 1;
                                }
                            } else if (obj.getShape()[i][j - 1] != ' ') {
                                if (animate_column + j - 1 + 1 < column && animate_arr[animate_row - (obj.getShapeRow() - 1) + i][animate_column + j - 1 + 1] != ' ') {
                                    placed = 1;
                                }
                            } else if (obj.getShape()[i][j - 2] != ' ') {
                                if (animate_column + j - 2 + 1 < column && animate_arr[animate_row - (obj.getShapeRow() - 1) + i][animate_column + j - 2 + 1] != ' ') {
                                    placed = 1;
                                }
                            }
                        }
                    }
                }
                if (placed == 0) this.animate_column++;
            }
            if (move_direction == 'L' || move_direction == 'l') { //checks moving left
                for (int i = 0; i < obj.getShapeRow(); i++) {
                    for (int j = 0; j < obj.getShapeColumn(); j++) {
                        if (j == 0) {
                            if (obj.getShape()[i][j] != ' ') {
                                if (animate_column + j - 1 > 0 && animate_arr[animate_row - (obj.getShapeRow() - 1) + i][animate_column + j - 1] != ' ') {
                                    placed = 1;
                                }
                            } else if (obj.getShape()[i][j + 1] != ' ') {
                                if (animate_column + j + 1 - 1 > 0 && animate_arr[animate_row - (obj.getShapeRow() - 1) + i][animate_column + j + 1 - 1] != ' ') {
                                    placed = 1;
                                }
                            } else if (obj.getShape()[i][j + 2] != ' ') {
                                if (animate_column + j + 2 - 1 > 0 && animate_arr[animate_row - (obj.getShapeRow() - 1) + i][animate_column + j + 2 - 1] != ' ') {
                                    placed = 1;
                                }
                            }
                        }
                    }
                }
                if (placed == 0) this.animate_column--;
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
        while (true) { //GOING DOWN
            if (animate_row == row) break; //the condition which is the bottom of board
            for (int i = 0; i < row; i++) {
                for (int k = 0; k < column; k++) {
                    animate_arr[i][k] = board[i][k]; //clearing previous move
                }
            }
            
            for (int i = 0; i < obj.getShapeRow(); i++) {
                for (int j = 0; j < obj.getShapeColumn(); j++) {
                    if (obj.getShape()[i][j] != ' ') {
                        if (animate_row - (obj.getShapeRow() - 1) + i + 1 < row && animate_arr[animate_row - (obj.getShapeRow() - 1) + i + 1][animate_column + j] != ' ') {
                            placed = 1;
                            break;
                        }
                    }
                }
                if (placed == 1) break;
            }
            
            for (int i = 0; i < obj.getShapeRow(); i++) {
                for (int j = 0; j < obj.getShapeColumn(); j++) {
                    //animating shape
                    if (obj.getShape()[i][j] == ' ') continue;
                    animate_arr[animate_row - (obj.getShapeRow() - 1) + i][animate_column + j] = obj.getShape()[i][j];
                }
            }
            draw_animate_arr();
            if (placed == 1) break;
            this.animate_row++;
        }

        for (int i = 0; i < row; i++) {
            for (int k = 0; k < column; k++) {
                board[i][k] = animate_arr[i][k]; //assigning to board
            }
        }
    }
                                
    /**
     * Function:    getRow
     * ----------------------
     * It is the getter that returns the value of row
     *
     * @return the value of row
     *
     */
    public int getRow() {
        return row;
    }

    /**
     * Function:    getColumn
     * ----------------------
     * It is the getter that returns the value of column
     *
     * @return the value of column
     *
     */
    public int getColumn() {
        return column;
    }

    /**
     * Function:    setMove
     * ----------------------
     * It is the setter that sets the value of movement informations.
     *
     * returns: it doesn't return anything.
     *
     * @param move_direction the direction of the tetromino
     * 
     * @param move_count the count of the move times of tetromino
     */
    public void setMove(char move_direction, int move_count) {
        this.move_direction = move_direction;
        this.move_count = move_count;
    }
}
