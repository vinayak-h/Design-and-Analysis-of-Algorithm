#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define INF 999999

int graph[MAX_VERTICES][MAX_VERTICES];
int dist[MAX_VERTICES];
bool visited[MAX_VERTICES];

int V;

int minDistance()
{
    int min = INF, min_index;
    for (int v = 0; v < V; v++)
    {
        if (!visited[v] && dist[v] < min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printDistances()
{
    printf("Vertex \tDistance from Source\n");
    for (int v = 0; v < V; v++)
    {
        printf("%d \t%d\n", v, dist[v]);
    }
}

void dijkstra(int source)
{
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[source] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance();
        visited[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printDistances();
}

int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);
    dijkstra(source);
    return 0;
}