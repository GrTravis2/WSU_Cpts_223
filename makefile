
main: linux_cmd_data.o linux_cmds.o list_test.o main.o
	g++ -g linux_cmd_data.o linux_cmds.o list_test.o main.o -o PA1

main.o: main.cpp
	g++ -std=c++11 -c -g -Wall main.cpp 

linux_cmd_data.o: linux_cmd_data.cpp linux_cmd_data.hpp list.hpp
	g++ -std=c++11 -c -g -Wall linux_cmd_data.cpp

linux_cmds.o: linux_cmds.cpp linux_cmds.hpp node.hpp list.hpp linux_cmd_data.hpp
	g++ -std=c++11 -c -g -Wall linux_cmds.cpp

list_test.o: list_test.cpp list.hpp node.hpp list_test.hpp
	g++ -std=c++11 -c -g -Wall list_test.cpp 

clean: 
	-rm *.o
	-rm *.gch
	-rm *.exe

run:
	@./PA1