#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *head = NULL;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBegin(int data)
{
    Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtEnd(int data)
{
    Node *newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPos(int data, int pos)
{
    if (pos == 1)
    {
        insertAtBegin(data);
        return;
    }
    Node *newNode = createNode(data);
    Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL)
        return;
    newNode->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteBegin()
{
    if (head == NULL)
        return;
    Node *temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
}

void deleteEnd()
{
    if (head == NULL)
        return;
    Node *temp = head;
    if (temp->next == NULL)
    {
        head = NULL;
        free(temp);
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
}

void deleteAtPos(int pos)
{
    if (head == NULL)
        return;
    if (pos == 1)
    {
        deleteBegin();
        return;
    }
    Node *temp = head;
    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL)
        return;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    free(temp);
}

void traverseForward()
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void traverseBackward()
{
    if (head == NULL)
        return;
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main()
{
    insertAtBegin(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtPos(15, 2);
    traverseForward();
    traverseBackward();
    deleteBegin();
    deleteEnd();
    deleteAtPos(2);
    traverseForward();
    return 0;
}
