#ifndef Merge_Sort_h
#define Merge_Sort_h
#include <list>

#include "../interface/SortInterface.h"

class MergeSort:public SortInterface{
public:
  MergeSort(int* array, int size);
  virtual ~MergeSort(){};
private:

  // Perform the insertion sort
  void sort(int* array, int size);
  void doMergeSort(int* array, int left, int size);
  void merge(int* array, int* leftArray, int leftSize, int* rightArray, int rightSize);
};
#endif /* !Merge_Sort_h*/