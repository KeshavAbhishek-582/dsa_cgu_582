#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 // Maximum size of the circular queue

int cq[MAX_SIZE];  // Array to store the circular queue
int front = -1;    // Initialize front pointer
int rear = -1;     // Initialize rear pointer

// Function to check if the circular queue is empty
int isEmpty() {
    return front == -1;
}

// Function to check if the circular queue is full
int isFull() {
    return (front == 0 && rear == MAX_SIZE - 1) || (rear == (front - 1) % (MAX_SIZE - 1));
}

// Function to insert an element into the circular queue
void CQINSERT(int item) {
    if (isFull()) {
        printf("Queue is full. Cannot insert.\n");
        return;
    }

    if (front == -1) {
        front = rear = 0; // Initialize the front and rear pointers
    } else {
        rear = (rear + 1) % MAX_SIZE; // Circular increment of rear
    }

    cq[rear] = item; // Insert the item at the rear position
    printf("\nData enqueued in the queue is: %d.\n\n", item);
}

// Function to delete an element from the circular queue
int CQDELETE() {
    int item;

    if (isEmpty()) {
        printf("Queue is empty. Cannot delete.\n");
        return -1; // Return a special value to indicate an error
    }

    item = cq[front]; // Get the item to be deleted

    if (front == rear) {
        front = rear = -1; // Reset the pointers if it's the last element
    } else {
        front = (front + 1) % MAX_SIZE; // Circular increment of front
    }

    return item;
}

// Function to display all elements in the circular queue
void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    int current = front;
    printf("Circular Queue elements: ");

    do {
        printf("%d ", cq[current]);
        current = (current + 1) % MAX_SIZE;
    } while (current != (rear + 1) % MAX_SIZE);

    printf("\n");
}

int main(){

    int opt;
    int data;
    
    do
    {
        printf("\n1. To insert element into Queue.\n2. To delete an element from Queue.\n3. For traversing of array.\n4. Exit\nEnter choice : ");
        scanf("%d", &opt);
        printf("\n");
        
        switch (opt)
        {
            case 1:
                printf("Enter data : ");
                scanf("%d", &data);
                CQINSERT(data);
                break;
            case 2:
                printf("Deleted item: %d\n", CQDELETE());
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                exit(0);
            default:
                printf("\n\n!! Invalid !!");
        }
    }while(1);
    

    return 0;
}