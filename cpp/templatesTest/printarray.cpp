#include <iostream>

template < typename T >
void printArray(const T * const array, int count )
{
  for(int i = 0; i < count; i++)
    {
      std::cout << array[i] << " ";
    }
  std::cout << std::endl;
}

int main()
{

  const int aCount = 3;
  const int bCount = 4;
  const int cCount = 5;

  int a[ aCount ] = { 1, 2, 3 };
  float b[ bCount ] = { 1.1, 2.2, 3.3, 4.4 };
  char c[ cCount ] = "WOAH";

  std::cout << "Array a: " << std::endl;
  printArray(a, aCount);
  std::cout << "Array b: " << std::endl;
  printArray(b, bCount);
  std::cout << "Array c: " << std::endl;
  printArray(c, cCount);
  
  return 0;
}
