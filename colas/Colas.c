#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

struct node
{
    int key;
    struct node *next;
};
void printQueue(struct node *tail)
{
    struct node *currentNode;
    if (tail == NULL)
    {
        printf("NULL\n");
    }
    else{
        currentNode = tail->next;
        while (currentNode != tail)
        {
            printf("%d -> ", currentNode->key);
            currentNode = currentNode->next;
        }
        printf("%d \n", tail->key);
    }
}
// funcion enqueue
struct node *enqueue(struct node *tail, int element)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->key = element;
    if (tail == NULL)
    {

        newNode->next = newNode;
        return newNode;
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
    return tail;
}
// funcion dequeue
int dequeue(struct node **tail)
{
    struct node *firstNode;
    int element;
    if (*tail == (*tail)->next)
    {
        element = (*tail)->key;
        free(*tail);
        *tail = NULL;
    }
    else
    {
        firstNode = (*tail)->next;
        element = firstNode->key;
        (*tail)->next = firstNode->next;
        free(firstNode);
    }
    return element;
}
// funcion queueEmpty
int queueEmpty(struct node *tail)
{
return tail == NULL ? TRUE : FALSE;
}
int main()
{
    struct node *tail = NULL;
    int operation, element;
    while(scanf("%d", &operation) != EOF)
    {
        if(operation == 1)// Enqueue operation
        {
            scanf("%d", &element);
            tail = enqueue(tail, element);
            printQueue(tail);
        }
        else{
            if (operation == 2) // Dequeue operation
            {
                if(!queueEmpty(tail))
                {
                    element = dequeue(&tail);
                    printf("Element: %d\n", element);
                    printQueue(tail);
                }
                else
                {
                    printf("Queue is empty\n");
                }
            }
            else
            {
                printf("Bad use\n 1. Enqueue\n 2. Dequeue\n");
            }
        }
    }
        
    return 0;
}