#include <stdio.h>
#define V 9
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
// Function to print the path
void printPath(int parent[], int j)
{
    if (parent[j] == -1)
    {
        printf("%d", j);
        return;
    }
    printPath(parent, parent[j]);
    printf(" -> %d", j);
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
                // Remember from where we reached v
                parent[v] = u;
            }
        }
    }
    printf("Vertex\tDistance\tPath\n");
    for (int i = 0; i < V; i++)
    {
        printf("%d\t%d\t\t", i, dist[i]);
        printPath(parent, i);
        printf("\n");
    }
}
int main()
{
    int graph[V][V] =
    {
        {0,4,0,0,8,0,0,0,0},
        {4,0,8,0,11,0,0,0,0},
        {0,8,0,7,0,0,4,0,2},
        {0,0,7,0,0,0,14,9,0},
        {8,11,0,0,0,1,0,0,7},
        {0,0,0,0,1,0,2,0,6},
        {0,0,4,14,0,2,0,10,0},
        {0,0,0,9,0,0,10,0,0},
        {0,0,2,0,7,6,0,0,0}
    };

    dijkstra(graph, 0);

    return 0;
}