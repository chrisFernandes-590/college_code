#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

void new_node(node *n)
{
    node *newNode = (node *)malloc(sizeof(node *));
    printf("\nEnter the data: ");
    scanf("%d", n->data);
    newNode->next = NULL;
}

void insert_end(node *n, int value, node *head)
{
    if (head->next == NULL)
    {
        new_node(n);
        head->next = new_node;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
        }
    }
}

int main()
{
    node *head;
    head->next = NULL;

    return 0;
}