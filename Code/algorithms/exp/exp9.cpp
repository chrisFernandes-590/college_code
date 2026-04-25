#include <iostream>
using namespace std;

#define MAX 100

int main()
{
  int n, W;

  cout << "Enter number of items: ";
  cin >> n;

  int profit[MAX], weight[MAX];

  cout << "Enter profit of items:\n";
  for (int i = 1; i <= n; i++)
    cin >> profit[i];

  cout << "Enter weight of items:\n";
  for (int i = 1; i <= n; i++)
    cin >> weight[i];

  cout << "Enter capacity of knapsack: ";
  cin >> W;

  int V[MAX][MAX];

  // Initialize
  for (int i = 0; i <= n; i++)
  {
    for (int w = 0; w <= W; w++)
    {
      if (i == 0 || w == 0)
        V[i][w] = 0;
      else if (weight[i] <= w)
      {
        V[i][w] = max(
            profit[i] + V[i - 1][w - weight[i]],
            V[i - 1][w]);
      }
      else
      {
        V[i][w] = V[i - 1][w];
      }
    }
  }

  cout << "Maximum Profit: " << V[n][W] << endl;

  // Backtracking to find selected items
  int i = n, k = W;

  cout << "Selected items: ";
  while (i > 0 && k > 0)
  {
    if (V[i][k] != V[i - 1][k])
    {
      cout << "Item" << i << " ";
      k = k - weight[i];
    }
    i--;
  }

  return 0;
}