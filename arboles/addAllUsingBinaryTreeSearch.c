#include <stdio.h>
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
        T = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;
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
        y = z;
    else
        y = TreeSuccessor(z);
    if (y->left != NULL)
        x = y->left;
    else
        x = y->right;
    if (x != NULL)
        x->p = y->p;
    if (y->p == NULL)
        T = x;
    else
    {
        if (y == y->p->left)
            y->p->left = x;
        else
            y->p->right = x;
    }
    if (y != z)
        z->key = y->key;
    free(y);
    return T;
}

void InOrderTreeWalk(struct nodeTree *T)
{
    if (T != NULL)
    {
        InOrderTreeWalk(T->left);
        printf("%d ", T->key);
        InOrderTreeWalk(T->right);
    }
}

struct nodeTree *TreeSearch(struct nodeTree *x, int k)
{
    while (x != NULL && k != x->key)
    {
        if (k < x->key)
            x = x->left;
        else
            x = x->right;
    }
    return x;
}



int main()
{
    int n, element, idElement;
    long long int result;
    struct nodeTree *T = NULL, *z;

    while (scanf("%d", &n) && (n > 0))
    {
        for (idElement = 1; idElement <= n; idElement++)
        {
            scanf("%d", &element);
            T = TreeInsert(T, element);
        }
        result = 0;
        while (T != NULL && (T->left != NULL || T->right != NULL)) // Ajustar condición para procesar correctamente el último nodo
        {
            z = TreeMinimum(T);
            element = z->key; // Accede al valor antes de eliminar el nodo
            T = TreeDelete(T, z);

            if (T != NULL) // Verifica si el árbol aún tiene nodos
            {
                z = TreeMinimum(T);
                element += z->key;
                T = TreeDelete(T, z);
                result += element;
                T = TreeInsert(T, element);
            }
        }
        printf("%lld\n", result);
        Free(T);
        T = NULL;
    }
    return 0;
}