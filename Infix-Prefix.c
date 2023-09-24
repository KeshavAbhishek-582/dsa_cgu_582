#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Structure for stack
struct Stack {
    int top;
    char items[MAX_SIZE];
};

// Function to check if the given character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to push an element onto the stack
void push(struct Stack* stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack->items[++(stack->top)] = item;
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack->items[(stack->top)--];
}

// Function to return the precedence of an operator
int precedence(char operator) {
    if (operator == '+' || operator == '-')
        return 1;
    if (operator == '*' || operator == '/')
        return 2;
    return 0;
}

// Function to convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    struct Stack stack;
    stack.top = -1;
    int i, j = 0;

    // Reverse the infix expression
    strrev(infix);

    for (i = 0; infix[i] != '\0'; i++) {
        char symbol = infix[i];
        
        if (symbol == ' ') {
            continue; // Ignore spaces
        } else if (isOperator(symbol)) {
            while (stack.top != -1 && precedence(stack.items[stack.top]) >= precedence(symbol)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, symbol);
        } else if (symbol == ')') {
            push(&stack, symbol);
        } else if (symbol == '(') {
            while (stack.items[stack.top] != ')') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); // Pop the '('
        } else {
            // Operand
            postfix[j++] = symbol;
        }
    }

    while (stack.top != -1) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';

    // Reverse the postfix expression to get the prefix expression
    strrev(postfix);
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    gets(infix);

    infixToPostfix(infix, postfix);

    printf("Prefix expression: %s\n", postfix);

    return 0;
}
