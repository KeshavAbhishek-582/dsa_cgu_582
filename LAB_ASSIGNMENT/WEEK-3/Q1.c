#include <stdio.h>
#define size 10

int stack[size];
int top = -1;

void push(int value){
    if(top==size-1){
        printf("Stack is Full.\n");
    }
    else{
        top++;
        stack[top]=value;
    }
}

void pop(){
    if(top==-1){
        printf("Stack is Empty.\n");
    }
    else{
        printf("Popped value : %d\n", stack[top]);
        top--;
    }
}

void peek(){
    printf("\nValue at top is : %d\n", stack[top]);
}

void display(){
    printf("\n");
    for (int i = top; i>=0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

int main(){
    push(6);
    push(7);
    push(8);
    push(5);
    push(3);
    pop();
    push(10);
    pop();
    pop();
    peek();
    display();
    
    return 0;
}