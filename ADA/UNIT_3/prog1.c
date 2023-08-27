#include <stdio.h>
void dfs(int a[][20], int visit[], int n, int v)
{
    int i;
    visit[v] = 1;
    printf("%d\t", v);
    for (i = 0; i < n; i++)
    {
        if (a[v][i] && !visit[i])
        {
            dfs(a, visit, n, i);
        }
    }
}
void PrintDFS(int a[][20], int n, int s)
{
    int visit[20], i;
    for (int i = 0; i < n; i++)
    {
        visit[i] = 0;
    }
    printf("\nDFS Traversal is\t:");
    dfs(a, visit, n, s);
}
int main()
{
    int i, j, s, a[20][20], visit[20], n;
    printf("Enter the number of vertices : ");
    scanf("%d", &n);
    printf("Ente the adjacency matrix : ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the Source Vertex : ");
    scanf("%d", &s);
    PrintDFS(a, n, s);
    return 0;
}

// Ajacency vetrices
// 0 1 0 0 0 1 0 1 0 1
// 0 0 0 0 0 1 0 1 0 1
// 0 1 1 1 1 0 0 1 0 1
// 0 1 0 0 0 1 0 1 0 1
// 0 0 0 0 0 1 0 1 0 1
// 0 1 1 1 1 0 0 1 0 1
// 0 0 0 0 0 1 0 1 0 1
// 0 1 1 1 1 0 0 1 0 1
// 1 0 0 0 1 0 1 0 1 0
// 1 0 0 0 1 0 1 0 1 1

// 0 1 0 1 0 0 0 0 
// 1 0 0 1 0 1 0 0
// 0 0 0 0 1 0 1 0
// 1 1 0 0 0 1 0 1
// 0 0 1 0 0 0 1 1
// 0 1 0 1 0 0 1 0
// 0 0 1 0 1 1 0 1
// 0 0 0 1 1 0 1 0 

