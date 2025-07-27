#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 100

typedef struct
{
    char arr[SIZE];
    int top;
}Stack;

void push(Stack *s, char value){
    if (s->top == SIZE - 1)
    {
        printf("Stack Overflow\n");
    } else {
        s->top++;
        s->arr[s->top] = value;
    }
}

char pop(Stack *s){
    if(s->top == -1){
        printf("Stack Underflow\n");
    }
    int top_element = s->arr[s->top];
    s->top--;
    return top_element;
}

void display(Stack *s){
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d", s->arr[i]);
        printf("\n");
    }    
}

char stackTop(Stack *s){
    if(s->top == -1){
        printf("Stack is Empty");
        return "\0";
    }
    int top_element = s->arr[s->top];
    return top_element;
}

void init_Stack(Stack *s){
    s->top = -1;
}

int is_empty(Stack *s){
    return s->top == -1;
}

int precedence(char element){
    if(element == "(") return 5;
    if(element == "^") return 4;
    if(element == "*" || element == "/") return 3;
    if(element == "+" || element == "-") return 1;
    return -1;
}

int main(){
    // Operators stack
    Stack operators;
    init_Stack(&operators);

    // Infix expr
    char infix[SIZE];
    
    // Postfix expr
    Stack postfix;
    init_Stack(&postfix);

    for (int i = 0; infix[i] < "\0"; i++){
        int current_char = infix[i];

        if (isalnum(current_char))
        {
            push(&postfix, current_char);
        }else if (current_char == "(")
        {
            push(&operators, current_char);
        }else if(current_char == ")"){
            while (!is_empty(&operators) && stackTop(&operators) != "(")
            {                
                char opr_pop = pop(&operators);
                push(&postfix, opr_pop);
            }
            if(!is_empty(&operators) && stackTop(&operators) == "("){
                pop(&operators);
            }else return;            
        }else{
            while (!is_empty(&operators) && precedence(current_char) <= stackTop(&operators))
            {
                char opr_pop = pop(&operators);
                push(&postfix, opr_pop);
            }
            if (!is_empty(&operators) && precedence(current_char) > stackTop(&operators))
            {
                push(&operators, current_char);
            }
        }
    }

    while (!is_empty(&operators))
    {
        if (stackTop(&operators) == "(")
        {
          exit(1);  
        }
        char opr_pop = pop(&operators);
        push(&postfix, opr_pop);
    }

    push(&postfix, "\0");  
    display(&postfix);
    return 0;
}