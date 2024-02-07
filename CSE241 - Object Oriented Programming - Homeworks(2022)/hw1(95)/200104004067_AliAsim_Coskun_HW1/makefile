all: clear compile run clean

compile: Driver.cpp tetromino.cpp tetromino.h
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@g++	-std=c++11 Driver.cpp tetromino.cpp -o Driver

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
	@rm -f Driver
	
clear:
	clear