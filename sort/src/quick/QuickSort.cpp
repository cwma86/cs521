#include "QuickSort.h"
QuickSort::QuickSort(int* array, int size){
  std::cout << "Performing Quick Sort" << std::endl;
  sort(array, size);
  std::cout << "Quick Sort Completed" << std::endl;
}
void QuickSort::sort(int* array, int size)
{
  quickSort(array, 0, size);
}

void QuickSort::quickSort(int* array, int low, int high)
{
  if( low < high)
  {
    int part = partition(array, low, high);
    quickSort(array, low, part-1);
    quickSort(array, part+1, high);

  }
}
int QuickSort::partition(int* array, int low, int high)
{
  // Create Pivot
  int pivotIndex = getPivotIndex(array, high);
  int index = low;
  for(int i = low; i < pivotIndex; i++)
  {
    if (array[i] < array[pivotIndex])
    {
      swap(array, index, i);
      index++;
    }
  }
  swap(array, index, pivotIndex);
  return index;
}

void QuickSort::swap(int* array, int index1, int index2){
  int tempValue = array[index1];
  array[index1] = array[index2];
  array[index2] = tempValue;
}
