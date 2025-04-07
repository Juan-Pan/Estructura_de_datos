//MinPriorityQueue 
#include <stdio.h>
#include <stdlib.h>
#define myPositiveInfinity 2147483647 // Representa un valor infinito positivo.
#define myNegativeInfinity -2147483647 // Representa un valor infinito negativo.
#define maxn 100 // Tamaño máximo del heap.

// Función para obtener el índice del nodo padre de un nodo en el heap.
int parent(int i) {
    return i / 2; // El padre de un nodo en el índice i está en i/2.
}

// Función para obtener el índice del hijo izquierdo de un nodo en el heap.
int left(int i) {
    return 2 * i; // El hijo izquierdo de un nodo en el índice i está en 2*i.
}

// Función para obtener el índice del hijo derecho de un nodo en el heap.
int right(int i) {
    return 2 * i + 1; // El hijo derecho de un nodo en el índice i está en 2*i+1.
}

// Función para mantener la propiedad de min-heap en el árbol.
// Si el nodo en el índice i viola la propiedad de min-heap, se corrige.
void MinHeapify(int Q[], int i, int heapSize) {
    int l, r, temp, least;

    l = left(i); // Índice del hijo izquierdo.
    r = right(i); // Índice del hijo derecho.

    // Determinar el nodo más pequeño entre el nodo actual y sus hijos.
    if (l <= heapSize && Q[l] < Q[i]) {
        least = l; // El hijo izquierdo es menor.
    } else {
        least = i; // El nodo actual es menor.
    }

    if (r <= heapSize && Q[r] < Q[least]) {
        least = r; // El hijo derecho es menor.
    }

    // Si el nodo actual no es el menor, intercambiar y continuar corrigiendo.
    if (least != i) {
        temp = Q[i]; // Intercambio de valores.
        Q[i] = Q[least];
        Q[least] = temp;
        MinHeapify(Q, least, heapSize); // Llamada recursiva para corregir el subárbol.
    }
}

// Función para obtener el elemento mínimo del heap (siempre está en la raíz).
int MinPQ_minimum(int Q[]) {
    return Q[1]; // El elemento mínimo está en el índice 1.
}

// Función para extraer el elemento mínimo del heap.
// Reduce el tamaño del heap y mantiene la propiedad de min-heap.
int MinPQ_extract(int Q[], int *heapSize) {
    int min = myNegativeInfinity; // Inicialización del valor mínimo.

    if (*heapSize < 1) {
        // Caso: el heap está vacío.
        printf("Error: heap underflow\n");
    } else {
        min = Q[1]; // El elemento mínimo está en la raíz.
        Q[1] = Q[*heapSize]; // Reemplazar la raíz con el último elemento.
        *heapSize = *heapSize - 1; // Reducir el tamaño del heap.
        MinHeapify(Q, 1, *heapSize); // Corregir la propiedad de min-heap.
    }
    return min;
}

// Función para disminuir la clave de un nodo en el heap.
// Si la nueva clave es mayor que la actual, se imprime un error.
// Si no, se actualiza la clave y se ajusta el heap hacia arriba.
void MinPQ_DecreaseKey(int Q[], int i, int key) {
    int temp;

    if (key > Q[i]) {
        // Caso: la nueva clave es mayor que la actual.
        printf("Error: new key is larger than current key\n");
    } else {
        Q[i] = key; // Actualizar la clave del nodo.
        // Ajustar el heap hacia arriba mientras se viole la propiedad de min-heap.
        while ((i > 1) && (Q[parent(i)] > Q[i])) {
            temp = Q[i]; // Intercambio de valores.
            Q[i] = Q[parent(i)];
            Q[parent(i)] = temp;
            i = parent(i); // Moverse al nodo padre.
        }
    }
}

// Función para insertar un nuevo elemento en el heap.
// Se incrementa el tamaño del heap y se ajusta la posición del nuevo elemento.
void MinPQ_insert(int Q[], int key, int *heapSize) {
    *heapSize = *heapSize + 1; // Incrementar el tamaño del heap.
    Q[*heapSize] = myPositiveInfinity; // Inicializar el nuevo elemento con infinito.
    MinPQ_DecreaseKey(Q, *heapSize, key); // Ajustar la clave del nuevo elemento.
}

// Función principal del programa.
// Permite al usuario realizar operaciones de inserción y extracción en la cola de prioridad.
int main() {
    int operation, element, heapSize = 0, Q[maxn + 1]; // Inicialización del heap.

    // Bucle para leer operaciones del usuario hasta el final de la entrada.
    while (scanf("%d", &operation) != EOF) {
        if (operation == 1) {
            // Operación de inserción en la cola de prioridad.
            scanf("%d", &element);
            MinPQ_insert(Q, element, &heapSize);
        } else if (operation == 2) {
            // Operación de extracción del elemento mínimo.
            element = MinPQ_extract(Q, &heapSize);
            printf("%d\n", element);
        } else {
            // Operación no válida.
            printf("Error! \n 1.Insert in PQ. \n 2.Extract Min. \n");
        }
    }

    return 0;
}