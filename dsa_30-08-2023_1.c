/*
1. Write a menu driven c-code for the following operations on Linear queue using array.

(i) Insertion
(ii) Deletion
(iii) Traversal
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int front = -1, rear = -1;

int queue[MAX_SIZE];

void enqueue(int value) {
    if (rear == MAX_SIZE - 1) {
        printf("\nQueue is Full.\n\n");
    } else {
        rear++;
        queue[rear] = value;
        if (front == -1) {
            front = 0; // Adjust the front pointer if it's the first element
        }
        printf("\nData enqueued in the queue is: %d.\n\n", value);
    }
}

void dequeue(){
    if((front==-1 && rear==-1) || (front>rear)){
        printf("\nQueue is Empty.\n\n");
    }
    else{
        printf("\nDequeued Value : %d\n\n", queue[front++]);
        if(front==rear+1){
            front=rear=-1;
        }
    }
}

void traverse(){
    if((front==-1 && rear==-1) || (front>rear)){
        printf("\nQueue is Empty.\n\n");
    }
    else{
        for (int i = front; i <= rear; i++)
        {
            printf("\nAt index : %d --> Value is : %d\n", i, queue[i]);
        }
    }
    
}

int main(){

    int opt;
    int data;
    
    do
    {
        printf("1. To insert element into Queue.\n2. To delete an element from Queue.\n3. For traversing of array.\n4. Exit\nEnter choice : ");
        scanf("%d", &opt);
        
        switch (opt)
        {
            case 1:
                printf("Enter data : ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                traverse();
                break;
            case 4:
                exit(0);
            default:
                printf("\n\n!! Invalid !!");
        }
    }while(1);
    

    return 0;
}
