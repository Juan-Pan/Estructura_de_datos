//mergeSort
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXN 100 // Tamaño máximo del arreglo.
#define infinity 2147483647 // Representa un valor infinito positivo para comparación.

// Función para combinar dos subarreglos ordenados en un único subarreglo ordenado.
// Parámetros:
// - A[]: Arreglo original.
// - p: Índice inicial del primer subarreglo.
// - q: Índice final del primer subarreglo (y uno antes del inicio del segundo).
// - r: Índice final del segundo subarreglo.
void myMerge(int A[], int p, int q, int r) {
    int n1 = q - p + 1; // Tamaño del primer subarreglo.
    int n2 = r - q; // Tamaño del segundo subarreglo.
    int i, j, k;
    int L[n1 + 2], R[n2 + 2]; // Subarreglos temporales para almacenar los elementos.

    // Copiar los elementos del primer subarreglo al arreglo temporal L[].
    for (i = 1; i <= n1; i++) {
        L[i] = A[p + i - 1];
    }

    // Copiar los elementos del segundo subarreglo al arreglo temporal R[].
    for (j = 1; j <= n2; j++) {
        R[j] = A[q + j];
    }

    // Agregar valores "infinito" al final de los subarreglos para evitar desbordamientos.
    L[n1 + 1] = infinity;
    R[n2 + 1] = infinity;

    i = 1; // Índice para recorrer L[].
    j = 1; // Índice para recorrer R[].

    // Combinar los subarreglos L[] y R[] en el arreglo original A[].
    for (k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i]; // Tomar el elemento de L[] si es menor o igual.
            i++;
        } else {
            A[k] = R[j]; // Tomar el elemento de R[] si es menor.
            j++;
        }
    }
}

// Función para ordenar un arreglo utilizando el algoritmo Merge Sort.
// Parámetros:
// - A[]: Arreglo a ordenar.
// - p: Índice inicial del subarreglo.
// - r: Índice final del subarreglo.
void MergeSort(int A[], int p, int r) {
    int q;
    if (p < r) {
        q = (p + r) / 2; // Calcular el índice medio para dividir el arreglo.
        MergeSort(A, p, q); // Ordenar la primera mitad.
        MergeSort(A, q + 1, r); // Ordenar la segunda mitad.
        myMerge(A, p, q, r); // Combinar ambas mitades ordenadas.
    }
}

int main() {
    int A[MAXN + 1], n, i; // A[] es el arreglo a ordenar, n es el tamaño del arreglo.

    // Leer el tamaño del arreglo y sus elementos desde la entrada estándar.
    while (scanf("%d", &n) != EOF) {
        for (i = 1; i <= n; i++) {
            scanf("%d", &A[i]); // Leer cada elemento del arreglo.
        }

        MergeSort(A, 1, n); // Ordenar el arreglo utilizando Merge Sort.

        // Imprimir el arreglo ordenado.
        for (i = 1; i <= n; i++) {
            printf("%d ", A[i]);
        }
        printf("\n"); // Nueva línea después de imprimir el arreglo.
    }

    return 0; // Finalizar el programa.
}