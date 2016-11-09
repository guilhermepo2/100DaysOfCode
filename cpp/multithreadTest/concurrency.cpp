#include <iostream>
#include <thread>
#include <chrono>
#include <time.h>

#define THREAD_COUNT 10
bool token = false;

void hello(int a)
{
  while(true)
    {
      if(!token)
	{
	  token = true;
	  std::cout << "hello from thread " << a << std::endl;
	  token = false;
	  break;
	}
      else
	{
	  int rand_t = rand() % 100;
	  std::this_thread::sleep_for(std::chrono::milliseconds(100 + rand_t));
	}
    }
}

void foo(int a)
{
  std::cout << "foo + " << a << std::endl; 
}

int main()
{
  while(true)
    {
      std::thread * threads = new std::thread[THREAD_COUNT];
      for(int i = 0; i < THREAD_COUNT; i++)
	{
	  threads[i] = std::thread(&hello, i);
	}
      
      for(int i = 0; i < THREAD_COUNT; i++)
	{
	  threads[i].join();
	}

      for(int i = 0; i < THREAD_COUNT; i++)
	{
	  threads[i] = std::thread(&foo, i);
	}

      for(int i = 0; i < THREAD_COUNT; i++)
	{
	  threads[i].join();
	}
    }
  return 0;
}
