## template makefile for new branches..

main: main.o
	g++ -std=c++11 -g ma4.o main.o -o MA4

main.o: ma4.o
	g++ -std=c++11 -c -g -Wall main.cpp

ma4.o: ma4.hpp
	g++ -std=c++11 -c -g -Wall ma4.cpp

clean:
	-rm *.o
	-rm *.gch
	-rm *.exe

debug:
	leaks -atExit --list -- ./MA4

run:
	@./MA4