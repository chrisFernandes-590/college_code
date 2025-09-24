#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int coeff;
    int pow;
    struct Node *next;
} Node;

Node *createNode(int coeff, int pow)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

void insert(Node **poly, int coeff, int pow)
{
    Node *newNode = createNode(coeff, pow);
    if (*poly == NULL)
    {
        *poly = newNode;
        return;
    }
    Node *temp = *poly;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

Node *addPoly(Node *poly1, Node *poly2)
{
    Node *result = NULL;
    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->pow == poly2->pow)
        {
            insert(&result, poly1->coeff + poly2->coeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly1->pow > poly2->pow)
        {
            insert(&result, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        }
        else
        {
            insert(&result, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL)
    {
        insert(&result, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }
    while (poly2 != NULL)
    {
        insert(&result, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }
    return result;
}

Node *subPoly(Node *poly1, Node *poly2)
{
    Node *result = NULL;
    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->pow == poly2->pow)
        {
            insert(&result, poly1->coeff - poly2->coeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        else if (poly1->pow > poly2->pow)
        {
            insert(&result, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        }
        else
        {
            insert(&result, -poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL)
    {
        insert(&result, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }
    while (poly2 != NULL)
    {
        insert(&result, -poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }
    return result;
}

void display(Node *poly)
{
    while (poly != NULL)
    {
        printf("%dx^%d", poly->coeff, poly->pow);
        poly = poly->next;
        if (poly != NULL && poly->coeff >= 0)
            printf(" + ");
        else if (poly != NULL)
            printf(" ");
    }
    printf("\n");
}

int main()
{
    Node *poly1 = NULL;
    Node *poly2 = NULL;
    Node *sum = NULL;
    Node *diff = NULL;

    // 4x^3 + 3x^2 + 2x + 1
    insert(&poly1, 4, 3);
    insert(&poly1, 3, 2);
    insert(&poly1, 2, 1);
    insert(&poly1, 1, 0);

    // 3x^3 + 1x^1 + 5
    insert(&poly2, 3, 3);
    insert(&poly2, 1, 1);
    insert(&poly2, 5, 0);

    printf("Polynomial 1: ");
    display(poly1);
    printf("Polynomial 2: ");
    display(poly2);

    sum = addPoly(poly1, poly2);
    diff = subPoly(poly1, poly2);

    printf("Sum: ");
    display(sum);
    printf("Difference: ");
    display(diff);

    return 0;
}
