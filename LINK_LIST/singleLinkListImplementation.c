#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *showLinkList(struct Node *ptr)
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

struct Node *insertFirst(struct Node * head);
struct Node *insertAtSpecificPosition(struct Node * head);
struct Node *insertEnd(struct Node * head);

//

struct Node *deleteFirst(struct Node *head);
struct Node *deleteAtSpecificPosition(struct Node *head);
struct Node *deleteEnd(struct Node *head);


struct Node *insertFirst(struct Node * head){
    struct Node * new = (struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter value : ");
    scanf("%d", &new->data);
    if(head==NULL){
        head=new;
        head->next=NULL;
        return head;
    }
    new->next=head;
    head=new;
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

struct Node *insertEnd(struct Node * head){
    if(head==NULL){
        return insertFirst(head);
    }
    struct Node * new = (struct Node*)malloc(sizeof(struct Node));
    struct Node * temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    printf("\nEnter value : ");
    scanf("%d", &new->data);
    new->next=NULL;
    temp->next=new;
    return head;
}

struct Node *deleteFirst(struct Node *head)
{
    struct Node *ptr = head;
    if (head == NULL)
    {
        printf("Linked List Empty.");
        return head;
    }
    else
    {
        head = head->next;
        printf("\nDeleted value : %d", ptr->data);
    }
    free(ptr);
    return head;
}

struct Node *deleteAtSpecificPosition(struct Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    int count = 0;
    struct Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    temp = head;

    int pos;
    printf("\nEnter position : ");
    scanf("%d", &pos);printf("\n");

    if (pos == 1){
        return deleteFirst(head);
    }

    if (pos == count){
        return deleteEnd(head);
    }

    if (pos > count){
        printf("\nInvalid Position\n");
    }
    else{
        for (int i = 0; i < pos - 2; i++){
            temp = temp->next;
        }
    }

    struct Node *temp_temp = temp->next;
    printf("\nDeleted value : %d", temp_temp->data);
    temp->next = temp_temp->next;
    free(temp_temp);
    return head;
}

struct Node *deleteEnd(struct Node *head)
{
    struct Node *temp = head;
    if (head == NULL){
        printf("\nLinked list is empty.\n");
        return head;
    }
    if (head->next == NULL){
        printf("\nDeleted value : %d", head->data);
        head = NULL;
    }
    else{
        while (temp->next->next != NULL){
            temp = temp->next;
        }
        struct Node *temp_temp = temp->next;
        printf("\nDeleted value : %d", temp_temp->data);
        free(temp_temp);
        temp->next = NULL;
    }

    return head;
}

int main(){
    char opt;

    struct Node *head=NULL;

    do{

        printf("\n\n1. Insertion at beginning\n2. Insertion at specific position\n3. Insertion at end\n\n4. Deletion at beginning\n5. Deletion at specific position\n6. Deletion at end\n\n0. To Travserse Link List\n\n\nChoose option :- ");

        opt=getche();

        switch (opt)
        {
        case '1':
            head=insertFirst(head);
            break;
        
        case '2':
            head=insertAtSpecificPosition(head);
            break;
        
        case '3':
            head=insertEnd(head);
            break;
        
        case '4':
            head=deleteFirst(head);
            break;
        
        case '5':
            head=deleteAtSpecificPosition(head);
            break;
        
        case '6':
            head=deleteEnd(head);
            break;
        
        case '0':
            showLinkList(head);
            break;
        
        default:
            printf("\nInvalid Option");
            exit(0);
            // break;
        }
    }while(1);

    return 0;
}