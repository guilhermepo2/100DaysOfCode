#include <iostream>
#include <thread>
#include <chrono>
#include <string>

bool printing = false;

void print_message()
{
  while(true)
    {
      if(!printing)
	{
	  printing = true;
	  std::cout << "hello" << std::endl;
	  printing = false;
	  break;
	}
      else
	{
	  std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
    }
}

int main()
{
  std::thread t1(print_message);
  std::thread t2(print_message);

  printing = true;
  std::cout << "Hello from the main function" << std::endl;
  printing = false;

  t1.join();
  t2.join();
  return 0;
}
