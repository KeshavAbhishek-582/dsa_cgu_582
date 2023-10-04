#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node{
    struct Node * prev;
    int data;
    struct Node * next;
};

int count = 0;

struct Node *createNode(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

struct Node *insertAtStart(struct Node *head, int data){
    struct Node *newNode = createNode(data);
    
    if (head == NULL){
        count++;
        head = newNode;
        return head;
    }
    
    struct Node * temp = head;
    head=newNode;
    newNode->next=temp;
    temp->prev=newNode;

    count++;

    return head;
}

struct Node * deleteAtBeginning(struct Node * head){
    // count keyword is declared globally.
    if(head->next==NULL && head->prev==NULL){
        printf("Value deleted = %d", head->data);
        head=NULL;
        count--;
        return head;
    }

    printf("Value deleted : %d\n", head->data);

    struct Node * temp = head;
    head = head->next;
    head->prev=NULL;

    count--;

    return head;
}

struct Node * deleteAtEnd(struct Node * head){
    // count keyword is declared globally.
    if(head->next==NULL && head->prev==NULL){
        printf("Value deleted = %d", head->data);
        head=NULL;
        count--;
        return head;
    }

    struct Node * temp = head;

    while(temp->next->next!=NULL){
        temp=temp->next;
    }

    printf("Value deleted : %d\n", temp->next->data);
    temp->next=NULL;

    count--;

    return head;
}

struct Node * deleteAtSpecificPosition(struct Node * head, int pos){
    // count keyword is declared globally.
    if(pos==1){
        return deleteAtBeginning(head);
    }
    if(pos==count){
        return deleteAtEnd(head);
    }

    int i=0;
    struct Node * temp = head;
    while(i!=pos-2){
        temp = temp->next;
        i++;
    }
    printf("Value deleted : %d\n", temp->next->data);
    temp->next = temp->next->next;
    temp->next->prev=temp;

    return head;

}

void printList(struct Node *head){
    while (head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}


int main(){
    struct Node *head = NULL; int data;

    for (int i = 0; i < 5; i++){
        printf("Enter data : ");
        scanf("%d", &data);
        head = insertAtStart(head,data);
    }

    printList(head);
    getch();
    head = deleteAtBeginning(head);
    getch();printList(head);
    head = deleteAtEnd(head);
    getch();printList(head);
    head = deleteAtSpecificPosition(head,2);
    getch();
    printList(head);

    return 0;
}