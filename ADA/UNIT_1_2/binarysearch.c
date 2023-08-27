#include <stdio.h>

int binarySearch(int A[], int n, int k) {
    int l = 0;
    int r = n - 1;
    int m;
    while (l <= r) {
        m = (l+r)/ 2;
        if (A[m] == k) {
            return m;  
        } else if (A[m] < k) {
            l = m + 1;  
        } else {
            r = m - 1; 
        }
    }

    return -1;  
}

int main() {
    int n,k,i;

    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int A[n];

    printf("Enter the elements of the array in sorted order: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("Enter the key to search: ");
    scanf("%d", &k);


    int index = binarySearch(A, n, k);

    if (index != -1) {
        printf("Key found at index %d\n", index);
    } else {
        printf("Key not found\n");
    }

    return 0;
}
