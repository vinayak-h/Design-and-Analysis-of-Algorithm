#include <stdio.h>
void merge(int A[], int B[], int p, int C[], int q) {
    int i = 0, j = 0, k = 0;
    while (i < p && j < q) {
        if (B[i] <= C[j]) {
            A[k] = B[i];
            i++;
        } else {
            A[k] = C[j];
            j++;
        }
        k++;
    }
    while (i < p) {
        A[k] = B[i];
        i++;
        k++;
    }
    while (j < q) {
        A[k] = C[j];
        j++;
        k++;
    }
}
void mergeSort(int A[], int size) {
    if (size < 2) {
        return; 
    }
    int mid = size / 2;
    int B[mid];
    int C[size - mid];
    for (int i = 0; i < mid; i++) {
        B[i] = A[i];
    }
    for (int i = mid; i < size; i++) {
        C[i - mid] = A[i];
    }

    mergeSort(B, mid);
    mergeSort(A, size - mid);

    merge(A, B, mid, C, size - mid);
}

int main() {
    int size,i,A[size];

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array: ");
    for (i = 0; i < size; i++) {
        scanf("%d", &A[i]);
    }

    mergeSort(A, size);

    printf("Sorted array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
