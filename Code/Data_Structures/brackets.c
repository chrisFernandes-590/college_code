#include <stdio.h>
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

int is_empty(Stack *s)
{
    return s->top == -1;
}

void init_Stack(Stack *s)
{
    s->top = -1;
}

void getInput(char *input)
{
    printf("Enter the statement to check weather it is well parethesized\n");
    fgets(input, SIZE, stdin);
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n')
    {
        input[len - 1] = '\0';
    }
}

int isMatchingPair(char open, char close)
{
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int isWellParenthesized(char *expr)
{
    Stack s;
    init_Stack(&s);

    for (int i = 0; expr[i] != '\0'; i++)
    {
        char currentChar = expr[i];

        if (currentChar == '(' || currentChar == '[' || currentChar == '{')
        {
            push(&s, currentChar);
        }
        else if (currentChar == ')' || currentChar == ']' || currentChar == '}')
        {
            if (is_empty(&s))
            {
                return 0;
            }
            char top = pop(&s);
            if (!isMatchingPair(top, currentChar))
                return 0;
        }
    }

    return is_empty(&s);
}

int main()
{
    char input[SIZE];
    getInput(input);

    if (isWellParenthesized(input))
    {
        printf("The Expression is well parenthesized\n");
    }
    else
    {
        printf("The Expression is not well parethesized\n");
    }

    return 0;
}