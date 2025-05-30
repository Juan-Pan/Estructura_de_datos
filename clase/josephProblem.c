#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct node
{

    int key;
    struct node *next;
};

// Insertar elemento a una lista Circular Simplemente Enlazada.
struct node *InsertElementInCircularLinkedList(struct node *tail, int element)
{

    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->key = element;

    if (tail == NULL)
    {

        newNode->next = newNode;
        tail = newNode;
    }

    else
    {

        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }

    return tail;
}

// Borrar el primer nodo de una lista Circular Simplemente Enlazada.

struct node *DeleteFirstNodeOfCircularLinkedList(struct node *tail)
{

    struct node *firstNode;

    if (tail == NULL)
        printf("The circular linked list is empty.\n");

    else
    {
        if (tail == tail->next)
        {
            free(tail);
            tail = NULL;
        }

        else
        {
            firstNode = tail->next;
            tail->next = firstNode->next;
            free(firstNode);
        }
    }

    return tail;
}

// imprimirlos elementos de una lista circular simplemente enlazada del primero al ultimo

void PrintCircularLinkedList(struct node *tail)
{
    struct node *current;

    if (tail == NULL)
        printf("NULL\n");

    else
    {
        current = tail->next;

        while (current != tail)
        {
            printf("%d -> ", current->key);
            current = current->next;
        }

        printf("%d -> ...\n", current->key);
    }
}
int solver(int n, int k)
{
    struct node *tail = NULL;
    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        tail = InsertElementInCircularLinkedList(tail, i);
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < k; j++)
        {
            tail = tail->next;
        }
        tail = DeleteFirstNodeOfCircularLinkedList(tail);
    }
    result = tail->key;
    free(tail);
    return result;
}

int main()
{

    int n, k;
    while (scanf("%d %d", &n, &k) && (n > 0))
    {
        printf("%d\n", solver(n, k));
    }

    return 0;
}