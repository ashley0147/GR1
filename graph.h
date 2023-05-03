#include "vector.h"
typedef struct graph_t
{
    int numVertices;
    vector **adjLists;
    int *visited;
} Graph;

Graph *createGraph(int verticeNumber);
void addEdge(Graph *graph, int src, int dest);
void bfs(Graph *graph, int startVertex);
void dfs(Graph *g, int v);
void dfsAll(Graph *g);