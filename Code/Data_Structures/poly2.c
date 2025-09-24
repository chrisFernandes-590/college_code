#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int coeff, pow;
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

void insert(Node **ploy, int coeff, int pow)
{
    Node newnode = createNode()
}