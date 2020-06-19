# CS11 C++ Track
# Assignment 5
# Kyriacos Xanthos
# kxanthos@caltech.edu
#
# Makefile performs all the necessary compilations
# Gives the ability to run the programs with a single command
# make test: runs the test-rational to check the unit converter
# make clean: cleans all the object files made  with make
# .PHONY to say that the clean target isn’t a real file
#
#

CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wno-unused-value
TEST_RAT_OBJS = testbase.o test-rational.o rational.o

all : test-rational

test-rational : $(TEST_RAT_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

test : 
	./test-rational

clean:
	rm -f test-rational *.o *~

.PHONY: all test clean


