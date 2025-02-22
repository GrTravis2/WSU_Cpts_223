main: main.o
	g++ -g main.o -o MA2

main.o: BST.h
	g++ -std=c++11 -c -g -Wall main.cpp

clean:
	-rm *.o
	-rm *.gch
	-rm *.exe

debug:
	leaks -atExit --list -- ./MA2

run:
	@./MA2