#include <iostream>
#include <thread>
#include <chrono>
#include <string>

bool printing = false;

void print_message()
{
  std::this_thread::sleep_for(std::chrono::milliseconds(5000));
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
  t1.detach();
  std::thread t2(print_message);
  t2.detach();
  std::thread t3(print_message);
  t3.detach();
  std::thread t4(print_message);
  t4.detach();
  std::thread t5(print_message);
  t5.detach();
  std::thread t6(print_message);
  t6.detach();
  std::thread t7(print_message);
  t7.detach();
  std::thread t8(print_message);
  t8.detach();
  std::thread t9(print_message);
  t9.detach();
  std::thread t10(print_message);
  t10.detach();
  std::thread t11(print_message);
  t11.detach();
  std::thread t12(print_message);
  t12.detach();
  std::thread t13(print_message);
  t13.detach();
  std::thread t14(print_message);
  t14.detach();
    
  printing = true;
  std::cout << "Hello from the main function" << std::endl;
  printing = false;

    std::this_thread::sleep_for(std::chrono::milliseconds(10000));

  // t1.join();
  // t2.join();
  // t3.join();
  // t4.join();
  // t5.join();
  // t6.join();
  // t7.join();
  // t8.join();
  // t9.join();
  // t10.join();
  // t11.join();
  // t12.join();
  // t13.join();
  // t14.join();
  return 0;
}
