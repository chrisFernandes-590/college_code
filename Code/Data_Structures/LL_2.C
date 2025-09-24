#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

Node *create_node()
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Enter the value of data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    return new_node;
}

void insert_start()
{
    Node *new_node = create_node();
    if (head == NULL)
    {
        head = new_node;
        head->next = head;
    }
    else
    {
        new_node->next = head->next;
        head->next = new_node;
    }
}

void insert_end()
{
    Node *new_node = create_node();
    if (head == NULL)
    {
        head = new_node;
        head->next = head;
    }
    {
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = head;
    }
}

void insert_pos()
{
    int pos, i;
    printf("Enter position: ");
    scanf("%d", &pos);
    Node *new_node = create_node();
    if (head == NULL)
    {
        head = new_node;
        head->next = head;
        return;
    }
    Node *temp = head->next;
    for (i = 1; i < pos - 1 && temp != head; i++)
        temp = temp->next;
    new_node->next = temp->next;
    temp->next = new_node;
    if (temp == head)
        head = new_node;
}

void delete_start()
{
    if (head == NULL)
        return;

    if (head->next == head) // only 1 node
    {
        free(head);
        head = NULL;
    }
    else
    {
        Node *temp = head;
        Node *last = head;

        // find the last node
        while (last->next != head)
            last = last->next;

        head = head->next; // move head to next node
        last->next = head; // fix circular link
        free(temp);
    }
}

void delete_end()
{
    if (head == NULL)
        return;
    Node *temp = head->next;
    if (head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }
    while (temp->next != head)
        temp = temp->next;
    temp->next = head->next;
    free(head);
    head = temp;
}

void delete_pos()
{
    if (head == NULL)
        return;
    int pos, i;
    printf("Enter position: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        delete_start();
        return;
    }
    Node *temp = head->next;
    for (i = 1; i < pos - 1 && temp->next != head->next; i++)
        temp = temp->next;
    Node *del = temp->next;
    temp->next = del->next;
    if (del == head)
        head = temp;
    free(del);
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    Node *temp = head->next;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head->next);
    printf("(back to start)\n");
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n1.Insert Begin\n2.Insert End\n3.Insert Position\n4.Delete End\n5.Delete Begin\n6.Delete Position\n7.Traverse\n8.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_start();
            break;
        case 2:
            insert_end();
            break;
        case 3:
            insert_pos();
            break;
        case 4:
            delete_end();
            break;
        case 5:
            delete_start();
            break;
        case 6:
            delete_pos();
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
