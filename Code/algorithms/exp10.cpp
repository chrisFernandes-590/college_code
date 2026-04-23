#include <iostream>
using namespace std;

#define MAX 100
#define INF 99999

struct Edge
{
  int u, v, w;
};

int main()
{
  int V, E;

  cout << "Enter number of vertices and edges: ";
  cin >> V >> E;

  Edge edges[MAX];

  cout << "Enter edges (u v weight):\n";
  for (int i = 0; i < E; i++)
  {
    cin >> edges[i].u >> edges[i].v >> edges[i].w;
  }

  int source;
  cout << "Enter source vertex: ";
  cin >> source;

  int dist[MAX];

  // Initialize distances
  for (int i = 0; i < V; i++)
    dist[i] = INF;

  dist[source] = 0;

  // Relax edges V-1 times
  for (int i = 1; i <= V - 1; i++)
  {
    for (int j = 0; j < E; j++)
    {
      int u = edges[j].u;
      int v = edges[j].v;
      int w = edges[j].w;

      if (dist[u] != INF && dist[u] + w < dist[v])
      {
        dist[v] = dist[u] + w;
      }
    }
  }

  // Check for negative cycle
  bool negativeCycle = false;
  for (int j = 0; j < E; j++)
  {
    int u = edges[j].u;
    int v = edges[j].v;
    int w = edges[j].w;

    if (dist[u] != INF && dist[u] + w < dist[v])
    {
      negativeCycle = true;
      break;
    }
  }

  if (negativeCycle)
  {
    cout << "Graph contains negative weight cycle\n";
  }
  else
  {
    cout << "Shortest distances from source:\n";
    for (int i = 0; i < V; i++)
    {
      cout << "To " << i << " = " << dist[i] << endl;
    }
  }

  return 0;
}