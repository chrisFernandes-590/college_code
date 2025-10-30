#include <stdio.h>
#define MAX 100

typedef struct
{
  int arr[MAX];
  int top;
} Stack;

void initStack(Stack *s)
{
  s->top = -1;
}

int isEmpty(Stack *s)
{
  return s->top == -1;
}

int isFull(Stack *s)
{
  return s->top == MAX - 1;
}

// perform action (action code) => stack
void performAction(Stack *s, int action_code)
{
  if (isFull(s))
  {
    printf("No more actions can be performed! \n");
    return;
  }
  s->arr[++s->top] = action_code;
}

// Undo() stack pop
void undo(Stack *s)
{
  if (isEmpty(s))
  {
    printf("No recent actions\n");
    return;
  }
  printf("Action Undoed: %d", s->arr[s->top--]);
}

void modifyLastAction(Stack *s, int new_action_code)
{
  if (isEmpty(s))
  {
    printf("No recent actions\n");
    return;
  }
  s->arr[s->top] = new_action_code;
  printf("Modified last action");
}

int getLastAction(Stack *s)
{
  if (isEmpty(s))
  {
    printf("No recent actions\n");
    return -1;
  }
  return s->arr[s->top];
}

void displayHistory(Stack *s)
{
  if (isEmpty(s))
  {
    printf("No recent actions\n");
    return;
  }
  for (int i = s->top; i >= 0; i--)
  {
    printf("\nAction: %d\n", s->arr[i]);
  }
}

int main()
{
  Stack s;
  initStack(&s);

  performAction(&s, 101);
  performAction(&s, 202);
  performAction(&s, 303);

  displayHistory(&s);

  modifyLastAction(&s, 404);
  printf("Last action: %d\n", getLastAction(&s));
  displayHistory(&s);

  undo(&s);
  displayHistory(&s);

  return 0;
}