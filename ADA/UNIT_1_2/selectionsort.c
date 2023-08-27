#include <stdio.h>
void selectionSort(int a[], int n)
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }

        temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }
}

int main()
{
    int a[100];
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Original array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    selectionSort(a, n);

    printf("\nSorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}