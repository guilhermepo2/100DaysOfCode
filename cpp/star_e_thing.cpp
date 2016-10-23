#include <iostream>

void f(int * p1, int * p2)
{
  std::cout << "====================================" << std::endl;
  std::cout << "f(int * p1, int * p2)" << std::endl;
  std::cout << "p1: " << p1 << " *p1: " << *p1 << std::endl;
  std::cout << "p2: " << p2 << " *p2: " << *p2 << std::endl;
  std::cout << "changing *p1 to 5 and *p2 to 7" << std::endl;
  *p1 = 5;
  *p2 = 7;
  std::cout << "====================================" << std::endl;
}

void g(int& x, int& y)
{
  std::cout << "====================================" << std::endl;
  std::cout << "g(int& x, int& y)" << std::endl;
  std::cout << "x: " << x << " &x: " << &x << std::endl;
  std::cout << "y: " << y << " &y: " << &y << std::endl;
  std::cout << "changing x to 10 and y to 11" << std::endl;
  x = 10;
  y = 11;
  std::cout << "====================================" << std::endl;
}

void h(int i, int j)
{
  std::cout << "====================================" << std::endl;
  std::cout << "h(int i, int j)" << std::endl;
  std::cout << "i: " << i << " &i: " << &i << std::endl;
  std::cout << "j: " << j << " &j: " << &j << std::endl;
  std::cout << "changing i to 99 and j to 100" << std::endl;
  i = 99;
  j = 100;
  std::cout << "====================================" << std::endl;
}


int main()
{
  int aa = 2, bb = 3;
  int * a = &aa, * b = &bb;
  std::cout << "created 2 ints: aa and bb" << std::endl;
  std::cout << "created 2 pointers: * a and * b" << std::endl;
  std::cout << "aa: " << aa << " &aa: " << &aa << std::endl;
  std::cout << "bb: " << bb << " &bb: " << &bb << std::endl;
  std::cout << "a: " << a << " *a: " << *a << std::endl;
  std::cout << "b: " << b << " *b: " << *b << std::endl;
  std::cout << std::endl;  std::cout << std::endl;
  std::cout << "function: h(aa, bb)" << std::endl;
  h(aa, bb);
  std::cout << "after h(aa, bb)" << std::endl;
  std::cout << "aa: " << aa << " &aa: " << &aa << std::endl;
  std::cout << "bb: " << bb << " &bb: " << &bb << std::endl;
  std::cout << std::endl;  std::cout << std::endl;
  std::cout << "function: h(*a, *b)" << std::endl;
  h(*a, *b);
  std::cout << "after h(*a, *b)" << std::endl;
  std::cout << "a: " << a << " *a: " << *a << std::endl;
  std::cout << "b: " << b << " *b: " << *b << std::endl;
  std::cout << std::endl;  std::cout << std::endl;
  std::cout << "function: f(a, b)" << std::endl;
  f(a, b);
  std::cout << "after f(a, b)" << std::endl;
  std::cout << "a: " << a << " *a: " << *a << std::endl;
  std::cout << "b: " << b << " *b: " << *b << std::endl;
  std::cout << std::endl;  std::cout << std::endl;
  std::cout << "function: g(*a, *b)" << std::endl;
  g(*a, *b);
  std::cout << "after g(*a, *b)" << std::endl;
  std::cout << "a: " << a << " *a: " << *a << std::endl;
  std::cout << "b: " << b << " *b: " << *b << std::endl;
  return 0;
}
