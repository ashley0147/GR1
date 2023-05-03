#include <stdio.h>
#include "queue.h"

Queue *createQueue()
{
  Queue *q = malloc(sizeof(Queue));
  q->front = NULL;
  q->rear = NULL;
  return q;
}

int isEmpty(Queue *q)
{
  if (q->front == NULL)
    return 1;
  else
    return 0;
}

void enqueue(Queue *q, int value)
{
  Node *newNode;
  newNode = (Node *)malloc(sizeof(Node));
  newNode->vertex = value;
  newNode->next = NULL;
  if ((q->front == NULL))
  {
    q->front = q->rear = newNode;
  }
  else
  {
    q->rear->next = newNode;
    q->rear = newNode;
  }
}

int dequeue(Queue *q)
{
  if (isEmpty(q))
  {
    printf("\nQueue is Empty");
    return -1;
  }
  else
  {
    Node *temp = q->front;
    q->front = q->front->next;
    int value = temp->vertex;
    free(temp);
    // printf("value %d", value);
    return value;
  }
}

void printQueue(Queue *q)
{
  Node *temp;
  if ((q->front == NULL) && (q->rear == NULL))
  {
    printf("\nQueue is Empty");
  }
  else
  {
    temp = q->front;
    while (temp)
    {
      printf(" %d ", temp->vertex);
      temp = temp->next;
    }
  }
  free(temp);
}