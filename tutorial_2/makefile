main: main.o team.o teammember.o
	g++ -g main.o team.o teammember.o -o main

main.o: main.cpp
	g++ -Wall -g -c main.cpp

team.o: team.cpp team.hpp
	g++ -Wall -g -c team.cpp

teammember.o: teammember.cpp teammember.hpp
	g++ -Wall -g -c teammember.cpp 

clean:
	rm -f *.o clean