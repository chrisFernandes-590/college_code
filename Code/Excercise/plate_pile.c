#include <stdio.h>
#define MAX 100

typedef struct
{
  int top;
  int plates[MAX];
} PlatePile;

void initPile(PlatePile *p)
{
  p->top = -1;
}

// Check if the pile is empty
int isEmpty(PlatePile *p)
{
  return p->top == -1;
}

// Check if the pile is full
int isFull(PlatePile *p)
{
  return p->top == MAX - 1;
}

void addPlate(PlatePile *p, int plate_number)
{
  if (isFull(p))
  {
    printf("Pile is full! Cannot add more plates.\n");
    return;
  }
  p->plates[++p->top] = plate_number;
  printf("Added plate number %d to the pile.\n", plate_number);
}

int removePlate(PlatePile *p)
{
  if (isEmpty(p))
  {
    printf("Pile is empty! No plate to remove.\n");
    return -1;
  }
  int removed = p->plates[p->top--];
  printf("Removed plate number %d from the pile.\n", removed);
  return removed;
}

void modifyPlate(PlatePile *p, int new_plate_num)
{
  if (isEmpty(p))
  {
    printf("Pile is empty! No plate to remove.\n");
    return;
  }
  p->plates[p->top] = new_plate_num;
}

int viewTopPlate(PlatePile *p)
{
  if (isEmpty(p))
  {
    printf("Pile is empty! No plate to remove.\n");
    return -1;
  }
  printf("%d", p->plates[p->top]);
  return p->plates[p->top];
}

void displayPile(PlatePile *p)
{
  if (isEmpty(p))
  {
    printf("Pile is empty!\n");
    return;
  }

  printf("Plates in the pile (top to bottom):\n");
  for (int i = p->top; i >= 0; i--)
  {
    printf("%d\n", p->plates[i]);
  }
}

int main()
{
  PlatePile pile;
  initPile(&pile);

  int choice, plate_number;

  while (1)
  {
    printf("\n--- Plate Pile Menu ---\n");
    printf("1. Add new plate\n");
    printf("2. Remove top plate\n");
    printf("3. Modify top plate\n");
    printf("4. View top plate\n");
    printf("5. Check if pile is empty\n");
    printf("6. Display all plates\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter plate number to add: ");
      scanf("%d", &plate_number);
      addPlate(&pile, plate_number);
      break;

    case 2:
      removePlate(&pile);
      break;

    case 3:
      printf("Enter new plate number for the top: ");
      scanf("%d", &plate_number);
      modifyPlate(&pile, plate_number);
      break;

    case 4:
      viewTopPlate(&pile);
      break;

    case 5:
      if (isEmpty(&pile))
        printf("Yes, the pile is empty.\n");
      else
        printf("No, the pile has plates.\n");
      break;

    case 6:
      displayPile(&pile);
      break;

    case 7:
      printf("Exiting program.\n");
      return 0;

    default:
      printf("Invalid choice! Try again.\n");
    }
  }

  return 0;
}