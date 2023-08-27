#include <stdio.h>
void dfs(int a[][20], int visit[], int n, int v)
{
	int i;
	visit[v] = 1;
	printf("%d\t", v);
	for (i = 0; i < n; i++)
	{
		if (a[v][i] && !visit[i])
			dfs(a, visit, n, i);
	}
}
void printdfs(int a[][20], int n, int s)
{
	int visit[20], i;
	for (i = 0; i < n; i++)
		visit[i] = 0;
	printf("DFS traversal is\t:");
	dfs(a, visit, n, s);
}
int main()
{
	int i, j, s, a[20][20], visit[20], n;
	printf("Enter the number of vertices\t: ");
	scanf("%d", &n);
	printf("Enter the adjacency matrix:\n ");
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	printf("Enter the source vertex: ");
	scanf("%d", &s);
	printdfs(a, n, s);
	return 0;
}