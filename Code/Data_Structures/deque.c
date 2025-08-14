#include <stdio.h>
#define SIZE 100

typedef struct
{
    int arr[SIZE];
    int f, r;
} Deque;

void insert_front(Deque *dq, int x)
{
    if ((dq->f == 0 && dq->r == SIZE - 1) || (dq->f == dq->r + 1))
    {
        printf("Full\n");
        return;
    }
    if (dq->f == -1)
    {
        dq->f = dq->r = 0;
    }
    else if (dq->f == 0)
    {
        dq->f = SIZE - 1;
    }
    else
    {
        dq->f--;
    }
    dq->arr[dq->f] = x;
}

void insert_rear(Deque *dq, int x)
{
    if ((dq->f == 0 && dq->r == SIZE - 1) || (dq->f == dq->r + 1))
    {
        printf("Full\n");
        return;
    }
    if (dq->f == -1)
    {
        dq->f = dq->r = 0;
    }
    else if (dq->r == SIZE - 1)
    {
        dq->r = 0;
    }
    else
    {
        dq->r++;
    }
    dq->arr[dq->r] = x;
}

void remove_front(Deque *dq)
{
    if (dq->f == -1)
    {
        printf("Empty\n");
        return;
    }
    if (dq->f == dq->r)
    {
        dq->f = dq->r = -1;
    }
    else if (dq->f == SIZE - 1)
    {
        dq->f = 0;
    }
    else
    {
        dq->f++;
    }
}

void remove_rear(Deque *dq)
{
    if (dq->f == -1)
    {
        printf("Empty\n");
        return;
    }
    if (dq->f == dq->r)
    {
        dq->f = dq->r = -1;
    }
    else if (dq->r == 0)
    {
        dq->r = SIZE - 1;
    }
    else
    {
        dq->r--;
    }
}

void display(Deque *dq)
{
    if (dq->f == -1)
    {
        printf("Empty\n");
        return;
    }
    int i = dq->f;
    while (1)
    {
        printf("%d ", dq->arr[i]);
        if (i == dq->r)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

void isfull(Deque *dq)
{
    if ((dq->f == 0 && dq->r == SIZE - 1) || (dq->f == dq->r + 1))
        printf("Full\n");
    else
        printf("Not full\n");
}

void isempty(Deque *dq)
{
    if (dq->f == -1)
        printf("Empty\n");
    else
        printf("Not empty\n");
}

int main()
{
    Deque dq;
    dq.f = dq.r = -1;
    int ch, x;
    printf("\n1.Insert front \n2.Insert rear \n3.Remove front \n4.Remove rear \n5.Display \n6.isFull? \n7.isEmpty? \n8.EXIT\n");
    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the value: ");
            scanf("%d", &x);
            insert_front(&dq, x);
            printf("\nAdded %d at the start", x);
            break;
        case 2:
            printf("\nEnter the value: ");
            scanf("%d", &x);
            insert_rear(&dq, x);
            printf("\nAdded %d at the end", x);
            break;
        case 3:
            remove_front(&dq);
            break;
        case 4:
            remove_rear(&dq);
            break;
        case 5:
            display(&dq);
            break;
        case 6:
            isfull(&dq);
            break;
        case 7:
            isempty(&dq);
            break;
        case 8:
            return 0;
        }
    }
}
