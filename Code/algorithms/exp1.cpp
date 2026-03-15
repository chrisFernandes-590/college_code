#include <iostream>
using namespace std;

// Roll - 10657, Name - Chris Fernandes

int bubbleSort(int a[], int n)
{
  int passes = 0;

  for (int pass = 0; pass < n - 1; pass++)
  {
    passes++;

    for (int i = 0; i < n - pass - 1; i++)
    {
      if (a[i] > a[i + 1])
        swap(a[i], a[i + 1]);
    }
  }

  return passes;
}

int modifiedBubbleSort(int a[], int n)
{
  bool exchanged = true;
  int passes = 0;

  for (int pass = 0; pass < n - 1 && exchanged; pass++)
  {
    exchanged = false;
    passes++;

    for (int i = 0; i < n - pass - 1; i++)
    {
      if (a[i] > a[i + 1])
      {
        swap(a[i], a[i + 1]);
        exchanged = true;
      }
    }
  }

  return passes;
}

int selectionSort(int a[], int n)
{
  int passes = 0;

  for (int i = 0; i < n - 1; i++)
  {
    passes++;
    int min = i;

    for (int j = i + 1; j < n; j++)
    {
      if (a[j] < a[min])
        min = j;
    }

    swap(a[i], a[min]);
  }

  return passes;
}

int insertionSort(int a[], int n)
{
  int passes = 0;

  for (int i = 1; i < n; i++)
  {
    passes++;

    int key = a[i];
    int j = i - 1;

    while (j >= 0 && a[j] > key)
    {
      a[j + 1] = a[j];
      j--;
    }

    a[j + 1] = key;
  }

  return passes;
}

void printArray(int a[], int n)
{
  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  cout << endl;
}

int main()
{
  int n, choice;

  cout << "Enter number of elements: ";
  cin >> n;

  int arr[n];

  cout << "\nChoose Case:\n";
  cout << "1. Best Case (Sorted)\n";
  cout << "2. Worst Case (Reverse)\n";
  cout << "3. Average Case (User Input)\n";
  cin >> choice;

  if (choice == 1)
  {
    for (int i = 0; i < n; i++)
      arr[i] = i + 1;
  }
  else if (choice == 2)
  {
    for (int i = 0; i < n; i++)
      arr[i] = n - i;
  }
  else
  {
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
      cin >> arr[i];
  }

  cout << "\nUnsorted Array:\n";
  printArray(arr, n);

  int a1[n], a2[n], a3[n], a4[n];

  for (int i = 0; i < n; i++)
  {
    a1[i] = arr[i];
    a2[i] = arr[i];
    a3[i] = arr[i];
    a4[i] = arr[i];
  }

  int p1 = bubbleSort(a1, n);
  int p2 = modifiedBubbleSort(a2, n);
  int p3 = selectionSort(a3, n);
  int p4 = insertionSort(a4, n);

  cout << "\nBubble Sort Result:\n";
  printArray(a1, n);
  cout << "Passes Required: " << p1 << endl;

  cout << "\nModified Bubble Sort Result:\n";
  printArray(a2, n);
  cout << "Passes Required: " << p2 << endl;

  cout << "\nSelection Sort Result:\n";
  printArray(a3, n);
  cout << "Passes Required: " << p3 << endl;

  cout << "\nInsertion Sort Result:\n";
  printArray(a4, n);
  cout << "Passes Required: " << p4 << endl;

  return 0;
}