#include <iostream>
#include <vector>
using namespace std;

vector<int> weights;  // input numbers
vector<int> selected; // 1 = included, 0 = not included
int n, targetSum;

/* Check if it's worth exploring further */
bool isPromising(int index, int currentSum, int remainingSum)
{
  return (currentSum + remainingSum >= targetSum) &&
         (currentSum == targetSum || currentSum + weights[index + 1] <= targetSum);
}

/* Backtracking function */
void findSubsets(int index, int currentSum, int remainingSum)
{
  if (isPromising(index, currentSum, remainingSum))
  {

    // If we found a valid subset
    if (currentSum == targetSum)
    {
      cout << "{ ";
      for (int i = 0; i <= index; i++)
      {
        if (selected[i] == 1)
          cout << weights[i] << " ";
      }
      cout << "}" << endl;
      return;
    }

    // Include next element
    selected[index + 1] = 1;
    findSubsets(index + 1,
                currentSum + weights[index + 1],
                remainingSum - weights[index + 1]);

    // Exclude next element
    selected[index + 1] = 0;
    findSubsets(index + 1,
                currentSum,
                remainingSum - weights[index + 1]);
  }
}

int main()
{
  int totalSum = 0;

  cout << "Enter number of elements: ";
  cin >> n;

  weights.resize(n);
  selected.resize(n, 0);

  cout << "Enter elements (in ascending order):\n";
  for (int i = 0; i < n; i++)
  {
    cin >> weights[i];
    totalSum += weights[i];
  }

  cout << "Enter target sum: ";
  cin >> targetSum;

  cout << "\nSubsets are:\n";

  findSubsets(-1, 0, totalSum);

  return 0;
}