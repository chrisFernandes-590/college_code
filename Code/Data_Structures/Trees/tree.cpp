#include<iostream>
using namespace std;

#define SIZE 100

//Employee Hierarchy (BFS Traversal)

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Queue {
    Node* arr[SIZE];
    int f, r;
} Queue;

// ------------------- Queue Functions -------------------

void initQueue(Queue *q) {
    q->f = q->r = -1;
}

bool isQueueEmpty(Queue *q) {
    return q->f == -1 && q->r == -1;
}

void enqueue(Queue *q, Node* root) {
    if (q->r == SIZE - 1) {
        cout << "Queue is full \n";
        return;
    }

    if (q->f == -1 && q->r == -1) {
        q->f = q->r = 0;
        q->arr[q->r] = root;
        return;
    }

    q->r++;
    q->arr[q->r] = root;
}

Node* dequeue(Queue *q) {
    if (q->f == -1 && q->r == -1) {
        cout << "Queue is empty\n";
        return NULL;
    }

    Node* poppedNode = q->arr[q->f];

    if (q->f == q->r)
        q->f = q->r = -1;
    else
        q->f++;

    return poppedNode;
}

// ------------------- Tree Functions -------------------

Node* createNode(int data) { //Seperate function for creating a new node 
    Node* newNode = new Node; //Node* newNode = (Node *)malloc(sizeof(Node)); --> C-style 
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* findEmployee(Queue *q, Node* root, int empID) {
    if (root == NULL) return NULL;

    initQueue(q);
    enqueue(q, root);

    while (!isQueueEmpty(q)) {
        Node* curr = dequeue(q);

        if (curr->data == empID)
            return curr;

        if (curr->left) enqueue(q, curr->left);
        if (curr->right) enqueue(q, curr->right);
    }

    return NULL;
}

bool addEmployee(Queue *q, Node* root, int empID, int managerID) {
    if (root == NULL) {
        cout << "Hierarchy is empty.\n";
        return false;
    }

    initQueue(q);
    enqueue(q, root);

    while (!isQueueEmpty(q)) {
        Node* curr = dequeue(q);

        if (curr->data == managerID) {
            if (curr->left == NULL) {
                curr->left = createNode(empID);
                cout << "Employee added successfully under Manager " << managerID << " (Left).\n";
                return true;
            } else if (curr->right == NULL) {
                curr->right = createNode(empID);
                cout << "Employee added successfully under Manager " << managerID << " (Right).\n";
                return true;
            } else {
                cout << "Manager " << managerID << " already has 2 subordinates.\n";
                return false;
            }
        }

        if (curr->left) enqueue(q, curr->left);
        if (curr->right) enqueue(q, curr->right);
    }

    cout << "Manager not found.\n";
    return false;
}

void delSubTree(Node* root) { //Recursively delete the given root and descendants 
    if (root == NULL) return;
    delSubTree(root->left);
    delSubTree(root->right);
    delete root;
}

bool removeEmployee(Queue *q, Node* root, int empID, int managerID) {
    if (root == NULL) {
        cout << "Hierarchy is empty.\n";
        return false;
    }

    initQueue(q);
    enqueue(q, root);

    while (!isQueueEmpty(q)) {
        Node* curr = dequeue(q);

        if (curr->data == managerID) {
            if (curr->left && curr->left->data == empID) {
                delSubTree(curr->left);
                curr->left = NULL; //To prevent dangling pointers
                cout << "Employee " << empID << " removed successfully.\n";
                return true;
            }
            if (curr->right && curr->right->data == empID) {
                delSubTree(curr->right);
                curr->right = NULL; //To prevent dangling pointers
                cout << "Employee " << empID << " removed successfully.\n";
                return true;
            }
            cout << "Employee not found under this manager.\n";
            return false;
        }

        if (curr->left) enqueue(q, curr->left);
        if (curr->right) enqueue(q, curr->right);
    }

    cout << "Manager not found.\n";
    return false;
}

bool modifyEmployee(Queue *q, Node* root, int oldID, int newID) {
    if (root == NULL) {
        cout << "Hierarchy is empty.\n";
        return false;
    }

    Node* emp = findEmployee(q, root, oldID);
    if (emp == NULL) {
        cout << "Employee not found.\n";
        return false;
    }

    emp->data = newID;
    cout << "Employee ID modified successfully!\n";
    return true;
}

void displayHierarchy(Queue *q, Node* root) {
    if (root == NULL) {
        cout << "Hierarchy is empty.\n";
        return;
    }

    cout << "Current Employee Hierarchy (Level Order): ";
    initQueue(q);
    enqueue(q, root);

    bool first = true;

    while (!isQueueEmpty(q)) {
        Node* curr = dequeue(q);

        if(!first) cout<<" --> "; //flag for arrow mark

        cout << curr->data;
        first = false;

        if (curr->left) enqueue(q, curr->left);
        if (curr->right) enqueue(q, curr->right);
    }
    cout << "\n";
}

// ------------------- Main Function -------------------

int main() {
    Queue q;
    initQueue(&q);

    Node* root = NULL;
    int choice, empID, managerID, newID;

    cout << "=== Employee Hierarchy Management System ===\n";

    while (true) {
        cout << "\n1. Create CEO (Root Employee)";
        cout << "\n2. Add Employee under Manager";
        cout << "\n3. Remove Employee (and Subordinates)";
        cout << "\n4. Modify Employee ID";
        cout << "\n5. Display Hierarchy";
        cout << "\n6. Exit";
        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (root != NULL) {
                    cout << "CEO already exists.\n";
                    break;
                }
                cout << "Enter CEO ID: ";
                cin >> empID;
                root = createNode(empID);
                cout << "CEO created successfully!\n";
                break;

            case 2:
                cout << "Enter Manager ID: ";
                cin >> managerID;
                cout << "Enter New Employee ID: ";
                cin >> empID;
                addEmployee(&q, root, empID, managerID);
                break;

            case 3:
                cout << "Enter Manager ID: ";
                cin >> managerID;
                cout << "Enter Employee ID to Remove: ";
                cin >> empID;
                removeEmployee(&q, root, empID, managerID);
                break;

            case 4:
                cout << "Enter Old Employee ID: ";
                cin >> empID;
                cout << "Enter New Employee ID: ";
                cin >> newID;
                modifyEmployee(&q, root, empID, newID);
                break;

            case 5:
                displayHierarchy(&q, root);
                break;

            case 6:
                cout << "Exiting program. Goodbye!\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
