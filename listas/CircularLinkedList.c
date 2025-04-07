//circularLinkedList
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Definición de la estructura de un nodo en la lista circular simplemente enlazada.
struct node {
    int key; // Valor almacenado en el nodo.
    struct node *next; // Puntero al siguiente nodo en la lista.
};

// Función para insertar un elemento en la lista circular simplemente enlazada.
// Si la lista está vacía, se crea un nuevo nodo que apunta a sí mismo.
// Si no está vacía, se inserta el nuevo nodo después del nodo actual "tail".
struct node *InsertElementInCircularLinkedList(struct node *tail, int element) {
    struct node *newNode;
    newNode = (struct node *) malloc(sizeof(struct node)); // Se reserva memoria para el nuevo nodo.
    newNode->key = element; // Se asigna el valor al campo "key" del nuevo nodo.

    if (tail == NULL) {
        // Caso: la lista está vacía.
        newNode->next = newNode; // El puntero "next" apunta al propio nodo.
        tail = newNode; // El nuevo nodo se convierte en el nodo "tail".
    } else {
        // Caso: la lista no está vacía.
        newNode->next = tail->next; // El puntero "next" del nuevo nodo apunta al primer nodo de la lista.
        tail->next = newNode; // El puntero "next" del nodo "tail" apunta al nuevo nodo.
        tail = newNode; // El nuevo nodo se convierte en el nodo "tail".
    }
    return tail;
}

// Función para eliminar el primer nodo de la lista circular simplemente enlazada.
// Si la lista está vacía, se imprime un mensaje.
// Si la lista tiene un solo nodo, se libera la memoria y se establece tail en NULL.
// Si tiene más de un nodo, se elimina el primer nodo y se actualizan los punteros.
struct node *DeleteFirstNodeOfCircularLinkedList(struct node *tail) {
    struct node *firstNode; // Puntero temporal para almacenar el primer nodo.

    if (tail == NULL) {
        // Caso: la lista está vacía.
        printf("The circular linked list is empty.\n");
    } else {
        if (tail == tail->next) {
            // Caso: la lista tiene un solo nodo.
            free(tail); // Se libera la memoria del nodo.
            tail = NULL; // Se establece tail en NULL.
        } else {
            // Caso: la lista tiene más de un nodo.
            firstNode = tail->next; // Se apunta al primer nodo de la lista.
            tail->next = firstNode->next; // El puntero "next" del nodo "tail" apunta al segundo nodo.
            free(firstNode); // Se libera la memoria del primer nodo.
        }
    }
    return tail;
}

// Función para imprimir los elementos de la lista circular simplemente enlazada desde el primero hasta el último.
// Si la lista está vacía, se imprime "NULL".
// Si no está vacía, se recorre desde el primer nodo hasta el último.
void PrintCircularLinkedList(struct node *tail) {
    struct node *current; // Puntero para recorrer la lista.

    if (tail == NULL) {
        printf("NULL\n");
    } else {
        current = tail->next; // Se apunta al primer nodo de la lista.
        while (current != tail) {
            printf("%d -> ", current->key); // Se accede al valor del nodo usando "->".
            current = current->next; // Se avanza al siguiente nodo usando "next".
        }
        printf("%d -> ...\n", current->key); // Se imprime el valor del último nodo.
    }
}

// Función principal del programa.
// Permite al usuario realizar operaciones de inserción y eliminación en la lista.
// También imprime la lista después de cada operación.
int main() {
    struct node *tail = NULL; // Inicialización de la lista como vacía.
    int operation, element;

    // Bucle para leer operaciones del usuario hasta el final de la entrada.
    while (scanf("%d", &operation) != EOF) {
        if (operation == 1) { 
            // Operación de inserción.
            scanf("%d", &element);
            tail = InsertElementInCircularLinkedList(tail, element);
            PrintCircularLinkedList(tail);
        } else if (operation == 2) {
            // Operación de eliminación.
            tail = DeleteFirstNodeOfCircularLinkedList(tail);
            PrintCircularLinkedList(tail);
        } else {
            // Operación no válida.
            printf("Bad use.\n 1.Insert\n 2.Delete\n");
        }
    }
    return 0;
}