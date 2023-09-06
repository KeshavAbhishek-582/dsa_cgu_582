#include <stdio.h>

#define MAX_SIZE 5 // Maximum size of the circular queue

// Structure for the circular queue
struct CircularQueue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

// Function to initialize the circular queue
void initialize(struct CircularQueue* cq) {
    cq->front = -1;
    cq->rear = -1;
}

// Function to check if the circular queue is empty
int isEmpty(struct CircularQueue* cq) {
    return (cq->front == -1);
}

// Function to check if the circular queue is full
int isFull(struct CircularQueue* cq) {
    return ((cq->rear + 1) % MAX_SIZE == cq->front);
}

// Function to insert an element into the circular queue
void CQINSERT(struct CircularQueue* cq, int value) {
    if (isFull(cq)) {
        printf("Circular queue is full. Cannot insert.\n");
    } else {
        if (isEmpty(cq)) {
            cq->front = 0;
        }
        cq->rear = (cq->rear + 1) % MAX_SIZE;
        cq->items[cq->rear] = value;
        printf("Inserted: %d\n", value);
    }
}

// Function to delete an element from the circular queue
void CQDELETE(struct CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Circular queue is empty. Cannot delete.\n");
    } else {
        int deletedValue = cq->items[cq->front];
        if (cq->front == cq->rear) {
            // Last element in the queue
            cq->front = -1;
            cq->rear = -1;
        } else {
            cq->front = (cq->front + 1) % MAX_SIZE;
        }
        printf("Deleted: %d\n", deletedValue);
    }
}

// Function to display the elements of the circular queue
void display(struct CircularQueue* cq) {
    if (isEmpty(cq)) {
        printf("Circular queue is empty.\n");
    } else {
        printf("Circular queue elements: ");
        int i = cq->front;
        do {
            printf("%d ", cq->items[i]);
            i = (i + 1) % MAX_SIZE;
        } while (i != (cq->rear + 1) % MAX_SIZE);
        printf("\n");
    }
}

int main() {
    struct CircularQueue cq;
    initialize(&cq);

    CQINSERT(&cq, 10);
    CQINSERT(&cq, 20);
    CQINSERT(&cq, 30);
    CQINSERT(&cq, 40);
    CQINSERT(&cq, 50);

    display(&cq);

    CQDELETE(&cq);

    display(&cq);

    CQINSERT(&cq, 70);

    display(&cq);

    return 0;
}
