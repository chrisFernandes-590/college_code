#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Item
{
  int value, weight;
};

bool cmp(Item a, Item b)
{
  double r1 = (double)a.value / a.weight;
  double r2 = (double)b.value / b.weight;
  return r1 > r2;
}

double fractionalKnapsack(int W, Item arr[], int n)
{
  sort(arr, arr + n, cmp);

  double totalValue = 0.0;

  for (int i = 0; i < n; i++)
  {
    if (arr[i].weight <= W)
    {
      // take full item
      W -= arr[i].weight;
      totalValue += arr[i].value;
    }
    else
    {
      // fractional weight
      totalValue += arr[i].value * ((double)W / arr[i].weight);
      break;
    }
  }
  return totalValue;
}

int main()
{
  int n, W;

  cout << "Enter number of elements: " << endl;
  cin >> n;
  Item arr[n];

  cout << "Enter profit and weight for each item:\n";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i].value >> arr[i].weight;
  }

  cout << "Enter the weight of the bag: " << endl;
  cin >> W;

  double maxProfit = fractionalKnapsack(W, arr, n);

  cout << "Maximum Profit: " << maxProfit << endl;
  return 0;
}