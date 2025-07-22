#include <stdio.h>
#define SIZE 50

typedef struct
{
    int arr[SIZE];
    int top;
}Stack;

void push(Stack *s, int value){
    if (s->top == SIZE - 1)
    {
        printf("Stack Overflow");
    }else{
        s->top++;
        s->arr[s->top] = value;
    }
    
}

void display(Stack *s){
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d", s->arr[i]);
        printf("\n");
    }

    
}

int main(){
    Stack s;
    s.top = -1;

    push(&s, 18);
    push(&s, 12);
    push(&s, 100);
    push(&s, 1134);
    push(&s, 112772);
    display(&s);
    

    return 0;
}