#ifndef Insertion_Sort_h
#define Insertion_Sort_h
#include "../interface/SortInterface.h"
class InsertionSort:public SortInterface{
public:
  InsertionSort(int* array, int size);
  virtual ~InsertionSort(){};
private:

  // Perform the insertion sort
  void sort(int* array, int size);

  // Insert the value at index to the insertlocation and shift all
  // values from insertlocation to index up 1 location
  void insert(int* array, int size,int index,int insertLocation){
    int tempValue = array[index];
    // Shift all values in the array from insert location to current location up 1 index
    for (int i = index-1; i >= insertLocation; i--)
    {
      array[i+1] = array[i];
    }
    // put the index in its new location
    array[insertLocation] = tempValue;
  }
};
#endif /* !Sort_Interface*/