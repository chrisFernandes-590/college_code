#include <iostream>
#include <string>
using namespace std;

#define MAX 100

int main()
{
  string X, Y;

  cout << "Enter first string: ";
  cin >> X;

  cout << "Enter second string: ";
  cin >> Y;

  int m = X.length();
  int n = Y.length();

  int L[MAX][MAX];

  // Initialize
  for (int i = 0; i <= m; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      if (i == 0 || j == 0)
        L[i][j] = 0;
      else if (X[i - 1] == Y[j - 1])
        L[i][j] = 1 + L[i - 1][j - 1];
      else
        L[i][j] = max(L[i - 1][j], L[i][j - 1]);
    }
  }

  cout << "Length of LCS: " << L[m][n] << endl;

  // Backtracking to find LCS string
  string lcs = "";
  int i = m, j = n;

  while (i > 0 && j > 0)
  {
    if (X[i - 1] == Y[j - 1])
    {
      lcs = X[i - 1] + lcs;
      i--;
      j--;
    }
    else if (L[i - 1][j] > L[i][j - 1])
    {
      i--;
    }
    else
    {
      j--;
    }
  }

  cout << "LCS: " << lcs << endl;

  return 0;
}