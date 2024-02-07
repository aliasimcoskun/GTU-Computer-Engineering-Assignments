import java.util.Scanner;
/**
 * A driver class to test the functionality of the Tetris and Tetromino classes.
 * This class creates 5 different test runs, each with different board sizes and
 * Tetromino shapes.
 */
public class driver1{
    /**
     * The main method of the driver1 class. It runs 5 different test cases,
     * each with different board sizes and Tetromino shapes.
     *
     * @param args command line arguments (not used)
     */
    public static void main(String[] args) {
        char check;
        System.out.println("Enter any character for 1st test:");
        Scanner sc = new Scanner(System.in);
        sc.nextLine();
        // Run 1: Test with a 5x5 board and I shape tetromino
        Tetris board1 = new Tetris(5, 5);
        Tetromino tetro1 = new Tetromino(Shapes.I);
        board1.addTetromino(tetro1);
        board1.setMove('R', 2);
        board1.animate(tetro1);
        board1.draw();
        System.out.println("Run 1: Test with a 5x5 board and I shape tetromino\n");
        System.out.println();
        
        System.out.println("Enter any character for 2nd test:");
        sc.nextLine();
        // Run 2: Test with a 7x7 board and L shape tetromino
        Tetris board2 = new Tetris(7, 7);
        Tetromino tetro2 = new Tetromino(Shapes.L);
        board2.addTetromino(tetro2);
        board2.setMove('L', 1);
        board2.animate(tetro2);
        board2.draw();
        System.out.println("Run 2: Test with a 7x7 board and L shape tetromino\n");
        System.out.println();
        
        System.out.println("Enter any character for 3rd test:");
        sc.nextLine();
        // Run 3: Test with a 10x10 board and 3 O shape tetrominos
        Tetris board3 = new Tetris(10, 10);
        Tetromino tetro3 = new Tetromino(Shapes.O);
        board3.addTetromino(tetro3);
        board3.setMove('R', 4);
        board3.animate(tetro3);
        board3.draw();
        System.out.println("Run 3: Test with a 10x10 board and 3 O shape tetromino\n");
        System.out.println();
        
        System.out.println("Enter any character for 4th test:");
        sc.nextLine();
        // Run 4: Test with a 12x12 board and T shape tetromino
        Tetris board4 = new Tetris(12, 12);
        Tetromino tetro4 = new Tetromino(Shapes.T);
        board4.addTetromino(tetro4);
        board4.setMove('L', 2);
        board4.animate(tetro4);
        board4.draw();
        System.out.println("Run 4: Test with a 12x12 board and T shape tetromino\n");
        System.out.println();
    
        System.out.println("Enter any character for 5th test:");
        sc.nextLine();
        // Run 5: Test with a 20x20 board and Z shape tetromino
        Tetris board5 = new Tetris(20, 20);
        Tetromino tetro5 = new Tetromino(Shapes.Z);
        board5.addTetromino(tetro5);
        board5.setMove('R', 10);
        board5.animate(tetro5);
        board5.draw();
        System.out.println("Run 5: Test with a 20x20 board and Z shape tetromino\n");
        System.out.println();
    }
}