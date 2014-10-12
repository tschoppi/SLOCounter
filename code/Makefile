install: all
	cp SLOCounter.out /usr/local/bin/SLOCounter

all: main.cpp fileparser.o
	g++ -Wall -o SLOCounter.out main.cpp fileparser.o

fileparser.o: fileparser.cpp fileparser.hpp
	g++ -Wall -o fileparser.o -c fileparser.cpp

clean:
	rm *.o 
