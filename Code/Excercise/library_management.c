#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int bookID;
  struct Node *left, *right;
} Node;

Node *createNode(Node *root, int bookID)
{
  Node *new = (Node *)malloc(sizeof(Node));
  new->bookID = bookID;
  new->left = new->right = NULL;
  return new;
}

Node *addBook(Node *root, int bookID)
{
  if (root == NULL)
    return createNode(root, bookID);
  if (bookID < root->bookID)
  {
    root->left = addBook(root->left, bookID);
  }
  else if (bookID > root->bookID)
  {
    root->right = addBook(root->right, bookID);
  }
  else
  {
    printf("The book already exist!");
  }
  return root;
}

Node *findMin(Node *root)
{
  while (root->left != NULL)
  {
    root = root->left;
  }
  return root;
}

Node *removeBook(Node *root, int bookID)
{
  if (root == NULL)
  {
    printf("The book does not exist");
    return root;
  }

  if (bookID < root->bookID)
  {
    root = removeBook(root->left, bookID);
  }
  else if (bookID > root->bookID)
  {
    root = removeBook(root->right, bookID);
  }
  else
  {
    // No child
    if (root->left == NULL && root->right == NULL)
    {
      free(root);
      return NULL;
    }
    // one child
    else if (root->left == NULL)
    {
      Node *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL)
    {
      Node *temp = root->left;
      free(root);
      return temp;
    }
    // two children
    Node *temp = findMin(root->right);
    root->bookID = temp->bookID;
    root->right = removeBook(root->right, temp->bookID);
  }
  return root;
}

int findBook(Node *root, int bookID)
{
  if (root == NULL)
    return 0;

  if (bookID == root->bookID)
  {
    return 1;
  }
  else if (bookID < root->bookID)
  {
    return findBook(root->left, bookID);
  }
  else
  {
    return findBook(root->right, bookID);
  }
}

void displayAllBooks(Node *root)
{
  if (root != NULL)
  {
    displayAllBooks(root->left);
    printf("%d ", root->bookID);
    displayAllBooks(root->right);
  }
}

Node *updateBook(Node *root, int newID, int oldID)
{
  if (!findBook(root, oldID))
  {
    printf("Book ID %d not found for update!\n", oldID);
    return root;
  }
  root = removeBook(root, oldID);
  root = addBook(root, oldID);
  printf("Book ID %d updated to %d successfully!\n", oldID, newID);
  return root;
}

int main()
{
  Node *root = NULL;
  int choice, book_ID, old_ID, new_ID;

  while (1)
  {
    printf("\n\n--- Library Book Management (BST) ---\n");
    printf("1. Add Book\n");
    printf("2. Remove Book\n");
    printf("3. Update Book ID\n");
    printf("4. Find Book\n");
    printf("5. Display All Books (In-Order)\n");
    printf("6. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter Book ID to add: ");
      scanf("%d", &book_ID);
      root = addBook(root, book_ID);
      break;
    case 2:
      printf("Enter Book ID to remove: ");
      scanf("%d", &book_ID);
      root = removeBook(root, book_ID);
      break;
    case 3:
      printf("Enter old Book ID: ");
      scanf("%d", &old_ID);
      printf("Enter new Book ID: ");
      scanf("%d", &new_ID);
      root = updateBook(root, old_ID, new_ID);
      break;
    case 4:
      printf("Enter Book ID to search: ");
      scanf("%d", &book_ID);
      if (findBook(root, book_ID))
        printf("Book ID %d found in library.\n", book_ID);
      else
        printf("Book ID %d not found.\n", book_ID);
      break;
    case 5:
      printf("All Book IDs (sorted): ");
      displayAllBooks(root);
      printf("\n");
      break;
    case 6:
      exit(0);
    default:
      printf("Invalid choice!\n");
    }
  }
  return 0;
}