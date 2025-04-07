#include <stdio.h>
#include <stdlib.h>

// Definimos constantes para representar valores booleanos
#define TRUE 1
#define FALSE 0

// Definimos la estructura de un nodo de la cola
struct node
{
    int key; // Valor que almacena el nodo
    struct node *next; // Puntero al siguiente nodo
};

// Función para imprimir la cola
// Recibe como parámetro el puntero al último nodo (tail)
void printQueue(struct node *tail)
{
    struct node *currentNode;
    if (tail == NULL) // Si la cola está vacía
    {
        printf("NULL\n");
    }
    else
    {
        // Recorremos la cola desde el primer nodo hasta el último
        currentNode = tail->next;
        while (currentNode != tail)
        {
            printf("%d -> ", currentNode->key); // Imprimimos el valor del nodo
            currentNode = currentNode->next; // Avanzamos al siguiente nodo
        }
        printf("%d \n", tail->key); // Imprimimos el último nodo
    }
}

// Función para agregar un elemento a la cola (enqueue)
// Recibe el puntero al último nodo (tail) y el elemento a insertar
struct node *enqueue(struct node *tail, int element)
{
    struct node *newNode;
    // Reservamos memoria para el nuevo nodo
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->key = element; // Asignamos el valor al nodo
    if (tail == NULL) // Si la cola está vacía
    {
        newNode->next = newNode; // El nuevo nodo se apunta a sí mismo
        return newNode; // El nuevo nodo es ahora el último
    }
    else
    {
        // Insertamos el nuevo nodo después del último nodo
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode; // Actualizamos el puntero al último nodo
    }
    return tail;
}

// Función para eliminar un elemento de la cola (dequeue)
// Recibe un puntero al puntero del último nodo (tail)
int dequeue(struct node **tail)
{
    struct node *firstNode;
    int element;
    if (*tail == (*tail)->next) // Si solo hay un nodo en la cola
    {
        element = (*tail)->key; // Guardamos el valor del nodo
        free(*tail); // Liberamos la memoria del nodo
        *tail = NULL; // La cola ahora está vacía
    }
    else
    {
        // Eliminamos el primer nodo de la cola
        firstNode = (*tail)->next;
        element = firstNode->key; // Guardamos el valor del nodo
        (*tail)->next = firstNode->next; // Actualizamos el puntero al siguiente nodo
        free(firstNode); // Liberamos la memoria del nodo eliminado
    }
    return element; // Retornamos el valor eliminado
}

// Función para verificar si la cola está vacía
// Retorna TRUE si está vacía, FALSE en caso contrario
int queueEmpty(struct node *tail)
{
    return tail == NULL ? TRUE : FALSE;
}

// Función principal
int main()
{
    struct node *tail = NULL; // Inicializamos la cola como vacía
    int operation, element;

    // Ciclo para leer operaciones hasta el final de la entrada
    while (scanf("%d", &operation) != EOF)
    {
        if (operation == 1) // Operación de enqueue
        {
            scanf("%d", &element); // Leemos el elemento a insertar
            tail = enqueue(tail, element); // Insertamos el elemento
            printQueue(tail); // Imprimimos la cola
        }
        else
        {
            if (operation == 2) // Operación de dequeue
            {
                if (!queueEmpty(tail)) // Si la cola no está vacía
                {
                    element = dequeue(&tail); // Eliminamos el primer elemento
                    printf("Element: %d\n", element); // Imprimimos el elemento eliminado
                    printQueue(tail); // Imprimimos la cola
                }
                else
                {
                    printf("Queue is empty\n"); // Mensaje si la cola está vacía
                }
            }
            else
            {
                // Mensaje de error si la operación no es válida
                printf("Bad use\n 1. Enqueue\n 2. Dequeue\n");
            }
        }
    }

    return 0; // Fin del programa
}