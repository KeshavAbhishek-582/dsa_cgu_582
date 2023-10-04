#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

int count=0;

struct Node * makeCircular(struct Node * head){
    struct Node * temp = head;
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }

    temp->next=head;

    return head;
    
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

    if(pos==1){
        struct Node * temp = head;
        while (temp->next!=head)
        {
            temp = temp->next;
        }

        temp->next = new;
        new->next = head;

        count++;

        head=new;

        return head;
    }

    struct Node * temp = head;

    while (i!=pos-2)
    {
        temp=temp->next;
        i++;
    }

    new->next=temp->next;
    temp->next=new;

    count++;

    return head;
}


struct Node * deletionAtSpecificPosition(struct Node * head, int pos){
    if(pos>count){
        printf("Position Invalid !");
        return head;
    }
    if(pos==1){
        printf("Value deleted : %d\n", head->data);
        struct Node * temp = head;
        count--;

        head = head->next;
        
        while (temp->next!=head){
            temp = temp->next;
        }

        temp->next=head;

        return head;
    }

    if(pos==count){
        struct Node * temp = head;

        while(temp->next->next!=head){
            temp=temp->next;
        }

        printf("Value deleted : %d\n", temp->next->data);
        temp->next=head;

        count--;

        return head;
    }
    
    int i=0;
    struct Node * temp = head;
    while(i!=pos-2){
        temp = temp->next;
        i++;
    }
    printf("\nValue deleted : %d\n", temp->next->data);
    temp->next = temp->next->next;

    count--;

    return head;
}


void printList(struct Node * head){
    printf("\n\n");
    struct Node * temp = head;
    while (temp->next!=head){
        // printf("%d ", temp->data);
        printf("%d\t%p %p\n", temp->data, temp, temp->next);
        temp = temp->next;
    }

    // printf("%d ", temp->data);
    printf("%d\t%p %p\n", temp->data, temp, temp->next);

    printf("\n\n");
}

int main(){
    struct Node * head = NULL;
    for (int i = 0; i < 5; i++){
        head=insertEnd(head);
        count++;
    }

    head = makeCircular(head);
    printList(head);
    head = insertAtSpecificPosition(head);
    printList(head);
    head = deletionAtSpecificPosition(head, 3);
    printList(head);

    return 0;
}