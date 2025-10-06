#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *top = NULL;

void push(int x)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = x;
    n->next = top;
    top = n;
}

int pop()
{
    if (!top)
        return -1;
    Node *t = top;
    int x = t->data;
    top = top->next;
    free(t);
    return x;
}

void display()
{
    Node *t = top;
    while (t)
    {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main()
{
    push(10);
    push(20);
    push(30);
    display();
    printf("Popped: %d\n", pop());
    display();
    return 0;
}
