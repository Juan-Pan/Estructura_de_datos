#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int tcases, k, x, y, t;
    unsigned long long int n, r;
    scanf("%d", &t);

    for (tcases = 1; tcases <= t; tcases++){

        scanf( "%llu", &n);
        k = (int) sqrt(n) / 2;
        r = n - (4 *(unsigned long long) k * k);

        if (r == 0){
            x = (2 * k - 1);
            y = -k + 1;
        }
        else if (r <= 4 * k + 2){

            x =  (2 * k + 1) - r;
        
            y = -k; 
        } 
        else if (r <= 3 * ( 2 * k + 1)){

            x = r - 3 * (2 * k + 1);
            y = -k + (r - ( 4 * k + 2));

        } 
        else 
        {
            x = r - 3 * ( 2 * k + 1);
            y = k + 1 - x;
        }
        printf("%d %d\n", x, y);
    }




    return 0;
}