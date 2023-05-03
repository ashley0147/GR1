#ifndef NODE_H
#define NODE_H

typedef struct node_t
{
    int vertex;
    struct node_t *next;
} Node;

Node *createNode(int vertex);

#endif