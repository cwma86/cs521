#ifndef Insertion_Sort_h
#define Insertion_Sort_h
#include "SortInterface.h"
class InsertionSort:public SortInterface{
public:
  InsertionSort(int* array, int size);
  virtual ~InsertionSort(){};
private:

  // Perform the insertion sort
  void sort(int* array, int size);

};
#endif /* !Sort_Interface*/