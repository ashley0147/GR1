#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "graph.c"

Graph *readFile(const char *filename)
{
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("Can not open %s", filename);
        return 0;
    }

    char line[100];
    char w1[8], w2[8];
    int edges, nodes;
    int f, t;
    for (int i = 0; i < 2; i++)
    {
        fgets(line, 100, fptr);
        printf("%s", line);
    }

    fscanf(fptr, "# %s %d %s %d\n", w1, &nodes, w2, &edges);
    Graph *newGraph = createGraph(nodes);
    // printf("nodes: %d edges: %d\n", nodes, edges);
    fgets(line, 100, fptr);
    // printf("%s\n", line);
    while (!feof(fptr))
    {
        fscanf(fptr, "%d %d\n", &f, &t);
        addEdge(newGraph, f, t);
        // printf("from: %d to: %d\n", f, t);
    }

    return newGraph;
}

int main()
{

    Graph *newGraph = readFile("./data/roadNet-CA.txt");

    // bfs(newGraph, 0);

    // dfs(newGraph, 0);
    // dfsAll(newGraph);
    return 0;
}