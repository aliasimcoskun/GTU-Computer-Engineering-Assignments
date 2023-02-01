all: clear compile run clean

compile: main4.c 
	@echo "Compiling..."
	@gcc -o test main4.c -lm

run:
	@echo "Running the tests...."
	./test
	@echo
	@echo "Completed tests...."

clean:
	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f test
	
clear:
	@clear
