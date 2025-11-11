#include <stdio.h>
#define MAX 10

int adj[MAX][MAX];
int visited[MAX];
int n; // number of vertices

// Function to create adjacency matrix
void createGraph()
{
    int edges, i, origin, dest;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize matrix
    for (i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter edges (origin destination):\n");
    for (i = 0; i < edges; i++)
    {
        scanf("%d %d", &origin, &dest);
        if (origin >= n || dest >= n || origin < 0 || dest < 0)
            printf("Invalid edge!\n");
        else
            adj[origin][dest] = 1; // for undirected graph: also add adj[dest][origin] = 1;
    }
}

// DFS Function
void DFS(int v)
{
    int i;
    visited[v] = 1;
    printf("%d ", v);
    for (i = 0; i < n; i++)
    {
        if (adj[v][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}

// BFS Function
void BFS(int start)
{
    int queue[MAX], front = 0, rear = -1;
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("%d ", start);
    visited[start] = 1;
    queue[++rear] = start;

    while (front <= rear)
    {
        int v = queue[front++];
        for (int i = 0; i < n; i++)
        {
            if (adj[v][i] == 1 && visited[i] == 0)
            {
                printf("%d ", i);
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int start;

    createGraph();

    printf("\nEnter starting vertex for DFS: ");
    scanf("%d", &start);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nDFS Traversal: ");
    DFS(start);

    printf("\n\nEnter starting vertex for BFS: ");
    scanf("%d", &start);

    printf("\nBFS Traversal: ");
    BFS(start);

    printf("\n");
    return 0;
}
