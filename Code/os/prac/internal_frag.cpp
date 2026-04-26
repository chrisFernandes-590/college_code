#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n, m;

  cout << "Enter the number of partitions: ";
  cin >> n;

  vector<int> partitions(n);
  ;
  cout << "Enter the partition sizes\n";
  for (int i = 0; i < n; i++)
  {
    cin >> partitions[i];
  }

  cout << "Enter the number of processes: ";
  cin >> m;

  vector<int> processes(m);
  cout << "Enter the process sizes\n";
  for (int i = 0; i < m; i++)
  {
    cin >> processes[i];
  }

  vector<int> allocation(m, -1);
  vector<int> frag(m, 0);
  vector<bool> used(n, false);

  // first fit allocation
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (!used[j] && partitions[j] >= processes[i])
      {
        allocation[i] = j;
        used[j] = true;
        frag[i] = partitions[j] - processes[i];
        break;
      }
    }
  }

  // out table
  cout << "\nProcess\tSize\tPartition\tFragmentation\n";
  for (int i = 0; i < m; i++)
  {
    cout << "P" << i + 1 << "\t" << processes[i] << "\t";
    if (allocation[i] != -1)
    {
      cout << allocation[i] + 1 << "\t\t" << frag[i];
    }
    else
    {
      cout << "No allocation\t0";
    }
    cout << endl;
  }
  return 0;
}