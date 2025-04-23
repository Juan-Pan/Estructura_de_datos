#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo
struct node
{
    int key;           // Campo que almacena el valor del nodo
    struct node *next; // Puntero que apunta al siguiente nodo en la lista
};

int main()
{
    // Declaración de punteros para manejar la lista enlazada
    struct node *head, *q, *current;

    // Creación del primer nodo (cabeza de la lista)
    head = (struct node *)malloc(sizeof(struct node)); // Reserva de memoria para el nodo
    head->key = 1;                                     // Asignación de valor al nodo
    head->next = NULL;                                 // Inicialmente, no apunta a ningún nodo

    // Creación del segundo nodo
    q = (struct node *)malloc(sizeof(struct node)); // Reserva de memoria para el nodo
    q->key = 2;                                     // Asignación de valor al nodo
    head->next = q;                                 // El primer nodo apunta al segundo nodo

    // Creación del tercer nodo
    q->next = (struct node *)malloc(sizeof(struct node)); // Reserva de memoria para el tercer nodo
    q->next->key = 3;                                     // Asignación de valor al tercer nodo
    q->next->next = NULL;                                 // El tercer nodo es el último, apunta a NULL

    // Recorrido de la lista enlazada para imprimir los valores de los nodos
    current = head; // Inicializamos el puntero 'current' en la cabeza de la lista
    while (current != NULL)
    {                                   // Mientras no lleguemos al final de la lista
        printf("%d -> ", current->key); // Imprimimos el valor del nodo actual
        current = current->next;        // Avanzamos al siguiente nodo
    }

    // Al final del recorrido, imprimimos "NULL" para indicar el final de la lista
    printf("NULL\n");
    return 0;

    // Nota: No se libera la memoria reservada con malloc en este ejemplo.
    // En un programa real, sería importante liberar la memoria para evitar fugas.
}