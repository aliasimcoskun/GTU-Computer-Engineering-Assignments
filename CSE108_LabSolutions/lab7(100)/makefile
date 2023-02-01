all: clear compile run clean

compile: 200104004067_AliAsim_Coskun.c 
	@echo "Compiling..."
	@gcc -o test 200104004067_AliAsim_Coskun.c 

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
