#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct Node
{
  int key;
  struct Node *next;
} Node;

Node *hashTable[SIZE];

int hash(int key)
{
  return key % SIZE;
}

void insert(int key)
{
  int index = hash(key);
  Node *new = malloc(sizeof(Node));
  new->key = key;
  new->next = hashTable[index];
  hashTable[index] = new;
}

int search(int key)
{
  int index = hash(key);
  Node *temp = hashTable[index];
  while (temp)
  {
    if (temp->key == key)
      return 1;
    temp = temp->next;
  }
  return 0;
}

void display()
{
  for (int i = 0; i < SIZE; i++)
  {
    Node *temp = hashTable[i];
    printf("%d: ", i);
    while (temp)
    {
      printf("%d -> ", temp->key);
      temp = temp->next;
    }
    printf("NULL\n");
  }
}

int main()
{
  insert(15);
  insert(25);
  insert(35);
  insert(5);
  display();
  printf("Search 25: %s\n", search(25) ? "Found" : "Not Found");
  printf("Search 100: %s\n", search(100) ? "Found" : "Not Found");
  return 0;
  return 0;
}