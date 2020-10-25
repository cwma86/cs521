#include "MergeSort.h"
MergeSort::MergeSort(int* array, int size){
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

        // Same as (l+r)/2, but avoids
        // overflow for large l and h
        int leftSize = (size) / 2;
        int rightIndex = leftSize + left;
        int rightSize = size - leftSize;

        // Sort first and second halves
        doMergeSort(array, left, leftSize);
        doMergeSort(array, rightIndex, rightSize);

        merge(array, left, rightIndex , rightIndex + rightSize - 1);
    }
}
void MergeSort::merge(int* array, int lStartIndex,int rStartIndex, int rEndIndex)
{
  // find the sub array lengths
  int i= lStartIndex;
  int j= rStartIndex;
  while(j <= rEndIndex && i < rEndIndex)
  {
    if(array[i] <= array[j])
    {
      i++;
    }
    else
    {
      insert(array, rEndIndex - lStartIndex, j , i);
      i++;
      j++;
    }
  }
}

