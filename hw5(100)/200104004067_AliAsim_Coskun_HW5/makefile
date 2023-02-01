all: clear compile run clean

compile: main.c 
	@echo "Compiling..."
	@gcc -o test main.c -lm

run:
	@echo "Running the tests...."
	@echo "\n"
	./test
	@echo "\n"
	@echo "Completed tests...."

clean:
	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f test
	
clear:
	@clear
