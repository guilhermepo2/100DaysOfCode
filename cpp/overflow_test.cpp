#include <iostream>

int main()
{
  short int a = 0;
  unsigned short int aa = 0;
  int b = 0;
  unsigned int bb = 0;
  long int c = 0;
  long unsigned int cc = 0;

  a++;
  while(a > 0)
    {
      a++;
    }
  std::cout << "short int: " << --a << std::endl;

  aa++;
  while(aa > 0)
    {
      aa++;
    }
  std::cout << "unsigned short int: " << --aa << std::endl;

  b++;
  while(b > 0)
    {
      b++;
    }
  std::cout << "int: " << --b << std::endl;

  bb++;
  while(bb > 0)
    {
      bb++;
    }
  std::cout << "unsigned int: " << --bb << std::endl;

  c++;
  while(c > 0)
    {
      c++;
    }
  std::cout << "long int: " << --c << std::endl;

  cc++;
  while(cc > 0)
    {
      cc++;
    }
  std::cout << "long unsigned int int: " << --cc << std::endl;
}
