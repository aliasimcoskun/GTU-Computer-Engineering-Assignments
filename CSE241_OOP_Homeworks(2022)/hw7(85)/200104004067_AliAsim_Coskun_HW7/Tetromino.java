/**
 * Enumeration of all the different shapes that a Tetromino can have
 * in a Tetris game.
 */
enum Shapes {
    /** The I shape. */
    I, 
    /** The J shape. */
    J, 
    /** The L shape. */
    L, 
    /** The O shape. */
    O, 
    /** The S shape. */
    S, 
    /** The T shape. */
    T, 
    /** The Z shape. */
    Z
}

/**
 * Tetromino class represents tetromino shapes used in the game Tetris.
 * It is a two-dimensional array that holds the shape of the tetromino.
 * The class also has fields for the shape's row and column size.
 * It has methods to get the shape, shapeRow and shapeColumn, print, rotate and init the shape of tetromino.
 */
class Tetromino {
    private char[][] shape; // 2D array that holds shapes

    private int shapeRow; // integer value that holds row size of shape
    private int shapeColumn; // integer value that holds column size of shape

    /**
     * @return it returns 2d array that has tetromino
     */
    public char[][] getShape() {
        return shape;
    }

    /**
     * @return row of tetromino
     */
    public int getShapeRow() {
        return shapeRow;
    }


    /**
     * @return column of tetromino
     */
    public int getShapeColumn() {
        return shapeColumn;
    }

    /**
     * @param tetroShape it takes tetrominos as a paramater
     */
    public Tetromino(Shapes tetroShape) {
        init(tetroShape);
    }
    
    // default constructor
    public Tetromino() {
        init(Shapes.I);
    }

    /**
     * Function:    print
     * ----------------------
     * It does: it prints the tetrominos
     *
     * returns: it doesn't return anything.
     *
     */
    public void print() {
        System.out.println();
        System.out.println("Selected Tetromino: ");
        for(int k = 0; k < shapeRow; k++) {
            for(int i = 0; i < shapeColumn; i++) {
                System.out.print(shape[k][i]);
            }
            System.out.println();
        }
        System.out.println();
    }

    /**
     * Function:    rotate
     * ----------------------
     * It does: it rotates the tetrominos with given direction
     *
     * returns: it doesn't return anything.
     *
     * @param direction direction of the rotation
     * 
     * @param row row of the shape
     * 
     * @param column column of the shape
     */
    public void rotate(char direction, int row, int column) {
        char[][] rotate = new char[column][row]; //column and row swapped

        if (direction == 'L') { //left
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < column; j++) {
                    rotate[j][i] = shape[i][j]; //transpose
                }
            }
            for (int i = 0; i < row; i++) {//row and column swapped
                int begin = 0;
                int end = column - 1;
                while (begin < end) {//row and column swapped
                    char temp = rotate[begin][i];
                    rotate[begin][i] = rotate[end][i];
                    rotate[end][i] = temp;
                    begin++;
                    end--;
                }
            }
        }
        else if (direction == 'R') { //right
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < column; j++) {
                    rotate[j][i] = shape[i][j]; //transpose
                }
            }
            for (int i = 0; i < column; i++) {
                int begin = 0;
                int end = row - 1;
                while (begin < end) {
                    char temp = rotate[i][begin];
                    rotate[i][begin] = rotate[i][end];
                    rotate[i][end] = temp;
                    begin++;
                    end--;
                }
            }
        }
        
        this.shapeRow=column;
        this.shapeColumn=row;
        this.shape=rotate;
    }

    /**
     * Function:    init
     * ----------------------
     * It does: it fills the 2D shape array with constructor.
     *
     * returns: it doesn't return anything.
     *
     * @param tetroShape it takes tetrominos as a paramater
     */
    public void init(Shapes tetroShape) {
        shape = new char[3][3];

        if (tetroShape == Shapes.I) {
            // {'I'}
            // {'I'}
            // {'I'}
            // {'I'}

            this.shapeRow = 4;
            this.shapeColumn = 1;
            shape = new char[shapeRow][1];

            for (int i = 0; i < 4; i++) {
                shape[i][0] = 'I';
            }
        } else if (tetroShape == Shapes.J) {
            // {' ', 'J'}
            // {' ', 'J'}
            // {'J', 'J'}

            this.shapeRow = 3;
            this.shapeColumn = 2;
            shape = new char[shapeRow][shapeColumn];

            for (int i = 0; i < 3; i++)
            {
                for (int k = 0; k < 2; k++)
                {
                    if(i==0 && k==0) shape[i][k]=' ';
                    else if(i==1 && k==0) shape[i][k]=' ';
                    else shape[i][k]='J';
                }
            }
        } else if (tetroShape == Shapes.L) {
            // {'L', ' '}
            // {'L', ' '}
            // {'L', 'L'}

            this.shapeRow = 3;
            this.shapeColumn = 2;
            shape = new char[shapeRow][shapeColumn];

            for (int i = 0; i < 3; i++)
            {
                for (int k = 0; k < 2; k++)
                {
                    if(i==0 && k==1) shape[i][k]=' ';
                    else if(i==1 && k==1) shape[i][k]=' ';
                    else shape[i][k]='L';
                }
            }
        } else if (tetroShape == Shapes.O) {
            // {'O', 'O'}
            // {'O', 'O'}

            this.shapeRow = 2;
            this.shapeColumn = 2;
            shape = new char[shapeRow][shapeColumn];

            for (int i = 0; i < 2; i++)
            {
                for (int k = 0; k < 2; k++)
                {
                    shape[i][k]='O';
                }
            }
        }else if (tetroShape == Shapes.S) {
            // {' ', 'S', 'S'}
            // {'S', 'S', ' '}

            this.shapeRow = 2;
            this.shapeColumn = 3;
            shape = new char[shapeRow][shapeColumn];

            for (int i = 0; i < 2; i++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if(i==0 && k==0) shape[i][k]=' ';
                    else if(i==1 && k==2) shape[i][k]=' ';
                    else shape[i][k]='S';
                }
            }
        }else if (tetroShape == Shapes.T) {
            // {'T', 'T', 'T'}
            // {' ', 'T', ' '}

            this.shapeRow = 2;
            this.shapeColumn = 3;
            shape = new char[shapeRow][shapeColumn];

            for (int i = 0; i < 2; i++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if(i==1 && k==0) shape[i][k]=' ';
                    else if(i==1 && k==2) shape[i][k]=' ';
                    else shape[i][k]='T';
                }
            }
        }else if (tetroShape == Shapes.Z) {
            // {'Z', 'Z', ' '}
            // {' ', 'Z', 'Z'}

            this.shapeRow = 2;
            this.shapeColumn = 3;
            shape = new char[shapeRow][shapeColumn];

            for (int i = 0; i < 2; i++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if(i==1 && k==0) shape[i][k]=' ';
                    else if(i==0 && k==2) shape[i][k]=' ';
                    else shape[i][k]='Z';
                }
            }
        }
    }
}

