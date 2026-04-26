#include <iostream>
#include <vector>
using namespace std;

struct Block
{
  int size;
  int pid; // -1 means free
};

int main()
{
  int totalMemory;
  cout << "Enter total memory: ";
  cin >> totalMemory;

  vector<Block> mem;
  mem.push_back({totalMemory, -1}); // initially all free

  int q;
  cout << "Enter number of operations: ";
  cin >> q;

  while (q--)
  {
    char type;
    cin >> type;

    // Allocation
    if (type == 'A')
    {
      int pid, size;
      cin >> pid >> size;

      bool done = false;

      for (int i = 0; i < mem.size(); i++)
      {
        if (mem[i].pid == -1 && mem[i].size >= size)
        {

          int rem = mem[i].size - size;

          mem[i].size = size;
          mem[i].pid = pid;

          if (rem > 0)
          {
            mem.insert(mem.begin() + i + 1, {rem, -1});
          }

          done = true;
          break;
        }
      }

      if (!done)
      {
        cout << "Process " << pid << " not allocated\n";
      }
    }

    // Deallocation
    else if (type == 'D')
    {
      int pid;
      cin >> pid;

      for (int i = 0; i < mem.size(); i++)
      {
        if (mem[i].pid == pid)
        {
          mem[i].pid = -1;

          // merge next
          if (i + 1 < mem.size() && mem[i + 1].pid == -1)
          {
            mem[i].size += mem[i + 1].size;
            mem.erase(mem.begin() + i + 1);
          }

          // merge previous
          if (i - 1 >= 0 && mem[i - 1].pid == -1)
          {
            mem[i - 1].size += mem[i].size;
            mem.erase(mem.begin() + i);
          }

          break;
        }
      }
    }

    // Print memory
    cout << "\nMemory:\n";
    for (int i = 0; i < mem.size(); i++)
    {
      if (mem[i].pid == -1)
        cout << "Free(" << mem[i].size << ") ";
      else
        cout << "P" << mem[i].pid << "(" << mem[i].size << ") ";
    }
    cout << "\n";
  }

  return 0;
}