all: clean driver1 driver2

driver1: driver1.cpp tetris.cpp tetromino.cpp tetromino.h tetris.h
	@g++ -std=c++11 -o driver1 driver1.cpp tetris.cpp tetromino.cpp
	@./driver1

driver2: driver2.cpp tetris.cpp tetromino.cpp tetromino.h tetris.h
	@g++ -std=c++11 -o driver2 driver2.cpp tetris.cpp tetromino.cpp
	./driver2

clean:
	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f driver1 driver2