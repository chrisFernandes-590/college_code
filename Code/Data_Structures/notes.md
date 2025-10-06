Stack 1: 10, 20, 40
Stack 2: 40, 20, 10

Queue: 10, 20, 40
Q_deque: 10, 20, 40
Q_diplay: 10, 20, 40


### CIR LL

insert_beg:
    create newnode
    if head == null:
        head = newnode
        newnode->next = head
    else:
        newnode->next = head->next
        head->next = newnode

```
insert_end:
    create newnode
    if head == null:
        head = newnode
        newnode->next = head
    else:
        Node* temp = head
        while(temp->next != head):
            temp = temp->next
        temp->next = newnode
        newnode->next = head
```
```
insert_pos:
    pos
    create newnode
    if head == null:
        head = newnode
        newnode->next = head
    else:
        Node* temp = head->next
        for(int i = 1; i < pos - 1 && temp != head; i++)   
            temp = temp->next
        newnode->next = temp->next
        temp->next = newnode
        if temp == head:
            head = newnode    
```


### POLYNOMIAL
```
insert(Node **poly, int pow, int coeff){
    create newnode
    
}
```
### POLYNOMIAL

**ADD**

```c
Node* add(Node *p1, Node *p2){
    Node *res = NULL, *temp = NULL;
    while(p1 && p2){
        Node *new;
        if(p1->pow == p2->pow){
            new = createNode(p1->coeff + p2->coeff, p1->pow)
            p1 = p1->next;
            p2 = p2->next;
        }else if(p1->pow > p2->pow){
            new = createNode(p1->coeff, p1->pow)
            p1 = p1->next;
        }else{
            new = createNode(p2->coeff, p2->pow)

        }
    }
}

```
