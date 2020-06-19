# CS11 C++ Track
# Assignment 4
# Kyriacos Xanthos
# kxanthos@caltech.edu
#
# Makefile performs all the necessary compilations
# Gives the ability to run the programs with a single command
# make test: runs the hw3testunits to check the unit converter
# make doc : creates doxygen documentation
# make clean: cleans all the object files made  with make
# .PHONY to say that the clean target isn’t a real file
#
#

CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror -Wno-unused-value
CONVERT_OBJS = units.o convert.o
HW3TEST_OBJS = units.o testbase.o hw3testunits.o

all : convert hw3testunits

convert : $(CONVERT_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

hw3testunits : $(HW3TEST_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

test : 
	./hw3testunits

doc :
	doxygen

clean:
	rm -f convert hw3testunits *.o *~
	rm -rf docs/

.PHONY: all test doc clean


