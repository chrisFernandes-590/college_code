#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *create_node(int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node)
    {
        exit(1);
    }
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

void insert_end(Node **head, int value)
{
    Node *new_node = create_node(value);
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    Node *temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = new_node;
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

int count_nodes(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

Node *concatenate(Node *head1, Node *head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    Node *p = head1;
    while (p->next != NULL)
        p = p->next;
    p->next = head2;
    return head1;
}

Node *reverse(Node *head)
{
    Node *p = NULL, *q = head, *r = NULL;
    while (q != NULL)
    {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    return p;
}

void split(Node *h1, Node **first, Node **second)
{
    int count = count_nodes(h1);
    if (count < 2)
    {
        *first = h1;
        *second = NULL;
        return;
    }
    Node *temp = h1;
    for (int i = 0; i < (count / 2) - 1; i++)
    {
        temp = temp->next;
    }
    *first = h1;
    *second = temp->next;
    temp->next = NULL;
}

void free_list(Node **head)
{
    Node *temp;
    while (*head)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main()
{
    Node *list1 = NULL, *list2 = NULL;
    Node *first_half = NULL, *second_half = NULL;

    insert_end(&list1, 1);
    insert_end(&list1, 2);
    insert_end(&list1, 3);

    insert_end(&list2, 4);
    insert_end(&list2, 5);
    insert_end(&list2, 6);

    printf("List1: ");
    display(list1);
    printf("List2: ");
    display(list2);

    Node *concat = concatenate(list1, list2);
    printf("Concatenated: ");
    display(concat);

    printf("Number of nodes = %d\n", count_nodes(concat));

    split(concat, &first_half, &second_half);
    printf("First half: ");
    display(first_half);
    printf("Second half: ");
    display(second_half);

    first_half = reverse(first_half);
    printf("Reversed first half: ");
    display(first_half);

    free_list(&first_half);
    free_list(&second_half);

    return 0;
}
