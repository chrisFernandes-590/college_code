#include <stdio.h>
#define SIZE 100

typedef struct 
{
    int arr[SIZE];
    int f, r;
}Queue;

void initQueue(Queue *q){
    q->f = 0;
    q->r = -1;
}

void enqueue(Queue *q, int value){
    if (q->r == SIZE - 1)
    {
        printf("\nQueue Overflow");
        return;
    }else {
        q->r++;
        q->arr[q->r] = value;
        return;
    }    
}

int dequeue(Queue *q){
    if(q->r < q->f){
        printf("Underflow");
        return -1;
    }
    int element = q->arr[q->f];
    q->f++;
    return element;
}

void display(Queue *q){
    if (q->r < q->f)
    {
        printf("Queue is empty");
        return;
    }
    for (int i = q->f; i <= q->r; i++)
    {
        printf("%d, ", q->arr[i]);
    }
    
    
}

int main(){
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);
    enqueue(&q, 70);

    display(&q);

    printf("\n");

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    display(&q);

    return 0;
}