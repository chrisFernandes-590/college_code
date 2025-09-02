#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *head2 = NULL;

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int countNodes(struct Node *head)
{
    int count = 0;
    struct Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

struct Node *reverse(struct Node *head)
{
    struct Node *p = NULL, *q = head, *r = NULL;
    while (q != NULL)
    {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    return p;
}

struct Node *copyList(struct Node *head)
{
    if (head == NULL)
        return NULL;
    struct Node *newHead = createNode(head->data);
    struct Node *temp1 = head->next;
    struct Node *temp2 = newHead;
    while (temp1 != NULL)
    {
        temp2->next = createNode(temp1->data);
        temp2 = temp2->next;
        temp1 = temp1->next;
    }
    return newHead;
}

struct Node *concatenate(struct Node *head1, struct Node *head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    struct Node *temp = head1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
    return head1;
}

void splitList(struct Node *head, struct Node **head1, struct Node **head2)
{
    if (head == NULL)
    {
        *head1 = NULL;
        *head2 = NULL;
        return;
    }
    int n = countNodes(head);
    int mid = n / 2;
    struct Node *temp = head;
    for (int i = 1; i < mid; i++)
        temp = temp->next;
    *head1 = head;
    *head2 = temp->next;
    temp->next = NULL;
}

int main()
{
    int choice, val;
    struct Node *copy = NULL, *firstHalf = NULL, *secondHalf = NULL;

    while (1)
    {
        printf("\n===== LINKED LIST MENU =====\n");
        printf("1. Insert into List 1\n");
        printf("2. Insert into List 2\n");
        printf("3. Display List 1\n");
        printf("4. Display List 2\n");
        printf("5. Count nodes in List 1\n");
        printf("6. Reverse List 1\n");
        printf("7. Copy List 1\n");
        printf("8. Concatenate List1 + List2\n");
        printf("9. Split List 1\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            insertEnd(&head, val);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &val);
            insertEnd(&head2, val);
            break;
        case 3:
            display(head);
            break;
        case 4:
            display(head2);
            break;
        case 5:
            printf("Number of nodes in List1 = %d\n", countNodes(head));
            break;
        case 6:
            head = reverse(head);
            printf("List1 Reversed!\n");
            break;
        case 7:
            copy = copyList(head);
            printf("Copied List1 -> ");
            display(copy);
            break;
        case 8:
            head = concatenate(head, head2);
            head2 = NULL;
            printf("Lists concatenated!\n");
            break;
        case 9:
            splitList(head, &firstHalf, &secondHalf);
            printf("First Half: ");
            display(firstHalf);
            printf("Second Half: ");
            display(secondHalf);
            break;
        case 0:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
