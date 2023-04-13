#include <stdio.h>
#include "queue.h"

Queue *createQueue()
{
  Queue *q = malloc(sizeof(queue));
  q->front = -1;
  q->rear = -1;
  return q;
}

int isEmpty(Queue *q)
{
  if (q->rear == -1)
    return 1;
  else
    return 0;
}

void enqueue(Queue *q, int value)
{
  if (q->rear == SIZE - 1)
    printf("\nQueue is Full!!");
  else
  {
    if (q->front == -1)
      q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
  }
}

int dequeue(Queue *q)
{
  int item;
  if (isEmpty(q))
  {
    printf("Queue is empty");
    item = -1;
  }
  else
  {
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear)
    {
      printf("Resetting queue ");
      q->front = q->rear = -1;
    }
  }
  return item;
}

void printQueue(Queue *q)
{
  int i = q->front;

  if (isEmpty(q))
  {
    printf("Queue is empty");
  }
  else
  {
    printf("\nQueue contains: \n");
    for (i = q->front; i < q->rear + 1; i++)
    {
      printf("%d ", q->items[i]);
    }
  }
}