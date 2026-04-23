#include <iostream>
using namespace std;

#define MAX 100
#define INF 99999

int main()
{
  int n;

  cout << "Enter number of vertices: ";
  cin >> n;

  int graph[MAX][MAX];

  cout << "Enter adjacency matrix:\n";
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> graph[i][j];
    }
  }

  int source;
  cout << "Enter source vertex: ";
  cin >> source;

  int dist[MAX];
  bool visited[MAX];

  // Initialize
  for (int i = 0; i < n; i++)
  {
    dist[i] = INF;
    visited[i] = false;
  }

  dist[source] = 0;

  // Dijkstra Algorithm
  for (int count = 0; count < n - 1; count++)
  {
    int u = -1, minDist = INF;

    // Find minimum distance vertex
    for (int i = 0; i < n; i++)
    {
      if (!visited[i] && dist[i] < minDist)
      {
        minDist = dist[i];
        u = i;
      }
    }

    visited[u] = true;

    // Relax neighbours
    for (int v = 0; v < n; v++)
    {
      if (!visited[v] && graph[u][v] != 0 &&
          dist[u] + graph[u][v] < dist[v])
      {
        dist[v] = dist[u] + graph[u][v];
      }
    }
  }

  // Output
  cout << "Shortest distances from source:\n";
  for (int i = 0; i < n; i++)
  {
    cout << "To " << i << " = " << dist[i] << endl;
  }

  return 0;
}