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
};
#endif /* !Sort_Interface*/