#include <stdio.h>
#define MAX 100

typedef struct
{
  int layers[MAX];
  int top;
} Cake;

void initStack(Cake *c)
{
  c->top = -1;
}

// cake has layers ? true : false
int isEmpty(Cake *c)
{
  return c->top == -1;
}

int isFull(Cake *c)
{
  return c->top == MAX - 1;
}

// Add new cake layer
void addNewLayer(Cake *c, int thickness)
{
  if (isFull(c))
  {
    printf("\nCake Full! Cannot add more layers");
    return;
  }
  c->layers[++c->top] = thickness;
  printf("\nAdded new layer");
}

// remove last added layer
int removeLayer(Cake *c)
{
  if (isEmpty(c))
  {
    printf("\nCake has no layers! Cannot remove layer");
    return -1;
  }
  int removed = c->layers[c->top];
  c->top--;
  return removed;
}

// change thickness of top layer
// change thickness of top layer without removing it
void modifyThickness(Cake *c, int newThickness)
{
  if (isEmpty(c))
  {
    printf("\nThe cake has no layers! Cannot remove layers");
    return;
  }
  c->layers[c->top] = newThickness;
}

// print all the layers
void display(Cake *c)
{
  if (isEmpty(c))
  {
    printf("\nCake has no layers");
    return;
  }
  for (int i = c->top; i >= 0; i--)
  {
    printf("\nLayer %d: %d\n", c->top - i + 1, c->layers[i]);
  }
}

int main()
{
  Cake cake;
  initStack(&cake);
  int choice, thickness;

  while (1)
  {
    printf("\n--- Cake Layer Menu ---\n");
    printf("1. Add Layer\n");
    printf("2. Remove Top Layer\n");
    printf("3. Modify Top Layer\n");
    printf("4. Display Cake\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter thickness of new layer: ");
      scanf("%d", &thickness);
      addNewLayer(&cake, thickness);
      break;
    case 2:
      removeLayer(&cake);
      break;
    case 3:
      printf("Enter new thickness for top layer: ");
      scanf("%d", &thickness);
      modifyThickness(&cake, thickness);
      break;
    case 4:
      display(&cake);
      break;
    case 5:
      printf("Exiting program.\n");
      return 0;
    default:
      printf("Invalid choice! Try again.\n");
    }
  }
  return 0;
}