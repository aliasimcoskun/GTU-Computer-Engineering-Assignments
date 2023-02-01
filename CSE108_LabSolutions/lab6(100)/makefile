all: clear compile run clean

compile: main.c 
	@echo "Compiling..."
	@gcc -o test main.c

run:
	@echo "Running the tests...."
	./test
	@echo "\n"
	@echo "Completed tests...."

clean:
	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f test
	
clear:
	@clear
