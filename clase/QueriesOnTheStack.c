// pilas
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

// Definición de la estructura de un nodo
struct node
{
    int key;           // Almacena el valor del nodo
    int maximum;       // Almacena el valor máximo de la pila
    int minimum;       // Almacena el valor mínimo de la pila
    struct node *next; // Puntero que apunta al siguiente nodo en la pila
};

// Función para insertar un elemento en la pila
// Parámetros:
// - top: Puntero al nodo superior de la pila (tope actual).
// - element: Valor que se desea insertar en la pila.
// Retorna:
// - Un puntero al nuevo nodo que ahora es el tope de la pila.
struct node *push(struct node *top, int element)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node)); // Reservar memoria para el nuevo nodo

    newNode->key = element; // Asignar el valor al nodo
    newNode->next = top;    // Apuntar al nodo que actualmente es el tope
    if (top == NULL)
    {                               // Si la pila estaba vacía
        newNode->maximum = element; // El nuevo nodo es el máximo
        newNode->minimum = element; // El nuevo nodo es el mínimo
    }
    else
    {
        if (element > top->maximum)
        {
            newNode->maximum = element; // Actualizar el máximo
        }
        else
        {
            newNode->maximum = top->maximum; // Mantener el máximo anterior
        }
        if (element < top->minimum)
        {
            newNode->minimum = element; // Actualizar el mínimo
        }
        else
        {
            newNode->minimum = top->minimum; // Mantener el mínimo anterior
        }
    }
    top = newNode; // Actualizar el tope de la pila
    return top;     // Retornar el nuevo tope
}

    // Función para eliminar el elemento superior de la pila
    // Parámetros:
    // - top: Doble puntero al nodo superior de la pila (para modificar el tope original).
    // Retorna:
    // - El valor del nodo eliminado (elemento en el tope de la pila).
    int pop(struct node * *top)
    {
        struct node *currentNode; // Nodo temporal para almacenar el nodo superior
        int element;              // Variable para almacenar el valor del nodo eliminado

        currentNode = *top;         // Apuntar al nodo superior actual
        element = currentNode->key; // Obtener el valor del nodo
        *top = currentNode->next;   // Actualizar el tope al siguiente nodo
        free(currentNode);          // Liberar la memoria del nodo eliminado

        return element; // Retornar el valor eliminado
    }

    // Función para verificar si la pila está vacía
    // Parámetros:
    // - top: Puntero al nodo superior de la pila.
    // Retorna:
    // - TRUE (1) si la pila está vacía, FALSE (0) en caso contrario.
    int stackEmpty(struct node * top)
    {
        return top == NULL ? TRUE : FALSE; // Retorna TRUE si el tope es NULL, FALSE en caso contrario
    }

    // Función para imprimir el contenido de la pila
    // Parámetros:
    // - top: Puntero al nodo superior de la pila.
    // Imprime:
    // - Los valores de los nodos desde el tope hasta el final de la pila.
    void printStack(struct node * top)
    {
        struct node *current = top; // Nodo temporal para recorrer la pila

        while (current != NULL)
        {                                   // Mientras no lleguemos al final de la lista
            printf("%d -> ", current->key); // Imprimimos el valor del nodo actual
            current = current->next;        // Avanzamos al siguiente nodo
        }
        printf("NULL\n"); // Indicamos el final de la lista
    }

    // Función principal
    int main()
    {
        struct node *top = NULL; 
        int t, q, operation, element;
    
        scanf("%d", &t); 
    
        while (t-- )
        {
            scanf("%d", &q); 
    
            top = NULL; 
    
            for (int i = 0; i < q; i++)
            {
                scanf("%d", &operation);
    
                if (operation == 1)
                { // Push
                    scanf("%d", &element);
                    top = push(top, element);
                }
                else if (operation == 2)
                { // Pop
                    if (!stackEmpty(top))
                    {
                        pop(&top);
                    }
                }
                else if (operation == 3)
                { 
                    if (!stackEmpty(top))
                    {
                        printf("%d\n", abs(top->maximum - top->minimum));
                    }
                    else
                    {
                        printf("Empty!\n");
                    }
                }
            }
        }
    
        return 0;
    }

    /*
    GitHub Copilot
    Aquí está tu código completamente documentado, sin realizar ningún cambio en su estructura o funcionalidad:

    Flujo de ejecución del programa
    Inicialización:

    La pila comienza vacía (top = NULL).
    Se definen las variables operation (para identificar la operación a realizar) y element (para almacenar el valor a insertar o eliminar).
    Entrada del usuario:

    El programa lee continuamente desde la entrada estándar (scanf) hasta que se alcance el final del archivo (EOF).
    El usuario debe ingresar un número que representa la operación:
    1: Insertar un elemento en la pila (push).
    2: Eliminar el elemento superior de la pila (pop).
    Operación push:

    Si el usuario ingresa 1, el programa solicita un número adicional (element) que será insertado en la pila.
    La función push:
    Crea un nuevo nodo.
    Asigna el valor del elemento al nodo.
    Actualiza el puntero top para que apunte al nuevo nodo.
    Después de la inserción, se llama a printStack para mostrar el estado actual de la pila.
    Operación pop:

    Si el usuario ingresa 2, el programa verifica si la pila está vacía usando stackEmpty.
    Si la pila no está vacía:
    Se llama a la función pop, que elimina el nodo superior y devuelve su valor.
    El valor eliminado se imprime en pantalla.
    Se llama a printStack para mostrar el estado actual de la pila.
    Si la pila está vacía, se imprime un mensaje indicando que no se puede realizar la operación.
    Operación inválida:

    Si el usuario ingresa un número distinto de 1 o 2, se imprime un mensaje de error indicando el uso correcto del programa.
    Finalización:

    El programa continúa ejecutándose hasta que se alcance el final de la entrada estándar (EOF).
    Al finalizar, el programa retorna 0

    Ejemplo de ejecucion
    1 10
    1 20
    2
    2
    2

    Salida
    10 -> NULL
    20 -> 10 -> NULL
    Elemento: 20
    10 -> NULL
    Elemento: 10
    NULL
    The stack is empty
    */