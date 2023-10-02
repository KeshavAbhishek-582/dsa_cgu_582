#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node * prev;
    int data;
    struct Node * next;
};

void showLinkList(struct Node *ptr)
{
    if (ptr == NULL)
    {
        printf("\n\nLinked list is Empty.");
    }
    else{
        printf("\nDouble-Link List contains : \nNULL");
        while (ptr != NULL)
        {
            printf("<->%d", ptr->data);
            ptr = ptr->next;
        }
        printf("<->NULL");
    }
}

struct Node * insertAtEnd(struct Node * head){
    struct Node * new;
    new = (struct Node *)malloc(sizeof(struct Node));
    
    new->prev=NULL;
    printf("Enter Data : ");
    scanf("%d", &new->data);
    new->next=NULL;
    if(head==NULL){
        head=new;
        head->next=NULL;
        return head;
    }

    struct Node * temp = head;

    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=new;
    new->prev=temp;

    return head;
}

struct Node * replace(struct Node * head){
    struct Node * temp=head;
    head = head->next;
    struct Node * temp2=head;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp;
    temp->prev=temp2;
    temp->next=NULL;

    return head;
}

int main(){
    struct Node * head = NULL;
    for (int i = 0; i < 5; i++)
    {
        head = insertAtEnd(head);
    }
    showLinkList(head);
    head=replace(head);
    printf("\nAfter Operation : \n");
    showLinkList(head);
    
    return 0;
}