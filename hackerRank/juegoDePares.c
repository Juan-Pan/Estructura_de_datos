#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define myPositiveInfinite 2147483647
#define myNegativeInfinite -2147483647
#define maxn 100

int Parent(int i){
    return i/2;
}
int Left(int i){
    return i*2;
} 
int Right(int i){
    return 2*i + 1;
}
//Ordena monton por monton hasta la raiz, es llamado por extract
void Minheapify(int Q[], int i, int heapSize){
    int l, r, least, temp;
    l = Left(i);
    r = Right(i);
    if (l <= heapSize && Q[l] < Q[i])
        least = l;
    else
        least = i;

    if (r <= heapSize && Q[r] < Q[least])
        least = r;
    
    if (least != i)
    {
        temp = Q[i];
        Q[i] = Q[least];
        Q[least] = temp;

        Minheapify(Q, least, heapSize);
    }
}
int MinPQ_Minimum(int Q[]){
    return Q[1];
}
//extraer la raiz, reorganiza el monton
//element = MinPQ_Extract(Q, &heapSize);
int MinPQ_Extract(int Q[], int *heapSize){
    int min = myNegativeInfinite;

    if (*heapSize < 1)
        printf("Error: Heap underflow.\n");
    else
    {
        min = Q[1];
        Q[1] = Q[*heapSize];
        *heapSize = *heapSize - 1;
        Minheapify(Q, 1, *heapSize);
    }

    return min;
}
//Organizar el arbol a medidad que se inserta
void MinPQ_DecreaseKey(int Q[], int i, int key){
    int temp;
    if (key > Q[i])
        printf("New key is higher than current\n");
    else
    {
        Q[i] = key;
        while (i > 1 && Q[Parent(i)] > Q[i]) //i llega a la raiz, por lo cual termina el intercambio
        {
            temp = Q[i];
            Q[i] = Q[Parent(i)];
            Q[Parent(i)] = temp;
            i = Parent(i);
        }   
    }
}
// MinPQ_Insert(Q, element, &heapSize); heapsize debe iniciar en 0
void MinPQ_Insert(int Q[], int key, int *heapSize){
    *heapSize = *heapSize + 1;
    Q[*heapSize] = myPositiveInfinite;
    MinPQ_DecreaseKey(Q, *heapSize, key);
}

int main()
{
    int t, n, heapSizeO = 0, heapSizeE = 0, otto[maxn + 1], emma[maxn + 1], element, counter, num1, num2, suma, div; // Inicialización del heap.
    scanf("%d", &t);
    while (t > 0)
    {
        scanf("%d", &n);
        heapSizeO = 0;
        heapSizeE = 0;
        counter = 0; // Reiniciar el contador para cada caso de prueba.

        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &element);
            MinPQ_Insert(emma, -1 * element, &heapSizeE);
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &element);
            MinPQ_Insert(otto, element, &heapSizeO);
        }
        while (heapSizeE > 0 && heapSizeO > 0) // Continuar mientras ambos heaps tengan elementos.
        {
            num1 = -1 * MinPQ_Extract(emma, &heapSizeE); // Extraer y revertir el signo.
            num2 = MinPQ_Extract(otto, &heapSizeO); // Extraer y revertir el signo.
            suma = num1 + num2;
            if (suma % 2 == 0)
            {
                div = suma / 2;
                MinPQ_Insert(emma, -1 * div, &heapSizeE); 
            }
            else
            {
                MinPQ_Insert(otto,suma, &heapSizeO); 
                
            }

            counter++;
        }

        // Determinar el ganador.
        if (heapSizeE < 1)
        {
            printf("%d Otto\n", counter);
        }
        else if (heapSizeO < 1)
        {
            printf("%d Emma\n", counter);
        }

        t--;
    }

    return 0;
}