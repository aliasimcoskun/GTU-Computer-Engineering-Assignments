all: clear compile run clean

compile: driver.cpp PFArray.cpp PFArray.h
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@g++	-std=c++11 driver.cpp PFArray.cpp -o driver

run:
	@echo "-------------------------------------------"
	@echo "Running the tests...."
	@echo "================================================================================="
	@./driver
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