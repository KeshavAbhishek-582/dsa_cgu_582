#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Node *showLinkList(struct Node *ptr)
{
    if (ptr == NULL)
    {
        printf("\n\nLinked list is Empty.");
    }
    else{
        printf("\nLink list contains : ");
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("-> NULL (End of Linked List)");
    }
}

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

struct Node *insertAtSpecificPosition(struct Node *head){
    struct Node * new = (struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter value : ");
    scanf("%d", &new->data);

    int i = 0, pos=0;

    printf("Enter position : ");
    scanf("%d", &pos);printf("\n");
    
    struct Node * temp = head;

    while (i!=pos-2)
    {
        temp=temp->next;
        i++;
    }

    new->next=temp->next;
    temp->next=new;

    return head;
}

int main(){
    struct Node *head;
    head = NULL;

    for (int x = 0; x < 5; x++){
        head=insertEnd(head);
    }

    showLinkList(head);

    head = insertAtSpecificPosition(head);
    
    printf("\nAfter Operation\n");
    
    showLinkList(head);

    return 0;
}