#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    unsigned long long int n, x, xPlus1 ;
    printf("Escribe un numero: ");
while ( scanf (" %llu ", &n) && (n != 0) )
{
x = ( - 1 + sqrt (1 + 8 * ( double )n)) / 2;
xPlus1 = x + 1;
if(x % 2 == 0)
x /= 2;
if( xPlus1 % 2 == 0)
xPlus1 /= 2;
if(x * xPlus1 == n)
printf (" YES \n");
else
printf ("NO\n") ;
}
    
    return 0;
}