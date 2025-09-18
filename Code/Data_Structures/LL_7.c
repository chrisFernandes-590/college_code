#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *last = NULL;

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
    if (last == NULL)
    {
        last = new_node;
        last->next = last;
    }
    else
    {
        new_node->next = last->next;
        last->next = new_node;
    }
}

void insert_end()
{
    Node *new_node = create_node();
    if (last == NULL)
    {
        last = new_node;
        last->next = last;
    }
    else
    {
        new_node->next = last->next;
        last->next = new_node;
        last = new_node;
    }
}

void insert_pos()
{
    int pos, i;
    printf("Enter position: ");
    scanf("%d", &pos);
    Node *new_node = create_node();
    if (last == NULL)
    {
        last = new_node;
        last->next = last;
        return;
    }
    Node *temp = last->next;
    for (i = 1; i < pos - 1 && temp != last; i++)
        temp = temp->next;
    new_node->next = temp->next;
    temp->next = new_node;
    if (temp == last)
        last = new_node;
}

void delete_start()
{
    if (last == NULL)
        return;
    Node *temp = last->next;
    if (last->next == last)
    {
        free(last);
        last = NULL;
    }
    else
    {
        last->next = temp->next;
        free(temp);
    }
}

void delete_end()
{
    if (last == NULL)
        return;
    Node *temp = last->next;
    if (last->next == last)
    {
        free(last);
        last = NULL;
        return;
    }
    while (temp->next != last)
        temp = temp->next;
    temp->next = last->next;
    free(last);
    last = temp;
}

void delete_pos()
{
    if (last == NULL)
        return;
    int pos, i;
    printf("Enter position: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        delete_start();
        return;
    }
    Node *temp = last->next;
    for (i = 1; i < pos - 1 && temp->next != last->next; i++)
        temp = temp->next;
    Node *del = temp->next;
    temp->next = del->next;
    if (del == last)
        last = temp;
    free(del);
}

void display()
{
    if (last == NULL)
    {
        printf("List is empty\n");
        return;
    }
    Node *temp = last->next;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
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