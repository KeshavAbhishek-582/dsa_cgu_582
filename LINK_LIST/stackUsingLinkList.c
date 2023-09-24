#include <stdio.h>
#include <stdlib.h>
#define size 5

struct Node{
    int data;
    struct Node * next;
};

int count = 0;

struct Node *showLinkList(struct Node *ptr)
{
    if (ptr == NULL)
    {
        printf("\n\nStack is Empty.");
    }
    printf("\nStack contains : ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("-> NULL");
}

// struct Node *push(struct Node * top);


struct Node *push(struct Node * top){
    struct Node * new = (struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter value : ");
    scanf("%d", &new->data);
    if(top==NULL){
        top=new;
        top->next=NULL;
        return top;
    }
    new->next=top;
    top=new;
    return top;
}

struct Node *pop(struct Node * top){
    if(top==NULL){
        printf("\n\nUnderFlow");
        return top;
    }
    struct Node * temp=top;
    top = top->next;
    printf("\nPopped value : %d", temp->data);
    // temp->next=NULL;
    free(temp);
    return top;
}

int main(){
    struct Node * top=NULL;


    while(count!=5){
        top=push(top);
        showLinkList(top);
        count++;
    }

    top=pop(top);
    top=pop(top);
    top=pop(top);
    top=pop(top);
    top=pop(top);
    top=pop(top);

    
    return 0;
}