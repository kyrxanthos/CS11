# CS11 C++ Track
# Assignment 6
# Kyriacos Xanthos
# kxanthos@caltech.edu
#
# Makefile performs all the necessary compilations
# Gives the ability to run the programs with a single command
# make test: runs the test-matrix to check the matrix program
# make clean: cleans all the object files made  with make
# .PHONY to say that the clean target isn’t a real file
#

CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wno-unused-value
TEST_MAT_OBJS = testbase.o test-matrix.o matrix.o

all : test-matrix

test-matrix : $(TEST_MAT_OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

test : 
	./test-matrix

clean:
	rm -f test-matrix *.o *~

.PHONY: all test clean


