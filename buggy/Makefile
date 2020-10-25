CXXFLAGS=-MD -MP

# this target will compile all the files
all: hhsum

hhsum: testhhs.o hhsum.o
	g++ testhhs.o hhsum.o -o hhsum

clean:
	rm -rf *.o *.d hhsum

-include *.d
