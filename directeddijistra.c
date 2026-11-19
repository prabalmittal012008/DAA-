#include <stdio.h>
#define V 5
#define INF 9999
int minDistance(int dist[], int visited[])
{
    int min = INF, index = -1;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && dist[i] < min)
        {
            min = dist[i];
            index = i;
        }
    }
    return index;
}
// Function to print path
void printPath(int parent[], int j)
{
    if (parent[j] == -1)
    {
        printf("%c", 'A' + j);
        return;
    }
    printPath(parent, parent[j]);
    printf(" -> %c", 'A' + j);
}
void dijkstra(int graph[V][V], int source)
{
    int dist[V];
    int visited[V] = {0};
    int parent[V];
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[source] = 0;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, visited);
        if (u == -1)
            break;
        visited[u] = 1;
        for (int v = 0; v < V; v++)
        {
            if (!visited[v] &&
                graph[u][v] != 0 &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                // Store previous vertex
                parent[v] = u;
            }
        }
    }
    printf("Vertex\tDistance\tPath\n");
    for (int i = 0; i < V; i++)
    {
        printf("%c\t%d\t\t", 'A' + i, dist[i]);
        printPath(parent, i);
        printf("\n");
    }
}
int main()
{
    // A=0, B=1, C=2, D=3, E=4
    int graph[V][V] =
    {
        // A   B   C   D   E
        { 0, 10,  5,  0,  0 },  // A
        { 0,  0,  0,  1,  0 },  // B
        { 0,  3,  0,  9,  2 },  // C
        { 0,  0,  0,  0,  0 },  // D
        { 2,  0,  0,  6,  0 }   // E
    };

    dijkstra(graph, 0);   // A is source

    return 0;
}