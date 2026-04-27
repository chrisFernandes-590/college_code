#include <iostream>
#include <vector>
using namespace std;

#define INF 1000

int getMinVertex(vector<int> &dist, vector<bool> &visited, int n){
    int minVal = INF;
    int minIdx = -1;

    for (int i = 0; i < n; i++)
    {
        if(!visited[i] && dist[i] < minVal){
            minVal = dist[i];
            minIdx = i;
        }
    }
    return minIdx;
    
}

void dijkstra(vector<vector<int>> &graph, int n, int src){
    vector<bool> visited(n, false);
    vector<int> dist(n, INF);

    dist[src] = 0;
    
    for (int i = 0; i < n - 1; i++)
    {
        int u = getMinVertex(dist, visited, n);

        if(u == -1) break;

        visited[u] = true;

        for (int v = 0; v < n; v++)
        {
            if(!visited[v] && graph[u][v] != INF && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
            }
        }
        
    }
    cout << "\nVertex   Distance from Source\n";
    for (int i = 0; i < n; i++) {
        cout << i << " \t\t " << dist[i] << endl;
    }
    
}

int main(){
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter adjacency matrix (-1 for no edge):\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;

            if (x == -1)
                graph[i][j] = INF;
            else
                graph[i][j] = x;
        }
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    dijkstra(graph, n, src);
    return 0;
}
