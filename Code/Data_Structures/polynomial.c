#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int coeff;
    int pow;
    struct Node *next;
} Node;

Node *createNode(int c, int p)
{
    Node *n = (Node *)malloc(sizeof(Node));
    n->coeff = c;
    n->pow = p;
    n->next = NULL;
    return n;
}

void insert(Node **head, int c, int p)
{
    Node *n = createNode(c, p);
    if (*head == NULL)
    {
        *head = n;
        return;
    }
    Node *t = *head;
    while (t->next)
        t = t->next;
    t->next = n;
}

Node *add(Node *p1, Node *p2)
{
    Node *res = NULL, *t = NULL;
    while (p1 && p2)
    {
        Node *n;
        if (p1->pow == p2->pow)
        {
            n = createNode(p1->coeff + p2->coeff, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->pow > p2->pow)
        {
            n = createNode(p1->coeff, p1->pow);
            p1 = p1->next;
        }
        else
        {
            n = createNode(p2->coeff, p2->pow);
            p2 = p2->next;
        }
        if (!res)
            res = t = n;
        else
        {
            t->next = n;
            t = n;
        }
    }
    while (p1)
    {
        insert(&res, p1->coeff, p1->pow);
        p1 = p1->next;
    }
    while (p2)
    {
        insert(&res, p2->coeff, p2->pow);
        p2 = p2->next;
    }
    return res;
}

Node *subtract(Node *p1, Node *p2)
{
    Node *res = NULL, *t = NULL;
    while (p1 && p2)
    {
        Node *n = (Node *)malloc(sizeof(Node));
        n->next = NULL;
        if (p1->pow == p2->pow)
        {
            n->pow = p1->pow;
            n->coeff = p1->coeff - p2->coeff;
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->pow > p2->pow)
        {
            n->pow = p1->pow;
            n->coeff = p1->coeff;
            p1 = p1->next;
        }
        else
        {
            n->pow = p2->pow;
            n->coeff = -p2->coeff;
            p2 = p2->next;
        }
        if (!res)
            res = t = n;
        else
        {
            t->next = n;
            t = n;
        }
    }
    while (p1)
    {
        insert(&res, p1->coeff, p1->pow);
        p1 = p1->next;
    }
    while (p2)
    {
        insert(&res, -p2->coeff, p2->pow);
        p2 = p2->next;
    }
    return res;
}

void printPoly(Node *head)
{
    while (head)
    {
        printf("%dx^%d", head->coeff, head->pow);
        if (head->next)
            printf(" + ");
        head = head->next;
    }
    printf("\n");
}

int main()
{
    Node *p1 = NULL;
    Node *p2 = NULL;
    insert(&p1, 4, 3);
    insert(&p1, 3, 2);
    insert(&p1, 2, 1);
    insert(&p1, 1, 0);
    insert(&p2, 3, 3);
    insert(&p2, 1, 1);
    insert(&p2, 2, 0);
    Node *sum = add(p1, p2);
    Node *diff = subtract(p1, p2);
    printPoly(p1);
    printPoly(p2);
    printPoly(sum);
    printPoly(diff);
    return 0;
}
