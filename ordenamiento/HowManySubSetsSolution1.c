#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXN 500000

int main()
{

    int A[MAXN + 1], i, j, n, q, idQuery, sum;
    long long int result;

    scanf("%d %d", &n, &q);
    for (i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    for (idQuery = 1; idQuery <= q; idQuery++)
    {
        result = 0;
        scanf("%d", &sum);
        for (i = 1; i <= n; i++)
        {
            for (j = i + 1; j <= n; j++)
            {
                if (A[i] + A[j] <= sum)
                    result++;
               
            }
        }
        printf("%lld\n", result);
    }
    return 0;
}