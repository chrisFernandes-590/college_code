#include <stdio.h>
#define MAX 10

typedef struct
{
  int arr[MAX];
  int front, rear;
} Deque;

void initDeque(Deque *d)
{
  d->front = d->rear = -1;
}

int isEmpty(Deque *d)
{
  return d->front == -1;
}

int isFull(Deque *d)
{
  return (d->front == 0 && d->rear == MAX - 1) || (d->front == d->rear + 1);
}

void attachFront(Deque *d, int data)
{
  if (isFull(d))
    return;

  if (isEmpty(d))
  {
    d->front = d->rear = 0;
  }
  else if (d->front == 0)
  {
    d->front = MAX - 1;
  }
  else
  {
    d->front--;
  }

  d->arr[d->front] = data;
}

void attachRear(Deque *d, int data)
{
  if (isFull(d))
    return;
  if (isEmpty(d))
  {
    d->front = d->rear = 0;
  }
  else if (d->rear == MAX - 1)
  {
    d->rear = 0;
  }
  else
  {
    d->rear++;
  }

  d->arr[d->rear] = data;
}

// detachFront
int detachFront(Deque *d)
{
  if (isEmpty(d))
    return -1;
  int id = d->arr[d->front];
  if (d->front == d->rear)
  {
    d->front = d->rear = -1;
  }
  else if (d->front == MAX - 1)
  {
    d->front = 0;
  }
  else
  {
    d->front++;
  }
  return id;
}

int detachRear(Deque *d)
{
  if (isEmpty(d))
    return -1;
  int id = d->arr[d->rear];
  if (d->front == d->rear)
  {
    d->front = d->rear = -1;
  }
  else if (d->rear == 0)
  {
    d->rear = MAX - 1;
  }
  else
  {
    d->rear--;
  }
  return id;
}

void modifyFront(Deque *d, int newID)
{
  if (isEmpty(d))
    return;
  d->arr[d->front] = newID;
}

void modifyRear(Deque *d, int newID)
{
  if (isEmpty(d))
    return;
  d->arr[d->rear] = newID;
}

int getFront(Deque *d)
{
  if (isEmpty(d))
  {
    printf("Train is empty. No front compartment.\n");
    return -1;
  }
  return d->arr[d->front];
}

// Peek at rear compartment
int getRear(Deque *d)
{
  if (isEmpty(d))
  {
    printf("Train is empty. No rear compartment.\n");
    return -1;
  }
  return d->arr[d->rear];
}

void displayTrain(Deque *t)
{
  if (isEmpty(t))
  {
    printf("Train is empty.\n");
    return;
  }

  printf("Train compartments (front to rear): ");
  int i = t->front;
  while (1)
  {
    printf("%d ", t->arr[i]);
    if (i == t->rear)
      break;
    i = (i + 1) % MAX;
  }
  printf("\n");
}

int main()
{
  Deque t;
  initDeque(&t);
  int choice, id;

  while (1)
  {
    printf("\n--- Train Compartment Arrangement ---\n");
    printf("1. Attach Front\n2. Attach Rear\n3. Detach Front\n4. Detach Rear\n");
    printf("5. Modify Front\n6. Modify Rear\n7. Get Front\n8. Get Rear\n");
    printf("9. Display Train\n10. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter Compartment ID: ");
      scanf("%d", &id);
      attachFront(&t, id);
      break;
    case 2:
      printf("Enter Compartment ID: ");
      scanf("%d", &id);
      attachRear(&t, id);
      break;
    case 3:
      detachFront(&t);
      break;
    case 4:
      detachRear(&t);
      break;
    case 5:
      printf("Enter new ID for front: ");
      scanf("%d", &id);
      modifyFront(&t, id);
      break;
    case 6:
      printf("Enter new ID for rear: ");
      scanf("%d", &id);
      modifyRear(&t, id);
      break;
    case 7:
      id = getFront(&t);
      if (id != -1)
        printf("Front Compartment ID: %d\n", id);
      break;
    case 8:
      id = getRear(&t);
      if (id != -1)
        printf("Rear Compartment ID: %d\n", id);
      break;
    case 9:
      displayTrain(&t);
      break;
    case 10:
      printf("Exiting...\n");
      return 0;
    default:
      printf("Invalid choice!\n");
    }
  }
  return 0;
}