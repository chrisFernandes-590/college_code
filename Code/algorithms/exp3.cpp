#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int quickPass = 0;
int randQuickPass = 0;

void printArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int partitionQS(int arr[], int low, int high)
{
  quickPass++;

  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j < high; j++)
  {
    if (arr[j] <= pivot)
    {
      i++;
      swap(arr[i], arr[j]);
    }
  }

  swap(arr[i + 1], arr[high]);
  return i + 1;
}

void quickSort(int arr[], int low, int high)
{
  if (low < high)
  {
    int pi = partitionQS(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int partitionRand(int arr[], int low, int high)
{
  randQuickPass++;

  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j < high; j++)
  {
    if (arr[j] <= pivot)
    {
      i++;
      swap(arr[i], arr[j]);
    }
  }

  swap(arr[i + 1], arr[high]);
  return i + 1;
}

int randomizedPartition(int arr[], int low, int high)
{
  int randomIndex = low + rand() % (high - low + 1);
  swap(arr[randomIndex], arr[high]);

  return partitionRand(arr, low, high);
}

void randomizedQuickSort(int arr[], int low, int high)
{
  if (low < high)
  {
    int pi = randomizedPartition(arr, low, high);

    randomizedQuickSort(arr, low, pi - 1);
    randomizedQuickSort(arr, pi + 1, high);
  }
}

int main()
{
  srand(time(0));

  int n;
  cout << "Enter number of elements: ";
  cin >> n;

  int arr[n];

  cout << "Enter " << n << " elements:\n";
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << "\nUnsorted Array:\n";
  printArray(arr, n);

  int arr1[n], arr2[n];

  for (int i = 0; i < n; i++)
  {
    arr1[i] = arr[i];
    arr2[i] = arr[i];
  }

  quickSort(arr1, 0, n - 1);

  cout << "\nQuick Sort Result:\n";
  printArray(arr1, n);
  cout << "Partitions (passes): " << quickPass << endl;

  randomizedQuickSort(arr2, 0, n - 1);

  cout << "\nRandomized Quick Sort Result:\n";
  printArray(arr2, n);
  cout << "Partitions (passes): " << randQuickPass << endl;

  return 0;
}