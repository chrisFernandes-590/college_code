#include <stdio.h>
#define SIZE 100

typedef struct 
{
    int arr[SIZE];
    int f, r;
}Queue;

void initQueue(Queue *q){
    q->f = -1;
    q->r = -1;
}

void enqueue(Queue *q, int value){
    if (q->f == (q->r + 1) % SIZE)
    {
        printf("\nQueue Overflow");
        return;
    }
    if(q->f == -1 && q->r == -1){
        q->f = q->r = 0;
        q->arr[q->r] = value;
    }else{
        q->r = (q->r + 1) % SIZE;
        q->arr[q->r] = value;
    }   
}

int dequeue(Queue *q){
    if(q->r == -1 && q->f == -1){
        printf("Underflow");
        return -1;
    }
    if(q->f == q->r){
        int ele = q->arr[q->f];
        q->f = q->r = -1;
        return ele;
    }else{
        int ele = q->arr[q->f];
        q->f = (q->f + 1) % SIZE;
        return ele; 
    }

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