#include <stdio.h>
#include <stdlib.h>
// Node in the adjacency list
struct Node
{
	int dest;
	struct Node *next;
};
// Adjacency list
struct adjlist
{
	struct Node *start;
};
void appdfs(struct adjlist *arr, int visit[], int v)
{
	visit[v] = 1;
	printf("%d\t", v);
	struct Node *temp = arr[v].start;
	while (temp != NULL)
	{
		int conNode = temp->dest;
		if (!visit[conNode])
			appdfs(arr, visit, conNode);
		temp = temp->next;
	}
}
void addEdge(struct adjlist *arr, int src, int dest)
{
	struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
	newnode->dest = dest;
	newnode->next = NULL;
	if (arr[src].start == NULL)
		arr[src].start = newnode;
	else
	{
		struct Node *ptr = arr[src].start;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = newnode;
	}
}


// void addEdge(struct adjlist *arr, int src, int dest)
// {
//     struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
//     newnode->dest = dest;c
//     newnode->next = arr[src].start; // Insert at the beginning
//     arr[src].start = newnode;
// }



void printdfs(struct adjlist *arr, int n, int s)
{
	int *visit = (int *)malloc(n * sizeof(int));
	int i;
	for (i = 0; i < n; i++)
		visit[i] = 0;
	printf("Application of DFS traversal is \t:");
	appdfs(arr, visit, s);
	free(visit);
}
int main()
{
	int i, j, s, n, nNeigh, neigh;
	printf("Enter the number of vertices in the graph: ");
	scanf("%d", &n);

	struct adjlist *arr = (struct adjlist *)malloc(n * sizeof(struct adjlist));
	for (i = 0; i < n; i++)
		arr[i].start = NULL;

	printf("Enter the adjacency list\n");
	for (i = 0; i < n; i++)
	{
		printf("Enter the number of adjacent vertices for vertex %d: ", i);
		scanf("%d", &nNeigh);
		for (j = 0; j < nNeigh; j++)
		{
			printf("Enter the adjacent vertex %d of vertex %d: ", j, i);
			scanf("%d", &neigh);
			addEdge(arr, i, neigh);
		}
	}

	printf("Enter the source for traversal: ");
	scanf("%d", &s);
	printdfs(arr, n, s);
	free(arr);
	return 0;
}
