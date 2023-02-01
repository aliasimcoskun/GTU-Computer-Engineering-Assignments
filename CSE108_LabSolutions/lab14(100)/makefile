all: clear compile run clean

compile: 200104004067.c
	@echo "-------------------------------------------"
	@echo "Compiling..."
	@gcc -o test 200104004067.c

run:
	@echo "-------------------------------------------"
	@echo "Running the tests...."
	@echo "================================================================================="
	./test
	@echo "================================================================================="
	@echo "Completed tests...."

clean:
	@echo "-------------------------------------------"
	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f test
	
clear:
	@clear
