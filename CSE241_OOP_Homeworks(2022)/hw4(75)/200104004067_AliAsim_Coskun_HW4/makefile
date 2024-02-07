all: clean driver

driver: driver.cpp DoY.cpp DoY.h
	@g++ -std=c++11 -o driver driver.cpp DoY.cpp
	@./driver

clean:
	@echo "Removing compiled files..."
	@rm -f *.o
	@rm -f driver