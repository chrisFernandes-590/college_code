#include <stdio.h>
#define SIZE 100

typedef struct
{
    int arr[SIZE];
    int f, r;
} Queue;

void initQueue(Queue *q)
{
    q->f = q->r = -1;
}

void displayQueue(Queue *q)
{
    if (q->f == -1 && q->r == -1)
    {
        printf("The Queue is empty");
        return;
    }

    for (int i = 0; i != q->r; i++)
    {
        printf("\n%d", q->arr[i]);
    }
}

void enqueue(Queue *q, int value)
{
    if (q->f == (q->r + 1) % SIZE)
    {
        printf("Queue Overflow");
        return;
    }
    if (q->f == -1 && q->r == -1)
    {
        q->f = q->r = 0;
        q->arr[q->r] = value;
        return;
    }
    q->arr[q->r] = value;
    q->r++;
}

int main()
{
    Queue q;
    initQueue(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    displayQueue(&q);
    return 0;
}