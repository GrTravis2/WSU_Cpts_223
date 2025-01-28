COMPILER = g++
FLAGS = -std=c++11
COMPILE = $(COMPILER) $(FLAGS)

main: main.o node.o list.o linux_cmd_data.o linux_cmds.o list_test.o
	g++ -g main.o node.o list.o linux_cmd_data.o linux_cmds.o -o main

main.o: main.cpp
	COMPILE -c -g -Wall main.cpp 

node.o: node.hpp
	COMPILE -c -g -Wall node.hpp 

list.o: list.hpp
	COMPILE -c -g -Wall list.hpp

linux_cmd_data.o: linux_cmd_data.cpp
	COMPILE -c -g -Wall linux_cmd_data.cpp

linux_cmds.o: linux_cmds.cpp
	COMPILE -c -g -Wall linux_cmds.cpp

list_test.o: list_test.cpp
	COMPILE -c -g -Wall list_test.cpp 

clean: 
	-rm *.o

run:
	@./main