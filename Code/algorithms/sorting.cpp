#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

void bubbleSort(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

void modifiedBubbleSort(int arr[], int n)
{
  int swapped = 0;
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(arr[j], arr[j + 1]);
        swapped = 1;
      }
    }
    if (!swapped)
      return;
  }
}

void selectionSort(int arr[], int n) {}

void insertionsSort(int arr[], int n)
{
  for (int i = 1; i < n - 1; i++)
  {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

bool isSorted(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    if (arr[i] > arr[i + 1])
      return false;
  }
  return true;
}

void printArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}



void runTest(int arr[], int n, string testName, string algorithmName, void (*sortFunction)(int[], int))
{
  cout << "Algorithm: " << algorithmName << endl;
  cout << "Test: " << testName << endl;

  auto start = high_resolution_clock::now();

  sortFunction(arr, n);

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<nanoseconds>(stop - start);

  if (isSorted(arr, n))
    cout << "Result: PASS" << endl;
  else
    cout << "Result: FAIL" << endl;

  cout << "Time: " << duration.count() << " ns" << endl;

  cout << "Output: ";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";

  cout << "\n------------------------\n";
}

int main()
{
  int test1[] = {5, 2, 9, 1, 3};
  int test2[] = {1, 2, 3, 4, 5};
  int test3[] = {5, 4, 3, 2, 1};
  int test4[] = {7, 7, 7, 7};
  int test5[] = {-3, 5, -1, 0, 2};

  int *tests[] = {test1, test2, test3, test4, test5};
  int sizes[] = {5, 5, 5, 4, 5};
  string names[] = {
      "Random",
      "Already Sorted",
      "Reverse Sorted",
      "Duplicates",
      "Negative Numbers"};

  int numTests = 5;

  for (int i = 0; i < numTests; i++)
  {
    int n = sizes[i];

    int arr[n]; // copy array

    for (int j = 0; j < n; j++)
      arr[j] = tests[i][j];

    // runTest(arr, n, names[i], "Bubble Sort", bubbleSort);
    runTest(arr, n, names[i], "Modified Bubble Sort", modifiedBubbleSort);
  }

  return 0;
}