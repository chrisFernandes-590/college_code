#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
  int diskSize, blockSize, fileSize;

  cout << "Enter disk size (in blocks): ";
  cin >> diskSize;

  vector<int> disk(diskSize, 0); // 0 = free, 1 = occupied

  cout << "Enter block size: ";
  cin >> blockSize;

  cout << "Enter file size: ";
  cin >> fileSize;

  int blocksNeeded = ceil((float)fileSize / blockSize);

  cout << "Blocks needed: " << blocksNeeded << endl;

  int start = -1, count = 0;

  // find contiguous free blocks
  for (int i = 0; i < diskSize; i++)
  {
    if (disk[i] == 0)
    {
      count++;
      if (count == blocksNeeded)
      {
        start = i - blocksNeeded + 1;
        break;
      }
    }
    else
    {
      count = 0;
    }
  }

  if (start != -1)
  {
    cout << "File allocated from block " << start
         << " to " << start + blocksNeeded - 1 << endl;

    for (int i = start; i < start + blocksNeeded; i++)
    {
      disk[i] = 1;
    }
  }
  else
  {
    cout << "Allocation failed (no contiguous space)\n";
  }

  return 0;
}