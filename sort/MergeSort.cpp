#include "MergeSort.h"
#include <list>
#include <algorithm>

MergeSort::MergeSort(int* array, int size)
{
  std::cout << "Performing Merge Sort" << std::endl;
  sort(array, size);
  std::cout << "Merge Sort Completed" << std::endl;
}

void MergeSort::sort(int* array, int size)
{
  doMergeSort(array, 0, size);
}

void MergeSort::doMergeSort(int* array, int left, int size)
{
    if (size > 1)
    {
      // Build the left and right arrays
      int leftSize = (size) / 2;
      int rightIndex = leftSize + left;
      int rightSize = size - leftSize;
      int* leftArray = new int[leftSize];
      std::copy(array, array+leftSize, leftArray);
      int* rightArray = new int[rightSize];
      std::copy(array+rightIndex, array+size, rightArray);

      // Sort the left and right halves
      doMergeSort(leftArray, 0, leftSize);
      doMergeSort(rightArray, 0, rightSize);

      // Merge the left and right haves back to the initial input array
      merge(array, leftArray, leftSize , rightArray, rightSize);

      // Clean up the temp arrays
      delete[] leftArray;
      delete[] rightArray;
    }
}

void MergeSort::merge(int* array, int* leftArray, int leftSize, int* rightArray, int rightSize)
{
  int arrayIndex = 0;
  int i = 0;
  int j = 0;
  while(i < leftSize)
  {
    while(j < rightSize)
    {
      if(i >= leftSize)
      {
        // Append all right values to end of the array
        array[arrayIndex] = rightArray[j];
        j++;
        arrayIndex++;
      }
      else if(leftArray[i] < rightArray[j])
      {
        // insert left array value
        array[arrayIndex] = leftArray[i];
        i++;
        arrayIndex++;
      }
      else
      {
        // insert right array value
        array[arrayIndex] = rightArray[j];
        j++;
        arrayIndex++;
      }
    }
    if(i < leftSize)
    {
      // append all remaining left values to the end of the array
      array[arrayIndex] = leftArray[i];
      i++;
      arrayIndex++;
    }
  }
}

