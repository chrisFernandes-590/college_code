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
        printf("Stack Overflow\n");
    } else {
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

int pop(Stack *s){
    if(s->top == -1){
        printf("Stack Underflow\n");
    }
    int top_element = s->arr[s->top];
    s->top--;
    return top_element;
}

int stackTop(Stack *s){
    if(s->top == -1){
        printf("Stack is Empty");
        return -404;
    }
    int top_element = s->arr[s->top];
    return top_element;
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
    printf("\n");
    pop(&s);
    pop(&s);
    push(&s, 112772);
    pop(&s);
    display(&s);
    printf("\nTop Element: %d\n", stackTop(&s));
    

    return 0;
}