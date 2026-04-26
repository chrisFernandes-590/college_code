#include <iostream>
#include <vector>

using namespace std;

class Graph
{
  int V; // no. of vertices
  vector<vector<int>> adj;

public:
  Graph(int V)
  {
    this->V = V;
    adj.resize(V);
  }

  // add edge
  void addEdge(int u, int v)
  {
    adj[u].push_back(v);
  }

  // dfs for cycle
  bool isCyclicUtil(int node, vector<bool> &visited, vector<bool> &recStack)
  {
    visited[node] = true;
    recStack[node] = true;

    for (int neighbor : adj[node])
    {
      if (!visited[neighbor])
      {
        if (isCyclicUtil(neighbor, visited, recStack))
          return true;
      }
      else if (recStack[neighbor])
      {
        return true; // cycle found
      }
    }
    recStack[node] = false;
    return false;
  }

  bool isDeadlock()
  {
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);

    for (int i = 0; i < V; i++)
    {
      if (!visited[i])
      {
        if (isCyclicUtil(i, visited, recStack))
        {
          return true;
        }
      }
    }
    return false;
  }
};

int main()
{
  int V, E;
  cout << "Enter the number of nodes(processes + resources): ";
  cin >> V;

  Graph g(V);
  cout << "Enter number of edges: ";
  cin >> E;

  cout << "Enter edges (u v):\n";
  cout << "(Use numbers for nodes)\n";

  for (int i = 0; i < E; i++)
  {
    int u, v;
    cin >> u >> v;
    g.addEdge(u, v);
  }

  if (g.isDeadlock())
    cout << "Deadlock detected\n";
  else
    cout << "No deadlock";
  return 0;
}
