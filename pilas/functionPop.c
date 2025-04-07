#include <stdio.h>
int pop (struct node **top)
{    
    struct node *currentNode;
    int element;
    currentNode = *top;
    element = currentNode->key;
    *top = currentNode->next;
    free(currentNode);
    return element;
}