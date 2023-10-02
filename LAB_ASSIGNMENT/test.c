#include <stdio.h>
#define size 5

int queue[size];
int front = -1;
int rear = -1;

int enqueue(int data)
{
    if (front == -1)
    {
        rear = 0;
        front = 0;
    }
    else
    {
        rear = (rear + 1) % size;
    }
    queue[rear] = data;
}

int dequeue()
{
    if (front == -1)
    {
        return front == -1;
    }
    printf("\nValue dequeued : %d", queue[front]);

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % size;
    }
}

int traverse()
{
    printf("\n");
    if (front==-1 || front > rear)
    {
        printf("Empty Circular Queue.\n");
    }
    else
    {
        int current = front;
        do
        {
            printf("\nValue : %d", queue[current]);
            current = (current + 1) % size;
        } while (current != (rear + 1) % size);
    }
}

int main()
{
    enqueue(127);
    enqueue(556);
    enqueue(30);
    enqueue(20);
    enqueue(30);
    traverse();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    traverse();
    enqueue(30);
    traverse();
    traverse();

    printf("\n\nFront = %d\nRear = %d", front, rear);

    return 0;
}