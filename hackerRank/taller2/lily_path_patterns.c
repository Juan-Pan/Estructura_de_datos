#include <stdio.h>
#define MAXN 1200000

int BusquedaBinaria(int A[], int i, int j, int k) {
    int m, resultado = -1;

    while (i <= j) {
        m = (i + j) >> 1; 

        if (A[m] == k) {
            resultado = m;
            break;
        } else if (k > A[m]) {
            i = m + 1;
        } else {
            j = m - 1;
        }
    }

    if (resultado == -1)
        resultado = (-1) * i - 1;
    
    return resultado;
}

int main(){
    int n, nenufares_ocupados[MAXN + 1], nenufares_libres[MAXN + 1]; 
    int nenufar_libre, contador = 0, q, salto;
    
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d ", &nenufares_ocupados[i]);
    
    scanf("%d", &q);
    
    for (int i = 1; i <= MAXN + 1; i++)
    {
        nenufar_libre = BusquedaBinaria(nenufares_ocupados, 1, n + 1, i);

        if (nenufar_libre < 0)
        {
            nenufares_libres[contador + 1] = i;
            contador++;
        }
    }

    for (int i = 1; i <= q; i++)
    {
        scanf("%d", &salto);

        int nenufar_ocupado = nenufares_ocupados[salto];

        int nenufar_cercano = BusquedaBinaria(nenufares_libres, 1, contador, nenufar_ocupado);
        nenufar_cercano = -1 * nenufar_cercano - 1;

        int nenufar_vacio = nenufares_libres[nenufar_cercano];

        nenufares_ocupados[salto] = nenufar_vacio;
        nenufares_libres[nenufar_cercano] = nenufar_ocupado;

        printf("%d\n", nenufares_ocupados[salto]);
    }

    return 0;
}
