#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

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
        head = newNode;
        return head;
    }
    
    struct Node * temp = head;
    head=newNode;
    newNode->next=temp;
    temp->prev=newNode;

    return head;
}

struct Node *reverseDoublyLinkedList(struct Node *head)
{
    struct Node *temp = NULL;
    struct Node *current = head;

    while (current != NULL){
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL){
        head = temp->prev;
    }

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

    printf("Original Doubly Linked List: ");
    printList(head);

    head = reverseDoublyLinkedList(head);

    printf("Reversed Doubly Linked List: ");
    printList(head);

    return 0;
}