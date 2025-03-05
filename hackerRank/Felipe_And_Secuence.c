#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int totalcases, idcase;
    unsigned long long int s, n;
    scanf("%d", &totalcases);
    for (idcase = 1; idcase <= totalcases; idcase++)
    {
        scanf("%llu", &s);
        n = (s + 1) * (s + 1) - 1;
        printf("%llu\n", n);
    }
    return 0;
}