# this target will compile all the files
all: hhsum

hhsum: testhhs.o hhsum.o
	g++ testhhs.o hhsum.o -o hhsum

testhhs.o: testhhs.cpp
	g++ -c testhhs.cpp

hhsum.o: hhsum.cpp
	g++ -c hhsum.cpp

clean:
	rm -rf *o hhsum 


