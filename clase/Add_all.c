#include <stdio.h>
#include <stdlib.h>
#define myPositiveInfinity 2147483647
#define myNegativeInfinity -2147483647
#define maxn 5000

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
    else{
        least = i;
    }

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
    int n,element, heapSize = 0, Q[maxn + 1];
    long long int result;

    while (scanf("%d", &n) && (n >0 ))
    {

        heapSize = 0;
        result = 0;
        for (int i = 1; i <= n; i++){
            scanf("%d", &element);
            MinPQ_insert(Q, element, &heapSize);
        }
        while(heapSize >= 2){
            element = MinPQ_extract(Q, &heapSize);
            element += MinPQ_extract(Q, &heapSize);
            result += element;
            MinPQ_insert(Q, element, &heapSize);
        }
        printf("%lld\n", result);
    }
    return 0;
}
