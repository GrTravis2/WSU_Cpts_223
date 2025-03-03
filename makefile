main: main.o
	g++ -std=c++11 -g avl_test.o USCity.o tree_comparison.o main.o -o PA3

main.o: avl_test.cpp tree_comparison.o
	g++ -std=c++11 -c -g -Wall main.cpp

avl_test.o: avl_map.hpp avl_node.hpp avl_test.hpp
	g++ -std=c++11 -c -g -Wall avl_test.cpp

tree_comparison.o: tree_comparison.hpp tree_comparison.cpp USCity.o
	g++ -std=c++11 -c -g -Wall tree_comparison.cpp

USCity.o: USCity.cpp USCity.hpp
	g++ -std=c++11 -c -g -Wall USCity.cpp

clean:
	-rm *.o
	-rm *.gch
	-rm *.exe

debug:
	leaks -atExit --list -- ./PA3

run:
	@./PA3