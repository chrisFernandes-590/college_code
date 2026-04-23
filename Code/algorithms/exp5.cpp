#include <iostream>
using namespace std;

pair<int, int> maxMin(int arr[], int low, int high)
{
  // Base case: only one element
  if (low == high)
  {
    return {arr[low], arr[low]};
  }

  // Base case: two elements
  if (high == low + 1)
  {
    if (arr[low] > arr[high])
      return {arr[low], arr[high]};
    else
      return {arr[high], arr[low]};
  }

  // Divide
  int mid = (low + high) / 2;

  pair<int, int> left = maxMin(arr, low, mid);
  pair<int, int> right = maxMin(arr, mid + 1, high);

  // Conquer
  int maximum = max(left.first, right.first);
  int minimum = min(left.second, right.second);

  return {maximum, minimum};
}

void print(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}
int main()
{
  int arr[] = {3, 5, 1, 8, 2, 9, 4};
  int n = sizeof(arr) / sizeof(arr[0]);

  pair<int, int> result = maxMin(arr, 0, n - 1);

  print(arr, n);
  cout << "Maximum: " << result.first << endl;
  cout << "Minimum: " << result.second << endl;

  return 0;
}