#include <stdio.h>
#define max 10

int queue[10];
int rear = -1;
int front = -1;

int push(int n)
{
    if ((front ==0 && rear == max-1))
    {
        printf("Queue is full\n");
    }

    if (front == -1 && rear == -1)
    {
        rear = 0;
        front = 0;
    }
    queue[rear] = n;
    rear++;
}

int pop()
{
    if (front == -1)
    {
        printf("Empty.\n");
    }
    else
    {
        printf("%d ", queue[front]);
        front = front + 1;
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
    }
}

int traverse(){
    printf("\n");
    if(front==-1){
        printf("Empty.\n");
    }
    else{
        for (int i = front; i < rear; i++)
        {
            printf("\n%d ", queue[i]);
        }
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    push(70);
    push(80);
    push(90);
    push(100);
    printf("\nPopping\n");
    pop();
    pop();
    pop();
    traverse();
    return 0;
}