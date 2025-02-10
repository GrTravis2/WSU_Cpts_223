
main: Destination.o ListMyJosephus.o VectorMyJosephus.o main.o
	g++ -g linux_cmd_data.o linux_cmds.o list_test.o main.o -o PA2

main.o: main.cpp
	g++ -std=c++11 -c -g -Wall main.cpp 

Destination.o: Destination.hpp
	g++ -std=c++11 -c -g -Wall Destination.cpp

ListMyJosephus.o: Destination.o MyJosephus.o ListMyJosephus.hpp
	g++ -std=c++11 -c -g -Wall ListMyJosephus.cpp

VectorMyJosephus.o: Destination.o MyJosephus.o VectorMyJosephus.hpp
	g++ -std=c++11 -c -g -Wall VectorMyJosephus.cpp

MyJosephus.o: MyJosephus.hpp
	g++ -std=c++11 -c -g -Wall MyJosephus.cpp 

clean: 
	-rm *.o
	-rm *.gch
	-rm *.exe

run:
	@./PA2