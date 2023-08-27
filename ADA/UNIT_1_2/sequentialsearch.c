#include <stdio.h>
int sequentialSearch(int a[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int n, i, key, a[n];
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int index = sequentialSearch(a, n, key);

    if (index != -1)
    {
        printf("Element %d found at index %d.\n", key, index);
    }
    else
    {
        printf("Element %d not found.\n", key);
    }

    return 0;
}
