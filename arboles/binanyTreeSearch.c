#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct nodeTree
{
    int key;
    struct nodeTree *p;
    struct nodeTree *left;
    struct nodeTree *right;
};

struct nodeTree *TreeInsert(struct nodeTree *T, int k)
{
    struct nodeTree *z, *x, *y;
    z = (struct nodeTree *)malloc(sizeof(struct nodeTree));
    z->key = k;
    z->left = NULL;
    z->right = NULL;
    y = NULL;
    x = T;
    while (x != NULL)
    {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    z->p = y;
    if (y == NULL)
        T = z; // El árbol estaba vacío
    else if (z->key < y->key)
        y->left = z; // Inserción a la izquierda
    else
        y->right = z; // Inserción a la derecha
    return T;
}
struct nodeTree *TreeMinimum(struct nodeTree *x)
{
    while (x->left != NULL)
        x = x->left;
    return x;
}
struct nodeTree *TreeSuccessor(struct nodeTree *x)
{
    struct nodeTree *y;
    if (x->right != NULL)
        return TreeMinimum(x->right);
    y = x->p;
    while (y != NULL && x == y->right)
    {
        x = y;
        y = y->p;
    }
    return y;
}
struct nodeTree *TreeDelete(struct nodeTree *T, struct nodeTree *z)
{
    struct nodeTree *y, *x;
    if (z->left == NULL || z->right == NULL)
        y = z; // Si tiene un hijo o ninguno
    else
        y = TreeSuccessor(z); // Si tiene dos hijos
    if (y->left != NULL)
        x = y->left; // Hijo izquierdo
    else
        x = y->right; // Hijo derecho
    if (x != NULL)
        x->p = y->p; // Actualizamos el padre del hijo
    if (y->p == NULL)
        T = x; // Si es la raíz, actualizamos el árbol
    else{
        if(y == y->p->left)
            y->p->left = x; // Actualizamos el hijo izquierdo del padre
        else
            y->p->right = x; // Actualizamos el hijo derecho del padre
    }
    if (y != z) // Si no es el nodo a eliminar
        z->key = y->key; // Copiamos el valor del nodo a eliminar //copy all information fields from y to z
    free(y); // Liberamos la memoria del nodo eliminado
    return T; // Retornamos el árbol actualizado    
}
void InOrderTreeWalk(struct nodeTree *T)
{
    if (T != NULL)
    {
        InOrderTreeWalk(T->left); // Recorremos el subárbol izquierdo
        printf("%d ", T->key); // Imprimimos el nodo actual
        InOrderTreeWalk(T->right); // Recorremos el subárbol derecho
    }
}
struct nodeTree *TreeSearch (struct nodeTree *x, int k)
{
    while (x != NULL && k != x->key) // Buscamos el nodo con la clave k
    {
        if (k < x->key)
            x = x->left; // Buscamos en el subárbol izquierdo
        else
            x = x->right; // Buscamos en el subárbol derecho
    }
    return x; // Retornamos el nodo encontrado o NULL si no se encontró
}
int main()
{
    int operation, element;
    struct nodeTree *T = NULL, *z;

    while(scanf("%d %d",&operation, &element) != EOF)
    {
        if(operation == 1) //insert
        {
            T = TreeInsert(T, element);
            InOrderTreeWalk(T); // Imprimimos el árbol en orden
            printf("\n");
        }
        else if (operation == 2) //delete
        {
            z = TreeSearch(T, element); // Buscamos el nodo a eliminar
            if(z==NULL) // Si no se encontró el nodo
            {
                printf("The %d is not in tree\n", element); // Imprimimos mensaje de error con salto de línea
                InOrderTreeWalk(T); // Imprimimos el árbol en orden
                printf("\n");   
            }
            else
            {
                T = TreeDelete(T, z); // Eliminamos el nodo encontrado
                InOrderTreeWalk(T); // Imprimimos el árbol en orden
                printf("\n");
            }
        }
        else{
            printf("Bad use. \n 1. Insert\n 2. Delete\n"); // Mensaje de error si la operación no es válida
        }
    }
    return 0;
}