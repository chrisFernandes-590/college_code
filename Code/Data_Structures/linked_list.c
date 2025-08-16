#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *create_node()
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node)
    {
        printf("\nMemory allocation failed");
        exit(1);
    }
    printf("Enter the value of data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    return new_node;
}

void insert_start(Node **head)
{
    Node *new_node = create_node();
    new_node->next = *head; // Points to the curr first node
    *head = new_node;       // Point to the new node
}

void insert_end(Node **head)
{
    Node *temp = *head;
    Node *new_node = create_node();
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

void insert_between(Node **head, int postion)
{
    Node *new_node = create_node();
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    Node *prev, *curr;
    prev = NULL;
    curr = *head;
    while (postion != 1)
    {
        prev = curr;
        curr = curr->next;
        postion--;
    }
    prev->next = new_node;
    new_node->next = curr;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    Node *head = NULL; // Empty List
    insert_start(&head);
    insert_end(&head);
    insert_between(&head, 2);
    insert_between(&head, 3);

    display(head);
    return 0;
}