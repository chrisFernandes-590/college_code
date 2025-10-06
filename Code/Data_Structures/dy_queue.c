#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

void enqueue(int x)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = x;
    n->next = NULL;
    if (!rear)
    {
        front = rear = n;
        return;
    }
    rear->next = n;
    rear = n;
}

int dequeue()
{
    if (!front)
        return -1;
    Node *t = front;
    int x = t->data;
    front = front->next;
    if (!front)
        rear = NULL;
    free(t);
    return x;
}

void display()
{
    Node *t = front;
    while (t)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    printf("Dequeued: %d\n", dequeue());
    display();
    return 0;
}
