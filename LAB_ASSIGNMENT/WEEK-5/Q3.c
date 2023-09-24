#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int sum=0;

struct Node *insertEnd(struct Node * head){
    struct Node * new = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter value : ");
    scanf("%d", &new->data);
    
    if(head==NULL){
        head=new;
        head->next=NULL;
        return head;
    }
    struct Node * temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    new->next=NULL;
    temp->next=new;
    return head;
}

int sumUp(struct Node * ptr){
    printf("\nLink list contains : ");
    while (ptr!=NULL)
    {
        sum+=ptr->data;
        printf("%d ", ptr->data);
        ptr=ptr->next;
    }
    return sum;
}

int main(){

    struct Node *head=NULL;
    for (int x = 0; x < 5; x++){
        head=insertEnd(head);
    }

    printf("\n\nSum = %d", sumUp(head));
    
    return 0;
}