#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void PUSH(int item) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    queue[++rear] = item;
}

int POP() {
    int item;
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        exit(1);
    }
    item = queue[front++];
    return item;
}

int main() {
    PUSH(1);
    PUSH(2);
    PUSH(3);

    printf("Dequeued: %d\n", POP());
    printf("Dequeued: %d\n", POP());
    printf("Dequeued: %d\n", POP());

    PUSH(4);
    PUSH(5);

    printf("Dequeued: %d\n", POP());
    printf("Dequeued: %d\n", POP());

    return 0;
}