//binarySearch
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXN 100000 // Tamaño máximo del arreglo TN.

// Función para realizar una búsqueda binaria en un arreglo ordenado.
// Parámetros:
// - A[]: Arreglo en el que se realiza la búsqueda.
// - i: Índice inicial del rango de búsqueda.
// - j: Índice final del rango de búsqueda.
// - k: Elemento que se desea buscar.
// Retorna:
// - Si el elemento está en el arreglo, retorna su posición.
// - Si no está, retorna un valor negativo que indica el punto de inserción.
int BinarySearch(int A[], int i, int j, int k) {
    int r = -1, m; // r almacena el resultado, m es el índice medio.

    // Bucle para realizar la búsqueda binaria.
    while (i <= j) {
        m = (i + j) / 2; // Calcular el índice medio.

        if (A[m] == k) {
            // Caso: el elemento se encuentra en la posición m.
            r = m;
            break;
        } else {
            // Caso: el elemento no está en la posición m.
            if (k > A[m]) {
                // Si k es mayor que el elemento en m, buscar en la mitad derecha.
                i = m + 1;
            } else {
                // Si k es menor, buscar en la mitad izquierda.
                j = m - 1;
            }
        }
    }

    // Si no se encontró el elemento, calcular el punto de inserción.
    if (r == -1) {
        r = -1 * i - 1; // Punto de inserción codificado como un valor negativo.
    }

    return r; // Retornar el resultado.
}

int main() {
    int TN[MAXN + 1], index, q, idQuery, element; // TN almacena los números triangulares.
    int position; // Almacena la posición del elemento buscado.

    TN[0] = 0; // Inicializar el primer número triangular como 0.

    // Generar los números triangulares y almacenarlos en el arreglo TN.
    // TN[n] = 1 + 2 + ... + n.
    for (index = 1; index <= MAXN; index++) {
        TN[index] = TN[index - 1] + index;
    }

    // Imprimir los números triangulares generados (opcional, para depuración).
    for (index = 1; index <= MAXN; index++) {
        printf("TN[%d] = %d\n", index, TN[index]);
    }

    // Leer el número de consultas (q).
    scanf("%d", &q);

    // Procesar cada consulta.
    for (idQuery = 1; idQuery <= q; idQuery++) {
        // Leer el elemento que se desea buscar.
        scanf("%d", &element);

        // Realizar la búsqueda binaria en el arreglo TN.
        position = BinarySearch(TN, 1, MAXN, element);

        if (position >= 0) {
            // Caso: el elemento está en el arreglo.
            printf("The %d is in the array in the position %d\n", element, position);
        } else {
            // Caso: el elemento no está en el arreglo.
            // Se imprime el punto de inserción calculado.
            printf("%d is not in the array. Insertion point: %d\n", element, -1 * position - 1);
        }
    }

    return 0; // Finalizar el programa.
}