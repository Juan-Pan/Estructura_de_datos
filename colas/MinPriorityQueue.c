#include <stdio.h>
#include <stdlib.h>
#define myPositiveInfinity 2147483647
#define myNegativeInfinity -2147483647
#define maxn 100

int parent (int i){
    return i/2;
}
int left (int i){
    return 2*i;
}
int right (int i){
    return 2*i+1;
}
void MinHeapify (int Q[], int i, int heapSize)
{
    int l, r, temp, least;

    l = left(i);
    r = right(i);
    if (l <= heapSize && Q[l] < Q[i]){
        least = l;
    }
    else
        least = i;

    if (r <= heapSize && Q[r] < Q[least]){
        least = r;  
    }
        if (least != i)
        {
            temp = Q[i];
            Q[i] = Q[least];
            Q[least] = temp;
            MinHeapify(Q, least, heapSize);
        }
        
}   
int MinPQ_minimum (int Q[]){
    return Q[1];
}   

int MinPQ_extract(int Q[], int *heapSize){

    int min = myNegativeInfinity;
    if(*heapSize < 1){
        printf("Error: heap underflow\n");
    }
        else
        {
            min = Q[1];
            Q[1] = Q[*heapSize];
            *heapSize = *heapSize - 1;
            MinHeapify(Q, 1, *heapSize); 
        }
    return min;
}
void MinPQ_DecreaseKey(int Q[],int i, int key){
    int temp;
    if(key > Q[i])
        printf("Error: new key is larger than current key\n");
    else{
        Q[i] = key;
        while((i > 1) && (Q[parent(i)] > Q[i])){
            temp = Q[i];
            Q[i] = Q[parent(i)];
            Q[parent(i)] = temp;
            i = parent(i);
        }
    }
}

void MinPQ_insert(int Q[], int key, int *heapSize){
    *heapSize = *heapSize + 1;
    Q[*heapSize] = myPositiveInfinity;
    MinPQ_DecreaseKey(Q, *heapSize, key);
}



int main()
{
    int operation, element, heapSize = 0, Q[maxn + 1];

    while (scanf("%d", &operation) != EOF)
    {
        if (operation == 1)  // insertar en la cola de prioridad
        {
            scanf("%d", &element);
            MinPQ_insert(Q, element, &heapSize);
        }
        else {
        
        if (operation == 2)  // extraer el elemento mínimo de la cola de prioridad
        {
            element = MinPQ_extract(Q, &heapSize);
            printf("%d\n", element);
        
        }
        else
        printf("Error! \n 1.Insert in PQ. \n 2.Extract Min. \n");
        }
    }
    
    return 0;
}