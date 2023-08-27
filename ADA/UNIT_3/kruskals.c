#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 100
#define MAX_VERTICES 100

struct Edge
{
    int src, dest, weight;
};

struct Graph
{
    int V, E;
    struct Edge edges[MAX_EDGES];
};

struct Subset
{
    int parent;
    int rank;
};

struct Graph graph;
struct Subset subsets[MAX_VERTICES];

void initGraph(int V, int E)
{
    graph.V = V;
    graph.E = E;
}

void initSubsets()
{
    for (int v = 0; v < graph.V; v++)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
}

int findParent(int v)
{
    if (subsets[v].parent != v)
    {
        subsets[v].parent = findParent(subsets[v].parent);
    }
    return subsets[v].parent;
}

void unionSets(int x, int y)
{
    int root_x = findParent(x);
    int root_y = findParent(y);

    if (subsets[root_x].rank < subsets[root_y].rank)
    {
        subsets[root_x].parent = root_y;
    }
    else if (subsets[root_x].rank > subsets[root_y].rank)
    {
        subsets[root_y].parent = root_x;
    }
    else
    {
        subsets[root_y].parent = root_x;
        subsets[root_x].rank++;
    }
}

int compareEdges(const void *a, const void *b)
{
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}

void kruskalMST()
{
    qsort(graph.edges, graph.E, sizeof(struct Edge), compareEdges);
    initSubsets();
    struct Edge result[MAX_EDGES];
    int mstEdges = 0;
    for (int i = 0; i < graph.E; i++)
    {
        struct Edge currentEdge = graph.edges[i];
        int srcParent = findParent(currentEdge.src);
        int destParent = findParent(currentEdge.dest);

        if (srcParent != destParent)
        {
            result[mstEdges++] = currentEdge;
            unionSets(srcParent, destParent);
        }
    }
    printf("Edge \tWeight\n");
    for (int i = 0; i < mstEdges; i++)
    {
        printf("%d - %d \t%d\n", result[i].src, result[i].dest, result[i].weight);
    }
}

int main()
{
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);
    initGraph(V, E);
    printf("Enter edges (source destination weight):\n");
    for (int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &graph.edges[i].src, &graph.edges[i].dest, &graph.edges[i].weight);
    }
    kruskalMST();
    return 0;
}