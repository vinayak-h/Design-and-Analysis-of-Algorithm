// #include <stdio.h>
// #include <stdlib.h>
// // Node in the adjacency list
// struct Node
// {
// 	int dest;
// 	struct Node *next;
// };
// // Adjacency list
// struct adjlist
// {
// 	struct Node *start;
// };
// void bfs(struct adjlist *arr, int visit[], int v)
// {
// 	visit[v] = 1;
// 	printf("%d\t", v);
// 	struct Node *temp = arr[v].start;
// 	while (temp != NULL)
// 	{
// 		int conNode = temp->dest;
// 		if (!visit[conNode])
// 			bfs(arr, visit, conNode);
// 		temp = temp->next;
// 	}
// }
// void addEdge(struct adjlist *arr, int src, int dest)
// {
// 	struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
// 	newnode->dest = dest;
// 	newnode->next = NULL;
// 	if (arr[src].start == NULL)
// 		arr[src].start = newnode;
// 	else
// 	{
// 		struct Node *ptr = arr[src].start;
// 		while (ptr->next != NULL)
// 			ptr = ptr->next;
// 		ptr->next = newnode;
// 	}
// }
// void printbfs(struct adjlist *arr, int n, int s)
// {
// 	int *visit = (int *)malloc(n * sizeof(int));
// 	int i;
// 	for (i = 0; i < n; i++)
// 		visit[i] = 0;
// 	printf("BFS traversal is \t:");
// 	bfs(arr, visit, s);
// 	free(visit);
// }
// int main()
// {
// 	int i, j, s, n, nNeigh, neigh;
// 	printf("Enter the number of vertices: ");
// 	scanf("%d", &n);
// 	struct adjlist *arr = (struct adjlist *)malloc(n * sizeof(struct adjlist));
// 	for (i = 0; i < n; i++)
// 		arr[i].start = NULL;
// 	printf("Enter the adjacency list\n");
// 	for (i = 0; i < n; i++)
// 	{
// 		printf("Enter the number of adjacent vertices for vertex %d\t:", i);
// 		scanf("%d", &nNeigh);
// 		for (j = 0; j < nNeigh; j++)
// 		{
// 			printf("Enter the adjacent vertex %d of vertex %d\t:", j, i);
// 			scanf("%d", &neigh);
// 			addEdge(arr, i, neigh);
// 		}
// 	}
// 	printf("Enter the the source for traversal\t:");
// 	scanf("%d", &s);
// 	printbfs(arr, n, s);
// 	free(arr);
// 	return 0;
// }

////_______________________________________DFS________________
// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>

// void dfs(int a[][8], int visit[], int n, int v)
// {
// 	visit[v] = 1;
// 	printf("%d\t", v);

// 	for (int i = 0; i < n; i++)
// 	{
// 		if (a[v][i] && !visit[i])
// 		{
// 			dfs(a, visit, n, i);
// 		}
// 	}
// }

// void printdfs(int a[][8], int n, int s)
// {
// 	int visit[8] = {0};
// 	printf("DFS traversal is: ");
// 	dfs(a, visit, n, s);
// }

// int main()
// {
// 	int graph[8][8] = {
// 		{0, 1, 0, 1, 0, 0, 0, 0},
// 		{1, 0, 0, 1, 0, 1, 0, 0},
// 		{0, 0, 0, 0, 1, 0, 1, 0},
// 		{1, 1, 0, 0, 0, 1, 0, 1},
// 		{0, 0, 1, 0, 0, 0, 1, 1},
// 		{0, 1, 0, 1, 0, 0, 1, 0},
// 		{0, 0, 1, 0, 1, 1, 0, 1},
// 		{0, 0, 0, 1, 1, 0, 1, 0}};

// 	int n = 8;
// 	int s;
// 	printf("Enter the source vertex: ");
// 	scanf("%d", &s);

// 	printdfs(graph, n, s);
// 	return 0;
// }

// //______DFS TOPOLOGICAL__________________
// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>

// void dfs(int a[][8], int visit[], int n, int v, int *stack, int *top)
// {
// 	visit[v] = 1;
// 	for (int i = 0; i < n; i++)
// 	{
// 		if (a[v][i] && !visit[i])
// 		{
// 			dfs(a, visit, n, i, stack, top);
// 		}
// 	}
// 	stack[++(*top)] = v;
// }

// void topologicalSort(int a[][8], int n)
// {
// 	int visit[8] = {0};
// 	int stack[8];
// 	int top = -1;

// 	for (int i = 0; i < n; i++)
// 	{
// 		if (!visit[i])
// 		{
// 			dfs(a, visit, n, i, stack, &top);
// 		}
// 	}

// 	printf("Topological sort order: ");
// 	while (top >= 0)
// 	{
// 		printf("%d ", stack[top--]);
// 	}
// 	printf("\n");
// }

// int main()
// {
// 	int graph[8][8] = {
// 		{0, 1, 0, 1, 0, 0, 0, 0},
// 		{1, 0, 0, 1, 0, 1, 0, 0},
// 		{0, 0, 0, 0, 1, 0, 1, 0},
// 		{1, 1, 0, 0, 0, 1, 0, 1},
// 		{0, 0, 1, 0, 0, 0, 1, 1},
// 		{0, 1, 0, 1, 0, 0, 1, 0},
// 		{0, 0, 1, 0, 1, 1, 0, 1},
// 		{0, 0, 0, 1, 1, 0, 1, 0}};

// 	int n = 8;

// 	topologicalSort(graph, n);

// 	return 0;
// }

#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

void topologicalSort(int graph[MAX_NODES][MAX_NODES], int numNodes)
{
	int inDegree[MAX_NODES] = {0};
	int queue[MAX_NODES];
	int front = 0, rear = -1;
	int sortedOrder[MAX_NODES];
	int sortedIndex = 0;

	for (int i = 0; i < numNodes; i++)
	{
		for (int j = 0; j < numNodes; j++)
		{
			if (graph[i][j] == 1)
				inDegree[j]++;
		}
	}

	for (int i = 0; i < numNodes; i++)
	{
		if (inDegree[i] == 0)
			queue[++rear] = i;
	}

	while (front <= rear)
	{
		int currentNode = queue[front++];
		sortedOrder[sortedIndex++] = currentNode;

		for (int i = 0; i < numNodes; i++)
		{
			if (graph[currentNode][i] == 1)
			{
				if (--inDegree[i] == 0)
					queue[++rear] = i;
			}
		}
	}

	if (sortedIndex != numNodes)
	{
		printf("Error: The graph contains cycles and doesn't have a valid topological order.\n");
		return;
	}

	printf("Topological Sorted Order: ");
	for (int i = 0; i < sortedIndex; i++)
	{
		printf("%d ", sortedOrder[i]);
	}
	printf("\n");
}

int main()
{

	int graph[8][8] = {
		{0, 1, 0, 1, 0, 0, 0, 0},
		{1, 0, 0, 1, 0, 1, 0, 0},
		{0, 0, 0, 0, 1, 0, 1, 0},
		{1, 1, 0, 0, 0, 1, 0, 1},
		{0, 0, 1, 0, 0, 0, 1, 1},
		{0, 1, 0, 1, 0, 0, 1, 0},
		{0, 0, 1, 0, 1, 1, 0, 1},
		{0, 0, 0, 1, 1, 0, 1, 0}};
	int numNodes = 8;

	topologicalSort(graph, numNodes);

	return 0;
}