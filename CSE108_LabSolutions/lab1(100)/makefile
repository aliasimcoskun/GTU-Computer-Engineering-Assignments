all: clear compile run clean

compile: main.c 
	@echo "Compiling..."
	@gcc main.c -c
	@gcc main.o

run:
	@echo "Running the tests...."
	./a.out
	@echo
	@echo "Completed tests...."

clean:
	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f *.out
	
clear:
	@clear
