#include <stdio.h>
#define size 5

int cq[size];
int rear = -1, front = -1;

int enqueue(int data)
{
    if (front == (rear + 1) % size)
    {
        printf("\nCQueue is Full.\n");
        return 1;
    }
    else
    {
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }
    }
    cq[rear] = data;
    printf("\nValue pushed : %d", data);
}

int dequeue()
{
    if (front == -1)
    {
        rear = front = -1;
        printf("\n\nCQueue is Empty.");
        return -1;
    }

    printf("\nValue deleted : %d", cq[front]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % size;
    }
}

int traverse()
{
    if (front == -1 || front > rear)
    {
        printf("\nCQueue is Empty");
        return 0;
    }
    int current = front;
    printf("\n\nValues : ");
    do
    {
        printf("%d ", cq[current]);
        // current = (current + 1)%size;

        // Circular Increment of Circular Queue Operation
        if (current == size - 1)
        {
            current = 0;
        }
        else
        {
            current++;
        }
    } while (current != (rear + 1) % size);
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    traverse();
    dequeue();
    // dequeue();
    // dequeue();
    // dequeue();
    // dequeue();
    traverse();
    printf("\n\nRear : %d\nFront : %d", rear, front);
    return 0;
}