#include <stdio.h>
#define MAX 100

typedef struct
{
  int tokens[MAX];
  int front, rear;
} RideQueue;

// Initialize the queue
void initQueue(RideQueue *q)
{
  q->front = q->rear = -1;
}

// Check if queue is empty
int isEmpty(RideQueue *q)
{
  return q->front == -1;
}

// Check if queue is full
int isFull(RideQueue *q)
{
  return (q->rear + 1) % MAX == q->front;
}

// Add a person to the queue
void enqueue(RideQueue *q, int token)
{
  if (isFull(q))
  {
    printf("Queue is full! Cannot add person %d\n", token);
    return;
  }

  if (isEmpty(q))
    q->front = 0;

  q->rear = (q->rear + 1) % MAX;
  q->tokens[q->rear] = token;
  printf("Person %d joined the line.\n", token);
}

// Serve the person and move them back to the queue
int serveAndRejoin(RideQueue *q)
{
  if (isEmpty(q))
  {
    printf("No one in the line!\n");
    return -1;
  }

  int served = q->tokens[q->front];

  // If only one person
  if (q->front == q->rear)
  {
    q->front = q->rear = -1;
    enqueue(q, served); // rejoin immediately
  }
  else
  {
    q->front = (q->front + 1) % MAX;
    enqueue(q, served); // rejoin immediately
  }

  printf("Person %d was served and rejoined the queue.\n", served);
  return served;
}

// Peek the first person in line
int peek(RideQueue *q)
{
  if (isEmpty(q))
  {
    printf("No one is waiting!\n");
    return -1;
  }

  return q->tokens[q->front];
}

// Display all persons in queue
void display(RideQueue *q)
{
  if (isEmpty(q))
  {
    printf("Queue is empty!\n");
    return;
  }

  printf("People in line (oldest to latest): ");
  int i = q->front;
  while (1)
  {
    printf("%d ", q->tokens[i]);
    if (i == q->rear)
      break;
    i = (i + 1) % MAX;
  }
  printf("\n");
}

// Main function to demonstrate operations
int main()
{
  RideQueue q;
  initQueue(&q);

  enqueue(&q, 101);
  enqueue(&q, 102);
  enqueue(&q, 103);

  display(&q);

  serveAndRejoin(&q);
  display(&q);

  printf("Next person in line: %d\n", peek(&q));

  return 0;
}
