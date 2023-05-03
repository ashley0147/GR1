#include <stdio.h>
#include "graph.h"
#include "vector.h"

Graph *createGraph(int numberOfVertice)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = numberOfVertice;
    graph->adjLists = (vector **)malloc(numberOfVertice * sizeof(vector *));
    graph->visited = (int *)malloc(numberOfVertice * sizeof(int));
    printf("init v");
    for (int i = 0; i < numberOfVertice; i++)
    {
        graph->adjLists[i] = create_vector();
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(Graph *graph, int src, int dest)
{
    printf("from %d to %d", src, dest);
    push_back(graph->adjLists[src], dest);
    // vector_pushback(graph->adjLists[dest], src);
}

// void bfs(Graph *graph, int startVertex)
// {
//     vector *q = create_vector();
//     graph->visited[startVertex] = 1;
//     vector_pushback(q, startVertex);
//     int currentVertext = startVertex;
//     int count = 0;
//     while (q->total != 0)
//     {
//         // printQueue(q);
//         int currentVertext = (int)vector_front(q);
//         printf("Visited %d\n", currentVertext);
//         // get list of adjacent vertices
//         vector *temp = graph->adjLists[currentVertext];

//         for (int i = 0; i < temp->total; i++)
//         {
//             int adjVertex = vector_get(temp, i);
//             if (graph->visited[adjVertex] == 0)
//             {
//                 graph->visited[adjVertex] = 1;
//                 vector_pushback(q, adjVertex);
//                 // printf("enqueue %d\n", adjVertex);
//             }
//         }
//         // free(temp);
//     }
//     printf("Traversed all nodes have connection to %d", startVertex);
// }

// void dfs(Graph *g, int v)
// {
//     Node *temp = g->adjLists[v];
//     g->visited[v] = 1;
//     printf("Visited %d \n", v);
//     while (temp != NULL)
//     {
//         int adjVertex = temp->vertex;
//         if (g->visited[adjVertex] == 0)
//         {
//             dfs(g, adjVertex);
//         }
//         temp = temp->next;
//     }
// }

// void dfsAll(Graph *g)
// {
//     for (int i = 0; i < g->numVertices; i++)
//     {
//         if (g->visited[i] == 0)
//         {
//             dfs(g, i);
//         }
//     }
// }
