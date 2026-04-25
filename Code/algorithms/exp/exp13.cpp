#include <iostream>
#include <cmath>
using namespace std;

#define MAX 100

int col[MAX]; // col[i] = column of queen in row i
int n;

// Check if safe to place queen
bool place(int q, int c)
{
  for (int i = 1; i < q; i++)
  {
    if (col[i] == c || abs(i - q) == abs(col[i] - c))
      return false;
  }
  return true;
}

// N-Queen function
void nqueen(int q)
{
  for (int c = 1; c <= n; c++)
  {
    if (place(q, c))
    {
      col[q] = c;

      if (q == n)
      {
        // Print solution
        cout << "Solution: ";
        for (int i = 1; i <= n; i++)
          cout << col[i] << " ";
        cout << endl;
      }
      else
      {
        nqueen(q + 1);
      }
    }
  }
}

int main()
{
  cout << "Enter number of queens: ";
  cin >> n;

  nqueen(1);

  return 0;
}