#include "node.c"
#define SIZE 2000000

typedef struct queue_t
{
    Node *front;
    Node *rear;
} Queue;

Queue *createQueue();
void enqueue(Queue *q, int);
int dequeue(Queue *q);
int isEmpty(Queue *q);
void printQueue(Queue *q);