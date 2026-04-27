#include <iostream>
#include <vector>
#define INF 100
using namespace std;

void printMatrix(vector<vector<int>> &dist, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(dist[i][j] == INF){
                cout << "INF";
            }else{
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}

void floydWarshall(vector<vector<int>> &dist, int n){
    // k immediate vertex
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // if through k is shorter
                if(dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
            
        }
        
    }
    
}

int main(){
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n));

    cout << "Enter the adjeceny matrix(use " << INF << " for no edge):\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> dist[i][j];
        }
        
    }

    floydWarshall(dist, n);
    cout << "\nShortest distance matrix: \n";
    printMatrix(dist, n);
    
    return 0;
}