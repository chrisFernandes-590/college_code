#include <stdio.h>
#define SIZE 100

typedef struct
{
    int arr[SIZE];
    int top;
} Stack;

void init_stack(Stack *s)
{
    s->top = -1;
}

int is_empty(Stack *s)
{
    return s->top == -1;
}

void push(Stack *s, int value)
{
    if (s->top == SIZE - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        s->arr[++(s->top)] = value;
    }
}

int pop(Stack *s)
{
    if (is_empty(s))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

void enqueue(Stack *s1, int value)
{
    push(s1, value);
    printf("Enqueued %d\n", value);
}

int dequeue(Stack *s1, Stack *s2)
{
    if (is_empty(s2))
    {
        while (!is_empty(s1))
        {
            push(s2, pop(s1));
        }
    }
    if (is_empty(s2))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return pop(s2);
}

void display(Stack *s1, Stack *s2)
{
    // Copy stacks to temp variables to preserve original
    Stack temp1 = *s1;
    Stack temp2 = *s2;

    // Print s2 first (front of queue)
    for (int i = temp2.top; i >= 0; i--)
    {
        printf("%d ", temp2.arr[i]);
    }
    // Then print s1 in original order
    for (int i = 0; i <= temp1.top; i++)
    {
        printf("%d ", temp1.arr[i]);
    }
    printf("\n");
}

int main()
{
    Stack s1, s2;
    init_stack(&s1);
    init_stack(&s2);

    enqueue(&s1, 10);
    enqueue(&s1, 20);
    enqueue(&s1, 30);
    enqueue(&s1, 100);

    display(&s1, &s2);

    printf("Dequeued: %d\n", dequeue(&s1, &s2));
    display(&s1, &s2);

    return 0;
}
