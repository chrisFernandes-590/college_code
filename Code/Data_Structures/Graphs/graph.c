#include<stdio.h>

#define SIZE 5

typedef struct Stack{
    int arr[SIZE];
    int top;
}Stack;

typedef struct Queue{
    int arr[SIZE];
    int f, r;
}Queue;

// Initialize stack
void initStack(Stack *s){
    s->top = -1;
}

// Initialize queue
void initQueue(Queue *q){
    q->f = q->r = -1;
}

// Validation helpers
int isStackEmpty(Stack *s){
    return s->top == -1;
}
int isStackFull(Stack *s){
    return s->top == SIZE - 1;
}
int isQueueEmpty(Queue *q){
    return q->f == -1 && q->r == -1;
}
int isQueueFull(Queue *q){
    return q->r == SIZE - 1;
}

// Stack operations
void stackPush(Stack *s, int val){
    if(isStackFull(s)){
        printf("Stack is full \n");
        return;
    }
    s->arr[++s->top] = val;
}
void stackPop(Stack *s){
    if(isStackEmpty(s)){
        return;
    }
    s->top--;
}
int stackPeep(Stack *s){
    if(isStackEmpty(s)){
        return -1;
    }
    return s->arr[s->top];
}

// Queue operations
void queuePush(Queue *q, int val){
    if(isQueueFull(q)){
        printf("Queue is full \n");
        return;
    }
    if(isQueueEmpty(q)){
        q->f = q->r = 0;
    }
    else{
        q->r++;
    }
    q->arr[q->r] = val;
}
int queuePop(Queue *q){
    if(isQueueEmpty(q)){
        printf("Queue is empty \n");
        return -1;
    }

    int val = q->arr[q->f];

    if(q->f == q->r)    
        q->f = q->r = -1;
    else
        q->f++;

    return val;
}

// DFS (uses stack + backtracking)
void DFS(int start, int vis[], int adj[SIZE][SIZE], Stack *s){
    printf("DFS Traversal is as follows:\n");

    stackPush(s, start);
    vis[start] = 1;
    printf("%c ", start + 'A');  // print as character

    while(!isStackEmpty(s)){
        int stackTop = stackPeep(s);
        int neighbour = 0;

        for(int c = 0; c < SIZE; c++){
            if(adj[stackTop][c] == 1 && !vis[c]){
                vis[c] = 1;
                printf("%c ", c + 'A');
                stackPush(s, c);
                neighbour = 1;
                break;
            }
        }

        if(!neighbour)
            stackPop(s);
    }
    printf("\n");
}

// BFS (level by level using queue)
void BFS(int start, int vis[], int adj[SIZE][SIZE], Queue *q){
    printf("BFS Traversal is as follows:\n");

    queuePush(q, start);
    vis[start] = 1;
    printf("%c ", start + 'A'); // print as char

    while(!isQueueEmpty(q)){
        int val = queuePop(q);

        for(int c = 0; c < SIZE; c++){
            if(adj[val][c] == 1 && !vis[c]){
                vis[c] = 1;
                printf("%c ", c + 'A');
                queuePush(q, c);
            }
        }
    }
    printf("\n");
}

// Reset visited before traversal
void resetVis(int vis[]){
    for(int i = 0; i < SIZE; i++)
        vis[i] = 0;
}

int main(){
    Stack s;
    Queue q;

    initStack(&s);
    initQueue(&q);

    int vis[SIZE];
    int adj[SIZE][SIZE];
    int choice, start;

    printf("Please enter the adj matrix values (0/1):\n");
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            scanf("%d", &adj[i][j]);
        }
    }

    while(1){
        printf("\n1. DFS Traversal\n");
        printf("2. BFS Traversal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter start vertex (0-%d): ", SIZE-1);
                scanf("%d", &start);
                resetVis(vis);
                initStack(&s);
                DFS(start, vis, adj, &s);
                break;

            case 2:
                printf("Enter start vertex (0-%d): ", SIZE-1);
                scanf("%d", &start);
                resetVis(vis);
                initQueue(&q);
                BFS(start, vis, adj, &q);
                break;

            case 3:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
