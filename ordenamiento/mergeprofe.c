#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXN 100
#define infinity 2147483647
void myMerge (int A[], int p, int q, int r) {
    int n1 = q - p + 1, n2 = r - q, i, j, k;
    int L[n1+2], R[n2+2];
    
    for (i = 1; i <= n1; i++) L[i] = A[p+i-1];

    for (j = 1; j <= n2; j++) R[j] = A[q+j];

    L[n1+1] = infinity;
    R[n2+1] = infinity;
    i = 1;
    j = 1;

    for(k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}