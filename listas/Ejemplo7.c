#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *next;
};

int main(){

    int n = 100;
    struct node *head = NULL, *newNode, *current;

    while (n >= 1)
    {
        newNode = (struct node *) malloc(sizeof(struct node));
        newNode->key = n;
        newNode->next = head;
        head = newNode;
        n--;

    }
    current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->key);
        current = current->next;
    }
    printf("NULL\n");
    while (head!= NULL)
    {
        current = head;
        head = head->next;
        free(current);
    }
    
return 0;
    
}