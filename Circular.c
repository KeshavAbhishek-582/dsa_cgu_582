#include <stdio.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1, rear = -1;

// Function to check if the queue is empty
int isEmpty() {
    return front == -1 && rear == -1;
}

// Function to check if the queue is full
int isFull() {
    return (rear + 1) % MAX_SIZE == front;
}

// Function to insert an element into the queue
void enqueue(int item) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX_SIZE;
    }

    queue[rear] = item;
    printf("%d enqueued to the queue.\n", item);
}

// Function to remove an element from the queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    } else if (front == rear) {
        printf("%d dequeued from the queue.\n", queue[front]);
        front = rear = -1;
    } else {
        printf("%d dequeued from the queue.\n", queue[front]);
        front = (front + 1) % MAX_SIZE;
    }
}

// Function to display the elements in the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    int i = front;
    printf("Queue: ");
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue[rear]);
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    enqueue(40);
    enqueue(50);
    enqueue(60);
    display();
    dequeue();
    dequeue();
    dequeue();
    display();
    return 0;
}
