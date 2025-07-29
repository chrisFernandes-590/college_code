#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 100

typedef struct
{
    char arr[SIZE];
    int top;
} Stack;

void push(Stack *s, char value)
{
    if (s->top == SIZE - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        s->arr[++s->top] = value;
    }
}

char pop(Stack *s)
{
    if (s->top == -1)
    {
        printf("Stack Underflow\n");
        return '\0';
    }
    return s->arr[s->top--];
}

char stackTop(Stack *s)
{
    if (s->top == -1)
        return '\0';
    return s->arr[s->top];
}

void init_Stack(Stack *s)
{
    s->top = -1;
}

int is_empty(Stack *s)
{
    return s->top == -1;
}

int precedence(char element)
{
    if (element == '(')
        return 0;
    if (element == '^')
        return 3;
    if (element == '*' || element == '/')
        return 2;
    if (element == '+' || element == '-')
        return 1;
    return -1;
}

void getInfixExpression(char *infix)
{
    printf("Enter the infix expression: ");
    fgets(infix, SIZE, stdin);
    size_t len = strlen(infix);
    if (len > 0 && infix[len - 1] == '\n')
    {
        infix[len - 1] = '\0';
    }
}

void display(Stack *s)
{
    for (int i = 0; i <= s->top; i++)
    {
        printf("%c", s->arr[i]);
    }
    printf("\n");
}

int main()
{
    Stack operators, postfix;
    init_Stack(&operators);
    init_Stack(&postfix);

    char infix[SIZE];
    getInfixExpression(infix);

    for (int i = 0; infix[i] != '\0'; i++)
    {
        char current_char = infix[i];

        if (isalnum(current_char))
        {
            push(&postfix, current_char);
        }
        else if (current_char == '(')
        {
            push(&operators, current_char);
        }
        else if (current_char == ')')
        {
            while (!is_empty(&operators) && stackTop(&operators) != '(')
            {
                push(&postfix, pop(&operators));
            }
            if (!is_empty(&operators) && stackTop(&operators) == '(')
            {
                pop(&operators);
            }
            else
            {
                printf("Mismatched parentheses\n");
                return 1;
            }
        }
        else
        {
            while (!is_empty(&operators) && precedence(current_char) <= precedence(stackTop(&operators)))
            {
                push(&postfix, pop(&operators));
            }
            push(&operators, current_char);
        }
    }

    while (!is_empty(&operators))
    {
        if (stackTop(&operators) == '(')
        {
            printf("Mismatched parentheses\n");
            return 1;
        }
        push(&postfix, pop(&operators));
    }

    printf("Postfix expression: ");
    display(&postfix);
    return 0;
}
