#include <iostream>
#include <vector>
using namespace std;

class RAG
{
  int n;
  vector<vector<int>> graph;
  vector<bool> visited, recStack;

public:
  RAG(int n)
  {
    this->n = n;
    graph.resize(n);
    visited.resize(n, false);
    recStack.resize(n, false);
  }

  void addEdge(int u, int v)
  {
    graph[u].push_back(v);
  }

  void displayGraph()
  {
    cout << "Resource Allocation Graph (Adjacency List):\n";
    for (int i = 0; i < n; i++)
    {
      cout << "Node " << i << " -> ";
      for (int neighbor : graph[i])
      {
        cout << neighbor << " ";
      }
      cout << endl;
    }
  }

  bool detectCycleUtil(int v)
  {
    visited[v] = true;
    recStack[v] = true;

    for (int neighbor : graph[v])
    {
      if (!visited[neighbor] && detectCycleUtil(neighbor))
        return true;
      else if (recStack[neighbor])
        return true;
    }

    recStack[v] = false;
    return false;
  }

  bool detectDeadlock()
  {
    for (int i = 0; i < n; i++)
    {
      if (!visited[i])
      {
        if (detectCycleUtil(i))
          return true;
      }
    }
    return false;
  }
};

int main()
{
  int processes = 4;
  RAG rag(processes);

  rag.addEdge(0, 1);
  rag.addEdge(1, 2);
  rag.addEdge(2, 0);

  // Display the graph
  rag.displayGraph();

  // Check for deadlock
  if (rag.detectDeadlock())
    cout << "Deadlock detected in the system." << endl;
  else
    cout << "No deadlock detected." << endl;

  return 0;
}