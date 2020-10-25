# Makefile
# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -g -std=c++11

# ****************************************************
# Targets needed to bring the executable up to date

SortTest: SortTest.o InsertionSort.o QuickSort.o MergeSort.o
	$(CXX) $(CXXFLAGS) -o SortTest SortTest.o InsertionSort.o QuickSort.o MergeSort.o

# The main.o target can be written more simply

main.o: SortTest.cpp InsertionSort.h QuickSort.h MergeSort.h
	$(CXX) $(CXXFLAGS) -c SortTest.cpp

InsertionSort.o: InsertionSort.cpp InsertionSort.h

QuickSort.o: QuickSort.cpp QuickSort.h

MergeSort.o: MergeSort.cpp MergeSort.h

clean:
	rm -f *.o
	rm -f *.out
	rm -f SortTest