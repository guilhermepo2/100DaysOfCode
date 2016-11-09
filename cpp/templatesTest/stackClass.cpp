#include <iostream>

template < typename T>
class Stack
{
private:
  int size;
  int top;
  T * stackPointer;

public:
  Stack(int = 10);

  ~Stack()
  {
    delete [] stackPointer;
  }

  bool push(const T &);
  bool pop(T & );

  bool isEmpty() const
  {
    return top == -1;
  }

  bool isFull() const
  {
    return top == size - 1;
  }
  
};

template < typename T >
Stack < T >::Stack(int s)
  : size(s > 0 ? s : 10),
    top(-1),
    stackPointer(new T[size])
{ 
}

template < typename T >
bool Stack< T >::push(const T &pushValue)
{
  if(!isFull())
    {
      stackPointer[++top] = pushValue;
      return true;
    }

  return false;
}

template < typename T >
bool Stack< T >::pop(T &popValue)
{
  if(!isEmpty())
    {
      popValue = stackPointer[top--];
      return true;
    }

  return false;
}


int main()
{
  Stack<double> doubleStack(5);
  double doubleValue = 1.3;
  while(doubleStack.push(doubleValue))
    {
      doubleValue += doubleValue;
    }
  std::cout << "popping double stack" << std::endl;
  while(doubleStack.pop(doubleValue))
    std::cout << doubleValue << " ";
  std::cout << std::endl;

  Stack<int> intStack(5);
  int intValue = 1;
  while(intStack.push(intValue))
    intValue++;
  std::cout << "popping int stack" << std::endl;
  while(intStack.pop(intValue))
    std::cout << intValue << " ";
  std::cout << std::endl;
}
