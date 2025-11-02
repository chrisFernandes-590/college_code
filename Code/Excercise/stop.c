#include <stdio.h>

typedef struct Node
{
  int stop_ID;
  struct Node *next;
} Node;

Node *head = NULL;

Node *createNode(int id)
{
  Node *new = (Node *)malloc(sizeof(Node));
  new->stop_ID = id;
  new->next = NULL;
  return new;
}

void addAtBeginning(int id)
{
  Node *new = createNode(id);
  new->next = head;
  head = new;
}

void removeLast(int id)
{
  if (head == NULL)
    return;
  if (head->next == NULL)
  {
    free(head);
    head = NULL;
    return;
  }
  Node *temp = head;
  while (temp->next->next != NULL)
  {
    temp = temp->next;
  }
  free(temp->next);
  temp->next = NULL;
}

int changeStopID(int old_ID, int new_ID)
{
  if (head == NULL)
    return;
  Node *temp = head;
  while (temp != NULL)
  {
    if (temp->stop_ID == old_ID)
    {
      temp->stop_ID = new_ID;
      return 1;
    }
    temp = temp->next;
  }
  return 0;
}

int main()
{
  return 0;
}