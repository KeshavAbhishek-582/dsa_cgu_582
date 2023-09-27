#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node * prev;
    int data;
    struct Node * next;
};

struct Node * insertAtBeginning(struct Node * head);
struct Node * insertAtEnd(struct Node * head);

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

struct Node * insertAtBeginning(struct Node * head){
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
    else{
        struct Node * temp = head;
        head=new;
        new->next=temp;
        temp->prev=new;
        return head;
    }
}

struct Node * insertAtSpecificPosition(struct Node * head){
    struct Node * new;
    new = (struct Node *)malloc(sizeof(struct Node));

    int i=0 , pos=0;
    struct Node * temp_temp = head;

    while(temp_temp!=NULL){
        temp_temp=temp_temp->next;
        i++;
    }

    if(head==NULL || pos==1){
        return insertAtBeginning(head);
    }

    if(pos==i){
        return insertAtEnd(head);
    }

    new->prev=NULL;
    printf("\nEnter Data : ");
    scanf("%d", &new->data);
    new->next=NULL;

    printf("Enter Position (1-%d) : ", i);scanf("%d", &pos);

    struct Node * temp = head;

    i=0;
    while(i!=pos-1){
        temp=temp->next;
        i++;
    }

    new->next=temp->next;
    temp->next=new;
    new->prev=temp;

    return head;
}

struct Node * insertAtEnd(struct Node * head){
    if(head==NULL){
        return insertAtBeginning(head);
    }
    struct Node * new;
    new = (struct Node *)malloc(sizeof(struct Node));
    
    new->prev=NULL;
    printf("Enter Data : ");
    scanf("%d", &new->data);
    new->next=NULL;

    struct Node * temp = head;

    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=new;
    new->prev=temp;

    return head;
}

int main(){
    struct Node * head=NULL;

    head=insertAtBeginning(head);
    head=insertAtEnd(head);

    head = insertAtSpecificPosition(head);
    head = insertAtSpecificPosition(head);

    showLinkList(head);

    return 0;
}