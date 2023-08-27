#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int l, int r) {
    int P = A[r];  
    int i = (l - 1);      

    for (int j = l; j <= r - 1; j++) {
        if (A[j] <= P) {
            i++;  
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[r]);
    return (i + 1);
}

void quickSort(int A[], int l, int r) {
    if (l < r) {
        int S = partition(A, l, r);

        quickSort(A, l, S - 1);
        quickSort(A, S + 1, r);
    }
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, size - 1);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
