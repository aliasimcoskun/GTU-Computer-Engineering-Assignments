all: clear compile run clean

compile: driver1.cpp tetris.cpp tetromino.cpp tetromino.h tetris.h
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@g++	-std=c++11 driver1.cpp tetris.cpp tetromino.cpp -o driver

run:
	@echo "-------------------------------------------"
	@echo "Running the tests...."
	@echo "================================================================================="
	./Driver
	@echo "================================================================================="
	@echo
	@echo "Completed tests...."

clean:
	@echo "-------------------------------------------"
	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f driver
	
clear:
	clear