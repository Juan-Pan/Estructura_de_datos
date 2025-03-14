
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>
#define myInfinite "zzzzzzzzzzzzzz"
#define MAXN 1000001


typedef struct {
    char numero [15];

} nombres;


void myMerge (nombres A[], int p, int q, int r) {
    int i, j, k, n1 = q - p + 1, n2 = r - q; 
    nombres L[n1 + 2], R[n2 + 2];

    for (i = 1; i <= n1; i++) 
        L[i] = A[p + i - 1];

    for (j = 1; j <= n2; j++)
        R[j] = A[q + j];


    strcpy (L[n1 + 1].numero, myInfinite);
    strcpy (R[n2 + 1].numero, myInfinite);

    i = 1; 
    j = 1;

    for (k = p; k <= r; k++) {
        if (strcmp (L[i].numero, R[j].numero) <= 0) {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort (nombres A[], int p, int r) {
    int q;
    if (p < r) {
        q = (p + r) / 2;
        mergeSort (A, p, q);
        mergeSort (A, q + 1, r);
        myMerge (A, p, q, r);
    }
}


int binarySearch (nombres A[], int i, int j, char k[]) {

    int m;
    if (i > j) {
        return -1 * i - 1;
    }
    else {
        m = (i + j)/2;
        if (strcmp (A[m].numero, k) == 0) {
            return m;
        }
        else {
            if (strcmp (A[m].numero, k) < 0)
                return binarySearch (A, m + 1, j, k);
            else
                return binarySearch (A, i, m - 1, k);
        }
    }
}


int main () {

    int palabrasTotal, q, LimiteIzquierdo, LimiteDerecho, numeroPalabras;

    char aux[15], inferior[15], superior[15];
    nombres diccionario[MAXN + 1];

    //ingreso de datos
    scanf ("%d %d", &palabrasTotal, &q);

    //lleno el diccionario con las palabras que va a tener
    for (int i = 1; i <= palabrasTotal; i++) {
        scanf ("%s", aux);
        strcpy (diccionario[i].numero, aux);
    }

    //se hace ordenamiento
    mergeSort (diccionario, 1, palabrasTotal);

    
    while (q--) {
        //Palabras que se van a buscar
        scanf ("%s %s", inferior, superior);

        //busco los limites de las palabras
        LimiteIzquierdo = binarySearch (diccionario, 1, palabrasTotal, inferior);
        LimiteDerecho = binarySearch (diccionario, 1, palabrasTotal, superior);

        //limite izquierdo si no se encuentra la palabra 
        if (LimiteIzquierdo < 0) 
            LimiteIzquierdo = - 1 * LimiteIzquierdo - 1;
        
       //limite derecho si no está
        if (LimiteDerecho < 0) 
            LimiteDerecho = -1 * LimiteDerecho - 2;
        
        //hago la diferencia entre los limites para saber cuantas palabras hay entre ellos
        numeroPalabras = LimiteDerecho - LimiteIzquierdo + 1;
        printf ("%d\n", numeroPalabras);
    }
    return 0;
}