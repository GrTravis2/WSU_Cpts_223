## template makefile for new branches..

main: main.o
	g++ -std=c++11 -g TestHashMap.o TestSinglyLinkedList.o InventoryQueryTool.o ArgParse.o TestArgParse.o AmazonProduct.o main.o -o PA4

main.o: TestHashMap.o TestSinglyLinkedList.o InventoryQueryTool.o ArgParse.o TestArgParse.o AmazonProduct.o
	g++ -std=c++11 -c -g -Wall main.cpp

TestHashMap.o: TestHashMap.hpp HashMap.hpp
	g++ -std=c++11 -c -g -Wall TestHashMap.cpp

TestSinglyLinkedList.o: TestSinglyLinkedList.hpp SinglyLinkedList.hpp
	g++ -std=c++11 -c -g -Wall TestSinglyLinkedList.cpp

InventoryQueryTool.o: AmazonProduct.hpp HashMap.hpp SinglyLinkedList.hpp InventoryQueryTool.hpp
	g++ -std=c++11 -c -g -Wall InventoryQueryTool.cpp

AmazonProduct.o: AmazonProduct.hpp
	g++ -std=c++11 -c -g -Wall AmazonProduct.cpp

ArgParse.o: ArgParse.hpp
	g++ -std=c++11 -c -g -Wall ArgParse.cpp

TestArgParse.o: ArgParse.hpp TestArgParse.hpp
	g++ -std=c++11 -c -g -Wall TestArgParse.cpp

clean:
	-rm *.o
	-rm *.gch
	-rm *.exe

debug:
	leaks -atExit --list -- ./PA4

run:
	@./PA4