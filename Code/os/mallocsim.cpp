#include <iostream>
#include <vector>
using namespace std;

// Function to print results
void printResult(string algo, vector<int> allocation, vector<int> holes)
{
  cout << "\n--- " << algo << " Allocation ---\n";
  for (int i = 0; i < allocation.size(); i++)
  {
    if (allocation[i] != -1)
      cout << "Process " << i + 1 << " -> Hole " << allocation[i] + 1 << endl;
    else
      cout << "Process " << i + 1 << " -> Not Allocated\n";
  }

  cout << "Remaining Hole Sizes:\n";
  for (int i = 0; i < holes.size(); i++)
  {
    cout << "Hole " << i + 1 << ": " << holes[i] << endl;
  }
}

// First Fit
void firstFit(vector<int> holes, vector<int> processes)
{
  vector<int> allocation(processes.size(), -1);

  for (int i = 0; i < processes.size(); i++)
  {
    for (int j = 0; j < holes.size(); j++)
    {
      if (holes[j] >= processes[i])
      {
        allocation[i] = j;
        holes[j] -= processes[i];
        break;
      }
    }
  }

  printResult("First Fit", allocation, holes);
}

// Best Fit
void bestFit(vector<int> holes, vector<int> processes)
{
  vector<int> allocation(processes.size(), -1);

  for (int i = 0; i < processes.size(); i++)
  {
    int bestIdx = -1;

    for (int j = 0; j < holes.size(); j++)
    {
      if (holes[j] >= processes[i])
      {
        if (bestIdx == -1 || holes[j] < holes[bestIdx])
        {
          bestIdx = j;
        }
      }
    }

    if (bestIdx != -1)
    {
      allocation[i] = bestIdx;
      holes[bestIdx] -= processes[i];
    }
  }

  printResult("Best Fit", allocation, holes);
}

// Worst Fit
void worstFit(vector<int> holes, vector<int> processes)
{
  vector<int> allocation(processes.size(), -1);

  for (int i = 0; i < processes.size(); i++)
  {
    int worstIdx = -1;

    for (int j = 0; j < holes.size(); j++)
    {
      if (holes[j] >= processes[i])
      {
        if (worstIdx == -1 || holes[j] > holes[worstIdx])
        {
          worstIdx = j;
        }
      }
    }

    if (worstIdx != -1)
    {
      allocation[i] = worstIdx;
      holes[worstIdx] -= processes[i];
    }
  }

  printResult("Worst Fit", allocation, holes);
}

// Efficiency calculation
void efficiency(vector<int> holes, vector<int> processes)
{
  int totalMemory = 0, usedMemory = 0;

  for (int h : holes)
    totalMemory += h;
  for (int p : processes)
    usedMemory += p;

  cout << "\n--- Efficiency ---\n";
  cout << "Total Memory: " << totalMemory << endl;
  cout << "Used Memory: " << usedMemory << endl;
  cout << "Memory Utilization: " << (float)usedMemory / totalMemory * 100 << "%\n";
  cout << "Fragmentation: " << totalMemory - usedMemory << endl;
}

// Check new process allocation
void checkNewProcess(vector<int> holes, int newProcess)
{
  cout << "\n--- New Process Allocation (" << newProcess << ") ---\n";

  bool possible = false;
  for (int h : holes)
  {
    if (h >= newProcess)
    {
      possible = true;
      break;
    }
  }

  if (possible)
    cout << "Process CAN be allocated.\n";
  else
    cout << "Process CANNOT be allocated.\n";
}

int main()
{
  int m, n;

  cout << "Enter number of holes: ";
  cin >> m;
  vector<int> holes(m);

  cout << "Enter sizes of holes:\n";
  for (int i = 0; i < m; i++)
    cin >> holes[i];

  cout << "Enter number of processes: ";
  cin >> n;
  vector<int> processes(n);

  cout << "Enter sizes of processes:\n";
  for (int i = 0; i < n; i++)
    cin >> processes[i];

  firstFit(holes, processes);
  bestFit(holes, processes);
  worstFit(holes, processes);

  efficiency(holes, processes);

  int newProcess;
  cout << "\nEnter new process size: ";
  cin >> newProcess;

  checkNewProcess(holes, newProcess);

  return 0;
}