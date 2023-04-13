#include <stdio.h>
#include "graph.h"

Node *createNode(int vertex)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

Graph *createGraph(int verticeNumber)
{
    Graph *graph = malloc(sizeof(Graph));
    graph->numVertices = verticeNumber;
    graph->adjLists = malloc(verticeNumber * sizeof(Node *));
    graph->visited = malloc(vertices * sizeof(int));

    for (int i = 0; i < verticeNumber; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(Graph *graph, int src, int dest)
{
    Node *newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjLists[src] = newNode;
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void bfs(Graph *graph, int startVertex)
{

    // create queue for holding visited vertex
    Queue *q = createQueue();
    // set startVertex to visited ( 1 = visited / 0 = not visited)
    graph->visited[startVertex] = 1;
    // enqueue visited vertex to the queue, in this case startVertex has been visited
    enqueue(q, startVertex);

    // loop until queue is empty
    while (!isEmpty(q))
    {
        printQueue(q);
        int currentVertext = dequeue(q);
        printf("Visited %d\n", currentVertext);
        // get list of adjacent vertices
        Node *temp = graph->adjLists[currentVertext];

        while (temp)
        {
            int adjVertex = temp->vertex;
            if (graph->visited[adjVertex] == 0)
            {
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}
