#include <iostream>
using namespace std;

struct Job
{
  int id, deadline, profit;
};

bool cmp(Job a, Job b)
{
  return a.profit > b.profit;
}

void JobSequencing(Job arr[], int n)
{
  sort(arr, arr + n, cmp);

  // max deadline
  int dMax = 0;
  for (int i = 0; i < n; i++)
  {
    if (dMax < arr[i].deadline)
    {
      dMax = arr[i].deadline;
    }
  }

  int slot[dMax + 1];
  fill(slot, slot + dMax + 1, 0);
  int totalProfit = 0;

  // assign
  for (int i = 0; i < n; i++)
  {
    for (int j = arr[i].deadline; j > 0; j--)
    {
      if (slot[j] == 0)
      {
        slot[j] = arr[i].id;
        totalProfit += arr[i].profit;
        break;
      }
    }
    // Output selected jobs
    cout << "Selected Jobs: ";
    for (int i = 1; i <= dMax; i++)
    {
      if (slot[i] != 0)
        cout << "j" << slot[i] << " ";
    }

    cout << "\nTotal Profit: "
         << totalProfit << endl;
  }
}

int main()
{
  int n;

  cout << "Enter number of jobs: " << endl;
  cin >> n;

  Job arr[n];

  cout << "Enter deadline and profit:\n";
  for (int i = 0; i < n; i++)
  {
    arr[i].id = i + 1;
    cin >> arr[i].deadline >> arr[i].profit;
  }

  JobSequencing(arr, n);
  return 0;
}