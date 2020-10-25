#ifndef Sort_Interface_h
#define Sort_Interface_h
#include "iostream"
class SortInterface{
  public:
  SortInterface(){};
  virtual ~SortInterface(){};
  public:
  virtual void sort(int* array, int size) = 0;
  bool checkIfSorted(int* array, int size)
  {
    if( array[0] <=  array[1])
    {
      if (size-1 <= 1)
      {
        // all values in array are less than or equal to the preceding value
        return true;
      }
      return checkIfSorted(array+1, size-1);

    }
    // left value is greater than right value
    return false;
  };
  void printArray(int* array, int size)
  {
    std::cout << "randomArray";
    for (auto i =0; i <size; i++)
    {
      std::cout << "[" << i<<"]:" << array[i] << ", ";
    }
    std::cout << std::endl;
  }
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