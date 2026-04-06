#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <chrono>

using namespace std;

queue<int> q;
const int MAX = 5;

mutex mtx;

void producer()
{
  for (int i = 1; i <= 10; i++)
  {
    while (true)
    {
      mtx.lock();

      if (q.size() < MAX)
      {
        cout << "Producer is running...\n";
        q.push(i);
        cout << "Produced: " << i << endl;
        mtx.unlock();
        break;
      }
      else
      {
        cout << "Producer waiting (Queue Full)\n";
        mtx.unlock();
        this_thread::sleep_for(chrono::milliseconds(500));
      }
    }
  }
}

void consumer()
{
  for (int i = 1; i <= 10; i++)
  {
    while (true)
    {
      mtx.lock();

      if (!q.empty())
      {
        cout << "Consumer is running...\n";
        int item = q.front();
        q.pop();
        cout << "Consumed: " << item << endl;
        mtx.unlock();
        break;
      }
      else
      {
        cout << "Consumer waiting (Queue Empty)\n";
        mtx.unlock();
        this_thread::sleep_for(chrono::milliseconds(500));
      }
    }
  }
}

int main()
{
  thread t1(producer);
  thread t2(consumer);

  t1.join();
  t2.join();

  return 0;
}