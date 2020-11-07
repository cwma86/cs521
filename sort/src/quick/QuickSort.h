#ifndef Quick_Sort_h
#define Quick_Sort_h
#include "../interface/SortInterface.h"
class QuickSort:public SortInterface{
public:
  QuickSort(int* array, int size);
  virtual ~QuickSort(){};
private:
  // Calls recursive quick sort algorithm
  void sort(int* array, int size);

  // performs quck sort
  void quickSort(int* array, int low, int high);

  // Partition the array and place all values less than the partition
  // to the left of the partition, and all greater values to the right
  int partition(int* array, int low, int high);

  //Swap the values at 2 indexes
  void swap(int* array, int index1, int index2);

  // given an array of size, return the pivot index
  // TODO can add logic for random pivot generation to reduce likelyhood of worst case
  virtual int getPivotIndex(int* array, int size){
    return size;
  }
};
#endif /* !Quick_Sort_h*/