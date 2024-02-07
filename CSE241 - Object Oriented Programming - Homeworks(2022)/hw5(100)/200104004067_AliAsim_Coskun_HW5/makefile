all: clean driver1 driver2

driver1: driver1.cpp Tetris1Darray.cpp TetrisVectorArray.cpp TetrisAdapter.cpp tetromino.cpp Abstract.h Tetris1Darray.h TetrisVectorArray.h tetromino.h
	@g++ -std=c++11 -o driver1 driver1.cpp Tetris1Darray.cpp TetrisVectorArray.cpp TetrisAdapter.cpp tetromino.cpp
	@./driver1

driver2: driver2.cpp Tetris1Darray.cpp TetrisVectorArray.cpp TetrisAdapter.cpp tetromino.cpp Abstract.h Tetris1Darray.h TetrisVectorArray.h tetromino.h
	@g++ -std=c++11 -o driver2 driver2.cpp Tetris1Darray.cpp TetrisVectorArray.cpp TetrisAdapter.cpp tetromino.cpp
	@./driver2

clean:
	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f driver2