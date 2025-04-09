#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define counterClockWise -1
#define clockWise 1

struct node
{
    int key;
    struct node *next;
    struct node *prev;
};

struct node *InsertElementInCircularDoublyLinkedList(struct node *tail, int element)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->key = element;

    if (tail == NULL)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = tail->next;
        newNode->prev = tail;
        tail->next = newNode;
        newNode->next->prev = newNode;
        tail = newNode;
    }
    return tail;
}

// struct node *DeleteFirstNodeOfCircularDoublyLinkedList(struct node *tail)
// {
//     struct node *firstNode;

//     if (tail == NULL)
//     {
//         printf("The circular doubly linked list is empty.\n");
//     }
//     else
//     {
//         if (tail == tail->next)
//         {
//             free(tail);
//             tail = NULL;
//         }
//         else
//         {
//             firstNode = tail->next;
//             tail->next = firstNode->next;
//             firstNode->next->prev = tail;
//             free(firstNode);
//         }
//     }
//     return tail;
// }

void PrintFirstToLast(struct node *tail)
{
    struct node *current;

    if (tail == NULL)
    {
        printf("NULL\n");
    }
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

void PrintLastToFirst(struct node *tail)
{
    struct node *current, *first;

    if (tail == NULL)
    {
        printf("NULL\n");
    }
    else
    {
        current = tail;
        first = tail->next;
        while (current != first)
        {
            printf("%d -> ", current->key);
            current = current->prev;
        }
        printf("%d -> ...\n", current->key);
    }
}

struct node *BuildCircularDoublyLinkedList(struct node *tail, int n)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        tail = InsertElementInCircularDoublyLinkedList(tail, i);
    }
    return tail;
}

int solver(int n, int k)
{
    struct node *tail = NULL, *current, *turn;
    int direction = clockWise, winner;
    tail = BuildCircularDoublyLinkedList(tail, n);
    current = tail->next;

    while (n > 1)
    {
        if (direction == clockWise)
        {
            for (int i = 1; i < k; i++)
            {
                current = current->next;
            }
            turn = current->next;
            current->next->prev = current->prev;
            current->prev->next = current->next;
            free(current);
            current = turn;
            direction = counterClockWise;
        }
        else
        {
            for (int i = 1; i < k; i++)
            {
                current = current->prev;
            }
            turn = current->prev;
            current->next->prev = current->prev;
            current->prev->next = current->next;
            free(current);
            current = turn;
            direction = clockWise;
        }
        n--;
    }
    winner = current->key;
    free(current);
    return winner;
}

int main()
{
    int n, k;

    while (scanf("%d %d", &n, &k) && (n > 0) && (k > 0))
    {
        printf("%d\n", solver(n, k));
    }
    return 0;
}