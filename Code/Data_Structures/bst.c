#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} NODE;

#define MAX 100
NODE *stack[MAX];
int top = -1;

void push(NODE *node) { stack[++top] = node; }
NODE *pop() { return stack[top--]; }
int isEmpty() { return top == -1; }

NODE *insert(NODE *root, int key)
{
    NODE *curr = (NODE *)malloc(sizeof(NODE));
    curr->data = key;
    curr->left = curr->right = NULL;
    if (root == NULL)
        return curr;
    NODE *p = NULL, *q = root;
    while (q != NULL)
    {
        p = q;
        if (key < q->data)
            q = q->left;
        else
            q = q->right;
    }
    if (key < p->data)
        p->left = curr;
    else
        p->right = curr;
    return root;
}

NODE *findMin(NODE *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

NODE *deleteNode(NODE *root, int key)
{
    if (root == NULL)
        return NULL;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL)
        {
            NODE *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            NODE *temp = root->left;
            free(root);
            return temp;
        }
        NODE *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorderNonRecursive(NODE *root)
{
    NODE *curr = root;
    while (curr != NULL || !isEmpty())
    {
        while (curr != NULL)
        {
            push(curr);
            curr = curr->left;
        }
        curr = pop();
        printf("%d ", curr->data);
        curr = curr->right;
    }
}

NODE *search(NODE *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

int countNodes(NODE *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeaf(NODE *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeaf(root->left) + countLeaf(root->right);
}

int countInterior(NODE *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    return 1 + countInterior(root->left) + countInterior(root->right);
}

int main()
{
    NODE *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    printf("Inorder Traversal (Non-Recursive): ");
    inorderNonRecursive(root);
    printf("\n");
    printf("Total Nodes: %d\n", countNodes(root));
    printf("Leaf Nodes: %d\n", countLeaf(root));
    printf("Interior Nodes: %d\n", countInterior(root));
    int key = 60;
    if (search(root, key))
        printf("Node %d found in BST.\n", key);
    else
        printf("Node %d not found.\n", key);
    root = deleteNode(root, 30);
    printf("After deleting 30, Inorder Traversal: ");
    inorderNonRecursive(root);
    printf("\n");
    return 0;
}
