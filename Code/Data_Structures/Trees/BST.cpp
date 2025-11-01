#include<iostream>
using namespace std;

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int data){ //Seperate function for creating a new node 
    Node* newNode = new Node; //Node* newNode = (Node *)malloc(sizeof(Node)); --> C-style 
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
}

//Recursive Insert Function
Node* insert(Node* root, int key){
    Node* newNode = createNode(key);

    if(root == NULL){
        return newNode;
    }

    if(root->data < key){
        root->right = insert(root->right, key);
    }
    else if(root->data > key){
        root->left = insert(root->left, key);
    }

    return root;
}

Node* iterativeInsert(Node* root, int key){
    Node* newNode = createNode(key);

    if(root == NULL){
        return newNode;
    }

    Node* temp = root;
    Node* prev = NULL;

    while(temp){
        prev = temp;
        if(temp->data < key){
           temp = temp->right;
        }
        else if(temp->data > key){
            temp = temp->left;
        }
    }

    if(prev->data > key){
        prev->left = newNode;
    }
    else prev->right = newNode;

    return root;
}

Node* deleteIterative(Node* root, int key) {
    if (root == NULL) {
        cout << "Tree is empty!\n";
        return NULL;
    }

    Node* parent = NULL;
    Node* curr = root;

    // 🔍 Step 1: Find the node to delete and its parent
    while (curr && curr->data != key) {
        parent = curr;
        if (key < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (!curr) {
        cout << "Node not found!\n";
        return root;
    }

    // 🧩 Step 2: Case 1 — No children (Leaf)
    if (!curr->left && !curr->right) {
        if (!parent) {  // deleting root only (IMP Edge case)
            delete curr; //free curr --> C-style
            return NULL;
        }
        if (parent->left == curr)
            parent->left = NULL;
        else
            parent->right = NULL;
        delete curr;
    }

    // 🌿 Step 3: Case 2 — One child
    else if (!curr->left || !curr->right) { 

        Node* child = (curr->left) ? curr->left : curr->right; //Ternanry operator

        if (!parent) { //IMP Edge Case
            delete curr; //free curr --> C-style
            return child; // new root
        }
        if (parent->left == curr)
            parent->left = child;
        else
            parent->right = child;
        delete curr;
    }

    // 🌳 Step 4: Case 3 — Two children
    else {
        // Find inorder predecessor (max in left subtree)
        Node* predParent = curr;
        Node* pred = curr->left;
        while (pred->right) {
            predParent = pred;
            pred = pred->right;
        }

        // Copy predecessor’s data into current node
        curr->data = pred->data;

        // Now delete the predecessor node (it has at most one child)
        if (predParent->right == pred)
            predParent->right = pred->left; //left can either be a valid node or NULL
            //Anyways, it's obvious that it won't contain any right child
        else
            predParent->left = pred->left;
        delete pred;
    }

    return root;
}