#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Node *insertEnd(struct Node * head){
    struct Node * new = (struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter value : ");
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

void update(struct Node * ptr){
    while(ptr!=NULL){
        ptr->data=(ptr->data)*10;
        ptr=ptr->next;
    }
}

void *showLinkList(struct Node *ptr)
{
    if (ptr == NULL)
    {
        printf("\n\nLinked list is Empty.");
    }
    printf("\nLink list contains : ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("-> NULL");
}

int main(){
    struct Node * head=NULL;

    for (int i = 0; i < 5; i++)
    {
        head = insertEnd(head);
    }

    showLinkList(head);
    update(head);
    printf("\n\nAfter Update : \n");
    showLinkList(head);
    
    return 0;
}