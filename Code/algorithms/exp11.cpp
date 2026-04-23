#include <iostream>
using namespace std;

#define MAX 100
#define INF 99999

int main()
{
  int n;

  cout << "Enter number of vertices: ";
  cin >> n;

  int cost[MAX][MAX], D[MAX][MAX];

  cout << "Enter cost matrix:\n";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> cost[i][j];

      // If no edge, use INF (except diagonal)
      if (i != j && cost[i][j] == 0)
        D[i][j] = INF;
      else
        D[i][j] = cost[i][j];
    }
  }

  // Floyd Warshall Algorithm
  for (int k = 0; k < n; k++)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (D[i][k] + D[k][j] < D[i][j])
        {
          D[i][j] = D[i][k] + D[k][j];
        }
      }
    }
  }

  // Output
  cout << "Shortest distance matrix:\n";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (D[i][j] == INF)
        cout << "INF ";
      else
        cout << D[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}