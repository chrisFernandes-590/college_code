#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

int counter = 0;
mutex mtx;

void increment(string thread_name)
{
  for (int i = 0; i < 3; i++)
  {
    cout << thread_name << " trying to acquire lock...\n";

    mtx.lock(); // acquire lock

    cout << thread_name << " is running (lock acquired)\n";

    int temp = counter;
    this_thread::sleep_for(chrono::milliseconds(500)); // simulate delay
    temp++;
    counter = temp;

    cout << thread_name << " updated counter to " << counter << endl;

    cout << thread_name << " releasing lock\n\n";
    mtx.unlock(); // release lock

    this_thread::sleep_for(chrono::milliseconds(300));
  }
}

int main()
{
  thread t1(increment, "t1");
  thread t2(increment, "t2");

  t1.join();
  t2.join();

  cout << "Final Counter Value: " << counter << endl;

  return 0;
}