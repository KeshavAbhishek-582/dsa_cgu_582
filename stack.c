#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1;

// Function to push an element onto the stack
void push(int value) {
    if (top == MAX_SIZE - 1) {
        printf("Stack is full. Cannot push.\n");
        return;
    }
    stack[++top] = value;
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    return stack[top--];
}

// Function to peek at the top element of the stack
int peek() {
    if (top == -1) {
        printf("Stack is empty. Cannot peek.\n");
        return -1;
    }
    return stack[top];
}

// Function to check if the stack is full
bool isfull() {
    return top == MAX_SIZE - 1;
}

// Function to check if the stack is empty
bool isempty() {
    return top == -1;
}

int main() {

    printf("Top element: %d\n", peek());

    pop();

    printf("Top element after pop: %d\n", peek());

    printf("Is stack full? %s\n", isfull() ? "Yes" : "No");
    printf("Is stack empty? %s\n", isempty() ? "Yes" : "No");

    return 0;
}