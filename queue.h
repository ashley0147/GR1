#define SIZE 1000

typedef struct queue_t
{
    int items[SIZE];
    int front;
    int rear;
} Queue;

Queue *createQueue();
void enqueue(Queue *q, int);
int dequeue(Queue *q);
void display(Queue *q);
int isEmpty(Queue *q);
void printQueue(Queue *q);