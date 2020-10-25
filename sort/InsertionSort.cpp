#include "InsertionSort.h"
InsertionSort::InsertionSort(int* array, int size){
  std::cout << "Performing Insertion Sort" << std::endl;
  sort(array, size);
  std::cout << "Insertion Sort Completed" << std::endl;
}
void InsertionSort::sort(int* array, int size)
{
  int countCompares = 0;
  // Start with 2nd index in the array
  for(auto i = 1; i < size; i++)
  {
    // Check all preceding values in the array
    for(auto j = 0; j < i; j++)
    {
      countCompares++;
      if(array[i] < array[j])
      {
        // Preceeding values is greater than current value insert to the left
        insert(array, size, i, j);
        break;
      }
    }
  }
}
