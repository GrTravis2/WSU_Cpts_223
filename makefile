
main: main.o
	g++ -g main.o -o PA2

main.o: TestListMyJosephus.o TestVectorMyJosephus.o
	g++ -std=c++11 -c -g -Wall main.cpp 

Destination.o: Destination.hpp
	g++ -std=c++11 -c -g -Wall Destination.cpp

TestListMyJosephus.o: ListMyJosephus.o TestListMyJosephus.hpp
	g++ -std=c++11 -c -g -Wall TestListMyJosephus.cpp

TestVectorMyJosephus.o: VectorMyJosephus.o TestVectorMyJosephus.hpp
	g++ -std=c++11 -c -g -Wall TestVectorMyJosephus.cpp

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