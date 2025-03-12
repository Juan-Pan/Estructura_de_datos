#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXN 100000

int BinarySearch (int A[], int i,  int j, int k)
{
    int r = -1, m;
    while (i <= j)
    {

        m = (i + j) / 2;
        if (A[m] == k)
        {
            r = m;
            break;
    }
    else{

        if (k > A[m])
            i = m + 1;
        else
            j = m - 1;
    }
}
    if ( r == -1)
        r = -1 * i -1;
    return r;
}
int main(){

    int TN [MAXN +1 ], index, q, idQuery, element;
    int position;
    TN[0] = 0;
    for (index = 1; index <= MAXN; index++)
        TN[index] = TN[index - 1] + index;
    for (index = 1; index <= MAXN; index++)
    printf("TN[%d] = %d\n", index, TN[index]);
    scanf("%d",  &q);

    for(  idQuery = 1; idQuery <= q; idQuery ++)
    {
        scanf("%d", &element);
        position = BinarySearch(TN, 1, MAXN, element);
        if (position >= 0)
            printf("The %d is in the array in the position %d\n", element, position);
        else
            printf("%d is not in the array. Insertion point: %d\n", element, -1 * position - 1);
    }

    return 0;
}