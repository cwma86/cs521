#ifndef No_Sort_h
#define No_Sort_h
#include "interface/SortInterface.h"

// Test class for using the sort interface 
//   functionality without performing a sort
class NoSort:public SortInterface
{
public:
  NoSort(int* array, int size)
  {
    sort(array, size);
  };
  virtual ~NoSort(){};
private:
  void sort(int* array, int size){};
};

#endif /* !No_Sort_h*/
