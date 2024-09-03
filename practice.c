#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int queue[MAX];
int front = -1;
int rear = -1;

//if full
int isFull() {
    if(rear == MAX - 1) {
        return 1;
    } else {
        return 0;
    }
}

//if empty
int isEmpty() {
    if(front == -1 || front == rear+1) {
        return 1;
    } else {
        return 0;
    }
}

//insert
void push(int data) {
    if(isFull()) {
        printf("\nQueue Overflow\n");
        return;
    }
    if(front == -1) front++;
    queue[++rear] = data;
}

//del
int pop() {
    if(isEmpty()) {
        printf("\nQueue Underflow\n");
        exit(1);
    }
    int i = queue[front];
    front++;
    return i;
}


//seek
int peek() {
    if(isEmpty()) {
        printf("\nQueue Underflow\n");
        exit(1);
    }
    return queue[front];
}

void main() {
    push(12);
    push(34);
    push(45);
    push(54);
    printf("\n%d\n", peek());
    pop();
    printf("\n%d\n", peek());
    pop();
    printf("\n%d\n", peek());
    push(12);
    push(2);
    push(4);
    push(77);
    push(12);
    push(3);
    push(45);
    push(34);
    push(76);
    push(34);
    push(98);
    push(7);
    printf("\n%d\n", peek());
}
