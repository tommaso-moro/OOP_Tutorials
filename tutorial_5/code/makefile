main: main.o excessChargeFine.o fixedPenaltyFine.o parkingAttendant.o parkingFine.o juniorPA.o seniorPA.o
	g++ -Wall -g main.o excessChargeFine.o fixedPenaltyFine.o parkingAttendant.o parkingFine.o juniorPA.o seniorPA.o -o main

main.o: main.cpp
	g++ -Wall -g -c main.cpp

excessChargeFine.o: excessChargeFine.hpp excessChargeFine.cpp
	g++ -Wall -g -c excessChargeFine.cpp

fixedPenaltyFine.o: fixedPenaltyFine.hpp fixedPenaltyFine.hpp
	g++ -Wall -g -c fixedPenaltyFine.cpp

parkingAttendant.o: parkingAttendant.hpp parkingAttendant.cpp
	g++ -Wall -g -c parkingAttendant.cpp

parkingFine.o: parkingFine.hpp parkingFine.cpp
	g++ -Wall -g -c parkingFine.cpp

juniorPA.o: juniorPA.hpp juniorPA.cpp helper.hpp
	g++ -Wall -g -c juniorPA.cpp

seniorPA.o: seniorPA.hpp seniorPA.cpp
	g++ -Wall -g -c seniorPA.cpp

clean:
	rm -f *.o clean