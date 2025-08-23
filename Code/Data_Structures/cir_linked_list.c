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
    if (*head == NULL)
    {
        new_node->next = *head;
        return;
    }
    new_node->next = *head; // Points to the curr first node
    *head = new_node;       // Point to the new node
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

    display(head);
    return 0;
}