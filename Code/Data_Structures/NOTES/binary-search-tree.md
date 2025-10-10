# Binary Search Tree (BST)

---

## 🧠 Definition
A Binary Search Tree (BST) is a binary tree where each node contains a key such that:
- Left child’s key < parent’s key  
- Right child’s key > parent’s key  

---

## 🧮 Properties
- Recursive structure
- Inorder traversal gives sorted order
- Height-balanced trees improve performance

---

## ⚙️ Operations
| Operation | Best Case | Average | Worst Case |
|------------|------------|----------|-------------|
| Insert     | O(log n)  | O(log n) | O(n) |
| Search     | O(log n)  | O(log n) | O(n) |
| Delete     | O(log n)  | O(log n) | O(n) |

---

## 🔢 Algorithm (Insert)

1. Create new node `curr` & `curr -> data = key`
2. Set left and right child of `curr` to __NULL__
3. if root == NULL then  
    return `curr`
4. else:  
    create two pointers `p = NULL` & `q = root`
5. LOOP till `q != NULL`  
    a. set `p = q`   
    b. if key < `q -> data`  
        `q = q -> left`  
    c. else:  
        `q = q -> right`
6. if `data < p -> data`  
    `p -> left = curr`
7. else:  
    `p -> right = curr`
8. return __root__

```c
Node* insert(Node *root, int key){
    Node* curr = (Node*)malloc(sizeof(Node));
    curr->data = key;
    curr->left = curr->right = NULL;
    if(root == NULL) return curr;
    Node *p = NULL, *q = root;
    while(q != NULL){
        p = q;
        if(key < q->data){
            q = q->left;
        }else{
            q = q->right;
        }
    }
    if(key < p->data){
        p->left = curr;
    }else{
        q->right = curr;
    }
    return root;
}
```

    


