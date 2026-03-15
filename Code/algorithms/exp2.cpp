#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key, int &comparisons)
{
  comparisons = 0;

  for (int i = 0; i < n; i++)
  {
    comparisons++;

    if (arr[i] == key)
      return i;
  }

  return -1;
}

int binarySearch(int arr[], int n, int key, int &comparisons)
{
  int low = 0;
  int high = n - 1;
  comparisons = 0;

  while (low <= high)
  {
    int mid = (low + high) / 2;
    comparisons++;

    if (arr[mid] == key)
      return mid;

    else if (key < arr[mid])
      high = mid - 1;

    else
      low = mid + 1;
  }

  return -1;
}

void printArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void sortArray(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
        swap(arr[j], arr[j + 1]);
    }
  }
}

int main()
{
  int n, key;

  cout << "Enter number of elements: ";
  cin >> n;

  int arr[n];

  cout << "Enter " << n << " elements:\n";
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << "\nArray:\n";
  printArray(arr, n);

  cout << "\nEnter element to search: ";
  cin >> key;

  int comp1, comp2;

  int pos1 = linearSearch(arr, n, key, comp1);

  if (pos1 != -1)
    cout << "\nLinear Search: Element found at position " << pos1 + 1;
  else
    cout << "\nLinear Search: Element not found";

  cout << "\nComparisons made: " << comp1 << endl;

  sortArray(arr, n);

  cout << "\nSorted Array for Binary Search:\n";
  printArray(arr, n);

  int pos2 = binarySearch(arr, n, key, comp2);

  if (pos2 != -1)
    cout << "\nBinary Search: Element found at position " << pos2 + 1;
  else
    cout << "\nBinary Search: Element not found";

  cout << "\nComparisons made: " << comp2 << endl;

  return 0;
}