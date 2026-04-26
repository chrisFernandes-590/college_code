#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n, m;

  cout << "Enter the number of partitions: ";
  cin >> n;

  vector<int> partitions(n);
  cout << "Enter the sizes of partitions: ";
  for (int i = 0; i < n; i++)
  {
    cin >> partitions[i];
  }

  cout << "Enter the no. of processes: ";
  cin >> m;

  vector<int> processes(m);
  cout << "Enter the sizes of processes: ";
  for (int i = 0; i < m; i++)
  {
    cin >> processes[i];
  }

  vector<int> allocation(m, -1);

  // first fit
  // for (int i = 0; i < m; i++)
  // {
  //   for (int j = 0; j < n; j++)
  //   {
  //     if (partitions[j] >= processes[i])
  //     {
  //       allocation[i] = j;
  //       partitions[j] -= processes[i];
  //       break;
  //     }
  //   }
  // }

  // BEST FIT

  for (int i = 0; i < m; i++)
  {
    int bestIdx = -1;
    int minDiff = INT_MAX;

    for (int j = 0; j < n; j++)
    {
      if (partitions[j] >= processes[i])
      {
        int diff = partitions[j] - processes[i];
        if (diff < minDiff)
        {
          minDiff = diff;
          bestIdx = j;
        }
      }
    }
    if (bestIdx != -1)
    {
      allocation[i] = bestIdx;
      partitions[bestIdx] -= processes[i];
    }
  }

  // out
  cout << "\nProcess\tSize\tBlock\n";
  for (int i = 0; i < m; i++)
  {
    cout << "P" << i + 1 << "\t" << processes[i] << "\t";
    if (allocation[i] != -1)
    {
      cout << allocation[i] + 1;
    }
    else
    {
      cout << "No allocation";
    }
    cout << endl;
  }

  // fragmentation
  int totalFree = 0;
  for (int i = 0; i < n; i++)
  {
    totalFree += partitions[i];
  }

  cout << "\nTotal free memory: " << totalFree << endl;

  for (int i = 0; i < m; i++)
  {
    if (allocation[i] == -1 && totalFree >= processes[i])
    {
      cout << "Process P" << i + 1
           << " could not be allocated due to External Fragmentation\n";
    }
  }

  return 0;
}