#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXV 1000
#define BLACK 0
#define GRAY 1
#define WHITE 2
#define NIL -1

struct edge
{
    int vertex;
    /*  int weight;  */
    struct edge *next;
};

struct graph
{
    int n_vertex;
    int m_edges;
    struct edge *Adj[MAXV + 1];
};

struct graph *ReadGraph(int vertices, int edges)
{
    int idVertex, idEdge, u, v;
    struct graph *G;
    struct edge *tempEdge;

    G = (struct graph *)malloc(sizeof(struct graph));
    G->n_vertex = vertices;
    G->m_edges = edges;

    for (idVertex = 1; idVertex <= G->n_vertex; idVertex++)
        G->Adj[idVertex] = NULL;

    for (idEdge = 1; idEdge <= G->m_edges; idEdge++)
    {
        scanf("%d %d", &u, &v);
        tempEdge = (struct edge *)malloc(sizeof(struct edge));
        tempEdge->vertex = v;
        tempEdge->next = G->Adj[u];
        G->Adj[u] = tempEdge;

        if (u != v)
        {
            tempEdge = (struct edge *)malloc(sizeof(struct edge));
            tempEdge->vertex = u;
            tempEdge->next = G->Adj[v];
            G->Adj[v] = tempEdge;
        }
    }
    return G;
}

void PrintGraph(struct graph *G)
{
    int idVertex;
    struct edge *tempEdge;

    if (G != NULL)
    {
        printf("Representation for graph's adjacent lists: \n");
        for (idVertex = 1; idVertex <= G->n_vertex; idVertex++)
        {
            printf("[%d]: ", idVertex);
            tempEdge = G->Adj[idVertex];
            while (tempEdge != NULL)
            {
                printf(" -> %d", tempEdge->vertex);
                tempEdge = tempEdge->next;
            }
            printf(" -> NULL\n");
        }
    }
    else
        printf("Empty Graph.\n");
}

struct graph *DeleteGraph(struct graph *G)
{
    int idVertex;
    struct edge *ActualEdge, *NextEdge;

    for (idVertex = 1; idVertex <= G->n_vertex; idVertex++)
    {
        ActualEdge = G->Adj[idVertex];
        while (ActualEdge != NULL)
        {
            NextEdge = ActualEdge->next;
            free(ActualEdge);
            ActualEdge = NextEdge;
        }
    }
    free(G);
    G = NULL;
    return G;
}
void DFS_visit(struct graph *G, int u, int *time, int color[], int pi[], int d[], int f[])
{
    struct edge *tempEdge;
    int v;
    color[u] = GRAY;
    *time = *time + 1;
    d[u] = *time;

    tempEdge = G->Adj[u];

    while (tempEdge != NULL)
    {
        v = tempEdge->vertex;
        if (color[v] == WHITE)
        {
            pi[v] = u;
            DFS_visit(G, v, &(*time), color, pi, d, f);
        }
        tempEdge = tempEdge->next;
    }
    color[u] = BLACK;
    *time = *time + 1;
    f[u] = *time;
}

void DFS(struct graph *G, int color[], int pi[], int d[], int f[])
{
    int u, time = 0;
    for (u = 1; u <= G->n_vertex; u++)
    {
        color[u] = WHITE;
        pi[u] = NIL;
    }
    for (u = 1; u <= G->n_vertex; u++)
    {
        if (color[u] == WHITE)
        {
            DFS_visit(G, u, &time, color, pi, d, f);
        }
    }
}

void solver(struct graph *G)
{
    int color[MAXV + 1], pi[MAXV + 1], d[MAXV + 1], f[MAXV + 1];
    int u;
    DFS(G, color, pi, d, f);

    printf("\n");
    for (u = 1; u <= G->n_vertex; u++)
    {
        if (color[u] == BLACK)
        {
            printf("color[%d] = BLACK\n", u);
        }
        if (color[u] == GRAY)
        {
            printf("color[%d] = GRAY\n", u);
        }
        if (color[u] == WHITE)
        {
            printf("color[%d] = WHITE\n", u);
        }
    }
    printf("\n");

    for (u = 1; u <= G->n_vertex; u++)
    {
        if (pi[u] == NIL)
        {
            printf("pi[%d] = NIL\n", u);
        }
        else
        {
            printf("pi[%d] = %d\n", u, pi[u]);
        }
    }
    printf("\n");
    for (u = 1; u <= G->n_vertex; u++)
    {
        printf("d[%d], f[%d] = (%d, %d)\n", u, u, d[u], f[u]);
    }
}
int main()
{
    int vertices, edges;
    struct graph *G;

    while (scanf("%d %d", &vertices, &edges) != EOF)
    {
        G = ReadGraph(vertices, edges);
        PrintGraph(G);
        solver(G);
        G = DeleteGraph(G);
        PrintGraph(G);
    }
    return 0;
}