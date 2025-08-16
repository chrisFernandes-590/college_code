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

void insert_between(Node **head, int position)
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
    while (position != 1)
    {
        prev = curr;
        curr = curr->next;
        position--;
    }
    prev->next = new_node;
    new_node->next = curr;
}

void delete_node(Node **head, int position)
{
    if (*head == NULL)
    {
        printf("The list is empty\n");
        return;
    }

    Node *curr = *head;
    Node *prev = NULL;

    if (position == 1)
    {
        *head = curr->next;
        free(curr);
        return;
    }

    while (position > 1 && curr != NULL)
    {
        prev = curr;
        curr = curr->next;
        position--;
    }

    if (curr == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    prev->next = curr->next;
    free(curr);
}

int count_nodes(Node **head)
{
    int count = 0;
    if (*head == NULL)
    {
        printf("List is empty!");
        return count;
    }

    Node *tmp = *head;
    while (tmp != NULL)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
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

void remove_duplicates(Node **head)
{
    if (*head == NULL)
        return;

    Node *curr = *head;
    while (curr != NULL)
    {
        Node *prev = curr;
        Node *tmp = curr->next;

        while (tmp != NULL)
        {
            if (tmp->data == curr->data)
            {
                prev->next = tmp->next;
                free(tmp);
                tmp = prev->next;
            }
            else
            {
                prev = tmp;
                tmp = tmp->next;
            }
        }
        curr = curr->next;
    }
}
int main()
{
    Node *head = NULL; // Empty List
    insert_start(&head);
    insert_end(&head);
    insert_end(&head);
    insert_end(&head);
    insert_end(&head);

    display(head);

    delete_node(&head, 4);
    remove_duplicates(&head);
    display(head);

    int count = count_nodes(&head);
    printf("Total nodes: %d\n", count);
    return 0;
}