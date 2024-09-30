// #include<stdio.h>
// #define TRUE 1
// #define FALSE 2

// struct node {
//     struct node *lnode;
//     struct node *rnode;
//     int data;
//     int balance;
// };

// struct node * rightrot(struct node *root) {
//     struct node *aptr;
//     aptr = root->lnode;
//     root->lnode = aptr->rnode;
//     aptr->rnode = root;
//     return aptr;
// }

// struct node *leftrot(struct node *root) {
//     struct node *aptl;
//     aptl = root->rnode;
//     root->rnode = aptl->lnode;
//     aptl->lnode = root;
//     return aptl;
// }

// struct node *insert_left_check(struct node * cnode, int *taller) {
//     switch(cnode->balance) {
//         case 0: cnode->balance = -1; break;
//         case 1: cnode->balance = 0; break;
//         case -1:cnode = insert_rightbal(cnode);
//     }
//     return cnode;
// }

// struct node *insert_leftbal(struct node *cnode) {
//     struct node *aptr, *bptr;
//     aptr = cnode;
//     if(aptr->balance == 1) {
//         cnode->balance = 0;
//         aptr->balance = 0;
//         aptr = rightrot(aptr);
//     }
//     else {
//         bptr = aptr->rnode;
//         switch(bptr->balance) {
//             case -1: cnode->balance = 0;
//             aptr->balance = 1;
//             break;
//             case 1: cnode->balance = -1;
//             aptr->balance = 0;
//             break;
//             case 0: cnode->balance = 0;
//             aptr->balance = 0;
//             break;
//         }
//         bptr->balance = 0;
//         cnode->lnode = leftrot(aptr);
//         cnode = rightrot(cnode);
//     }
//     return cnode;
// }

// struct node *insert_left_check(struct node *cnode, int *taller) {
//     switch(cnode->balance) {
//         case 0 : cnode->balance = 1; break;
//         case -1: cnode->balance = 0; *taller = FALSE; break;
//         case 1:  cnode = insert_leftbal(cnode); *taller = FALSE; break;
//     }
//     return cnode;
// }

// struct node * insert(struct node *cnode, int key) {
//     static int taller;
//     if(cnode == NULL) {
//         cnode =  (struct node *)malloc(sizeof(struct node));
//         cnode->data = key;
//         cnode->lnode = NULL;
//         cnode->rnode = NULL;
//         cnode->balance = 0;
//         taller = TRUE;
//     }
//     else if(key<cnode->data) {
//         cnode->lnode = insert(cnode->lnode, key);
//         if(taller == TRUE) cnode = insert_left_check(cnode, &taller);
//     }
//     else if(key>cnode->data) {
//         cnode->rnode = insert(cnode->rnode, key);
//         if(taller == TRUE) cnode = insert_right_check(cnode, &taller);
//     }
//     else {
//         printf("Duplicate Keys");
//         taller = FALSE;
//     }
//     return cnode;
// }
struct node {
    struct node *lchild;
    int data;
    struct node *rchild;
};

struct node *stack[20];
int top = -1;

void push(struct node *item) {
    if(top == 19) {
        printf("gf");
        return;
    }
    stack[++top] = item;
}

struct node *pop() {
    if(top == -1) {
        printf("gfr");
    }
    return stack[top--];
}

void nrec_pre(struct node *root) {
    if(root == NULL) {
        printf("Enpty tree");
        return;
    }
    push(root);
    struct node *ptr;
    ptr = root;
    while(top != -1) {
        ptr = pop();
        print("%d\t", ptr->data);
        if(ptr->rchild!=NULL) push(ptr->rchild);
        if(ptr->lchild!=NULL) push(ptr->lchild);
    }
    printf("\n");
}

void nrec_in(struct node *root) {
    if(top == -1) {
        printf("no tree");
        return;
    }
    struct node *ptr;
    ptr = root;
    while(1) {
        while(ptr->lchild != NULL) {
            push(ptr);
            ptr = ptr->lchild;
        }
        while(ptr->rchild == NULL) {
            printf("%d", ptr->data);
            if(top == -1) return;
            ptr = pop();
        }
        printf("%d", ptr->data);
        ptr = ptr->rchild;
    }
    printf("\n");
}

void nrec_post(struct node *root) {
    if(root == NULL) {
        printf("e");
        return;
    }
    struct node *ptr, *q;
    ptr =  q = root;
    while(1) {
        while(ptr->lchild != NULL) {
            push(ptr);
            ptr = ptr->lchild;
        }
        while(ptr->rchild == NULL || ptr->rchild = q) {
            printf("%d", ptr->data);
            q = ptr;
            if(top == -1) return;
            ptr = pop();
        }
    }
}

struct node *queue[20];
int front = -1, rear = -1;

void insert(struct node *root) {
    if(rear = 19) {
        printf("overflow");
        return;
    }
    if(front == -1){
        front = 0;
    }
    queue[++rear] = root;
}

struct node *del(struct node *root) {
    if(front == -1 || front == rear +1) {
        printf("underflow");
        return;
    }
    return queue[front++];
}

void nrec_lv(struct node *root) {
    if(root == NULL) {
        printf("tree is empty");
        return;
    }
    struct node *ptr;
    ptr = root;
    insert(root);
    while(front == -1 || front == rear+1) {
        ptr = del();
        printf("%d", ptr->data);
        if(ptr->lchild != NULL) insert(ptr->lchild);
        if(ptr->rchild != NULL) insert(ptr->rchild);
    }
}