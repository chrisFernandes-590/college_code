#include <stdio.h>
#define SIZE 100

struct TwoStacks
{
    int arr[SIZE];
    int top1;
    int top2;
};


void initializeStacks(struct TwoStacks *ts){
    ts->top1 = -1;
    ts->top2 = SIZE;
}

void push(struct TwoStacks *ts, int value, int stackNumber){
    if (ts->top1 + 1 == ts->top2)
    {
        printf("Stack Overflow\n");
    }
    if(stackNumber == 1){
        ts->top1++;
        ts->arr[ts->top1] = value;
    }
    if(stackNumber == 2){
        ts->top2--;
        ts->arr[ts->top2] = value;
    }else{
        printf("Invalid Stack number!\n");
    }
    
}

int pop(struct TwoStacks *ts, int stackNumber){
    if(stackNumber == 1){
        if(ts->top1 == -1){
            printf("Stack Underflow\n");
            return -1;
        }
        int popped = ts->arr[ts->top1];
        ts->top1--;
        return popped;
    }
    if(stackNumber == 2){
        if(ts->top2 == SIZE){
            printf("Stack Underflow\n");
            return -1;
        }
        int popped = ts->arr[ts->top2];
        ts->top2++;
        return popped;
    }else{
        printf("Invalid Stack number When popped!\n");
        return -1;
    }

}

int main(){
    struct TwoStacks ts;
    initializeStacks(&ts);

    push(&ts, 10, 1);
    push(&ts, 20, 1);
    push(&ts, 30, 2);
    push(&ts, 40, 2);

    printf("Popped from Stack 1: %d\n", pop(&ts, 1)); // 20
    printf("Popped from Stack 2: %d\n", pop(&ts, 2)); // 40
    printf("Popped from Stack 1: %d\n", pop(&ts, 1)); // 10
    printf("Popped from Stack 2: %d\n", pop(&ts, 2)); // 30
    return 0;
}