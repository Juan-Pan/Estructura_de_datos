#include <stdio.h>
#include <stdlib.h>


struct  node
{
    int key;
    struct node *next;
};


int main(){
    struct node *head, *q, *current;
    head = (struct node *) malloc(sizeof(struct node));
    head->key = 1;
    q = (struct node*) malloc(sizeof(struct node));
    q->key = 2;
    head->next = q;
    q->next = (struct node*) malloc(sizeof(struct node));
    q->next->key = 3;
    q->next->next = NULL;

    current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->key);
        current = current->next;
    }

    printf("NULL\n");
    
}

/*struct node
{
    int key;
    struct node *next;
};

int main(){
    struct node *head, *q, *current;
    head = (struct node *) malloc (sizeof(struct node));  
    head -> key = 1; 
    q = (struct node *) malloc (sizeof(struct node)); 
    q -> key = 2;
    head -> next = q;
    q = (struct node *) malloc (sizeof(struct node));
    q->next->key = 3;
    q ->next-> next = NULL;
    current = head;

    while (current != NULL){
        printf("%d ->", current -> key);
        current = current -> next;
    }
    printf("NULL\n");
    return 0;
}*/
