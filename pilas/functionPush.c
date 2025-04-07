#include<stdio.h>

struct node *push(struct node *top, int element){
    
    struct node *newNode;
    newNode = (struct node *) malloc(sizeof (struct node));
    newNode->key = element;
    newNode->next = top; 
    top = newNode;
    return top;
int main(){

    return 0;
}