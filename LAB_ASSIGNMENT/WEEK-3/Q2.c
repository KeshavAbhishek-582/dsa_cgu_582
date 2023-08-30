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
    push(10);

    display();
    
    return 0;
}