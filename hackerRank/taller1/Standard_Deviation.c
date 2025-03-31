#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    unsigned long long sumaCuadrados;
    double s;

    while (scanf("%d", &n) && n != 0)
    {
        sumaCuadrados = (double)n * (n * (double)n - 1) / 3;
        s = sqrt((double)sumaCuadrados / (n - 1));
        printf("%.6f\n", s);
    }

    return 0;
}
