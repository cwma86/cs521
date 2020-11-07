#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <unistd.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <chrono>
#include <iostream>
#include "SortInterface.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "NoSort.h"
#include "QuickSort.h"


void buildRandomArray(int* randomArray, int size){
  srand (time(0));
  /* initialize random seed: */
  for (auto i = 0; i < size; i++)
  {

    /* generate number between 0 and 100: */
    *(randomArray+i) = rand() % 100;

  }
}

int main (int argc, char *argv[])
{
  char opt;
  int arraySize = 100;
  int sortType = 0;
  bool verboseOutput = false;
  while((opt = getopt(argc, argv, ":iqvhma:")) != -1)
  {
    switch(opt)
    {
      case 'a':
        arraySize = atoi(optarg);
        break;
      case 'i':
        sortType = 0;
        std::cout << "insert sort" << std::endl;
        break;
      case 'q':
        sortType = 1;
        break;
      case 'm':
        std::cout << "merge sort" << std::endl;
        sortType = 2;
        break;
      case 'v':
        verboseOutput = true;
        break;
      case 'h':
        std::cout << "-a input array size (default:100" << std::endl;
        std::cout << "-i insertion sort (default sort)" << std::endl;
        std::cout << "-q quick sort" << std::endl;
        std::cout << "-m merge sort" << std::endl;
        std::cout << "-v verbose output" << std::endl;
        break;
      default:
        std::cout << "d" << std::endl;
        break;

    }
  }
  std::cout << "sortType:" << sortType << std::endl;

  // Build a Random Array
  int* randomArray = new int[arraySize];
  std::cout << "building array size: " << arraySize << std::endl;
  buildRandomArray(randomArray, arraySize);

  // Print the random array
  SortInterface* sort = new NoSort(randomArray, arraySize);
  if(verboseOutput)
  {
    std::cout << "Unsorted array:" << std::endl;
    sort->printArray(randomArray, arraySize);
  }
  if(sort->checkIfSorted(randomArray, arraySize))
  {
    std::cout << "array is sorted" << std::endl;
  }
  else
  {
    std::cout << "Array is not sorted" << std::endl;
  }
  delete sort;

  auto sortStartTime = std::chrono::high_resolution_clock::now();
  if(sortType == 0)
  {
    sort = new InsertionSort(randomArray, arraySize);
  }
  else if(sortType == 1)
  {
    sort = new QuickSort(randomArray, arraySize);
  }
  else if(sortType == 2)
  {
    sort = new MergeSort(randomArray, arraySize);
  }
  else
  {
    std::cout << "Error - Invalid Sort type" << std::endl;
    return 1;
  }
  auto sortStopTime = std::chrono::high_resolution_clock::now();
  auto sortRunTime = std::chrono::duration_cast<std::chrono::microseconds>(sortStopTime - sortStartTime);
  std::cout << "Sort runtime:" << sortRunTime.count() << " microseconds" << std::endl;
  if(verboseOutput)
  {
    std::cout << "Sorted array:" << std::endl;
    sort->printArray(randomArray, arraySize);
  }
  // check if array is sorted
  if(sort->checkIfSorted(randomArray, arraySize))
  {
    std::cout << "array is sorted" << std::endl;
  }
  else
  {
    std::cout << "Array is not sorted" << std::endl;
  }
  delete sort;
  delete randomArray;
  return 0;
}
