# Binary Search Tree (BST)

1. Struct contains `data, node* left, *right`

## insert
```c
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
}
```

## delete
```c
Node* deleteNode(Node* root, int data){
  // tree empty
  if(root == NULL) return root;

  if(data < root->data){
    root = deleteNode(root->left, data);
  }else if(data > root -> data){
    root = deleteNode(root->right, data);
  }else{
    // No Child
    if(root->left == NULL && root->right == NULL){
      free(root);
      return NULL;
    }
    // One child
    if(root->left == NULL){
      Node* temp = root->right;
      free(root);
      return temp;
    }else if(root->right == NULL){
      Node* temp = root->left;
      free(root);
      return temp;
    }
    Node* temp = findMin(root->left);
    root->data = temp->data;
    root->right = delete(root->left, temp->data);
  }
  return root;
}
```

1. Stack
2. Queue
3. Deque
4. BST
5. 
6.
7.


```c
// Insert AT end

void insertAtEnd(int data){
  Node* new = createNode(data);
  if(head == NULL){
    head = new;
    return;
  }
}
```