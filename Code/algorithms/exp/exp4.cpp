#include <iostream>
using namespace std;

int mergePass = 0;

void printArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void merge(int arr[], int p, int q, int r)
{
  mergePass++;

  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], R[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];

  for (int j = 0; j < n2; j++)
    R[j] = arr[q + 1 + j];

  int i = 0, j = 0, k = p;

  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int p, int r)
{
  if (p < r)
  {
    int q = (p + r) / 2;

    mergeSort(arr, p, q);
    mergeSort(arr, q + 1, r);

    merge(arr, p, q, r);
  }
}

int main()
{
  int n;

  cout << "Enter number of elements: ";
  cin >> n;

  int arr[n];

  cout << "Enter " << n << " elements:\n";

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << "\nUnsorted Array:\n";
  printArray(arr, n);

  mergeSort(arr, 0, n - 1);

  cout << "\nSorted Array:\n";
  printArray(arr, n);

  cout << "\nMerge Operations (passes): " << mergePass << endl;

  return 0;
}