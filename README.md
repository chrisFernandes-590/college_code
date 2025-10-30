# College code

- Feel free to contribute to it and make sure to give a star to the repo 😉

```s
#include <stdio.h>
#define MAX 100

typedef struct {
  int arr[MAX];
  int top;
}Stack;

void initStack(Stack *s)
{
  s->top = -1;
}

// Stack has layers ? true : false
int isEmpty(Stack *s)
{
  return s->top == -1;
}

int isFull(Stack *s)
{
  return s->top == MAX - 1;
}

void display(Stack *s)
{
  if (isEmpty(s))
  {
    printf("\nStack has no layers");
    return;
  }
  for (int i = s->top; i >= 0; i--)
  {
    printf("%d\n", s->layers[i]);
  }
}

int main(){
  return 0;
}

```