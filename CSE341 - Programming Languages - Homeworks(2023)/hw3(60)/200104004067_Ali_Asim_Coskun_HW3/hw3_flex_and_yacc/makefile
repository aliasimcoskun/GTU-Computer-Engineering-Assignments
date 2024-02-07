all: compile run 

compile:
	@bison -dy gpp_interpreter.y
	@flex gpp_interpreter.l
	@gcc -o gpp_interpreter lex.yy.c y.tab.c -lfl
run:
	@./gpp_interpreter < test.g++