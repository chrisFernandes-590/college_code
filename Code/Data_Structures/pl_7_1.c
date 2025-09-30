#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int isCircular(Node *head)
{
    if (head == NULL)
        return 0;
    struct Node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }
    return (temp == head);
}

int main()
{
    Node *head = createNode(1);
    Node *second = createNode(2);
    Node *third = createNode(3);

    head->next = second;
    second->next = third;
    third->next = head;

    if (isCircular(head))
        printf("The linked list is circular\n"); // output
    else
        printf("The linked list is not circular\n");

    return 0;
}
