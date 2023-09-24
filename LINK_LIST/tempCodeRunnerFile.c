#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
void linked_display(struct node *current){
    printf("\n      :-----Single linked list:-----\n");
    while (current!=NULL)
    {
        printf("%d ->",current->data);
        current=current->next;
    }
    printf("NULL");
}
/*------------------------------------------------INSERTION------------------------------------------------*/
struct node* insertatfirst(struct node *head){
    struct node new=(struct node)malloc(sizeof(struct node));
    printf("\nEnter data for new node: ");
    scanf("%d",&new->data);
    new->next=head;
    return new;
}

struct node*insertatlast(struct node *head){
    struct node*temp=head;
    struct node*lastnew=(struct node*)malloc(sizeof(struct node));
    while(temp->next!=NULL){
        temp=temp->next;
    }
    printf("\nEnter data for last new node: ");
    scanf("%d",&lastnew->data);
    temp->next=lastnew;
    lastnew->next=NULL;
    return head;
}
struct node*insertatposition(struct node *head){
    struct node* counttemp=head;
    struct node*temp=head;
    int count=1;//counting node
    int pos;
    while (counttemp->next!=NULL)
    {
        counttemp=counttemp->next;
        count++;
    }
    printf("\nTotal Node in the Linked list is %d\n",count);
    printf("Enter the position where you want to insert a node: ");
    scanf("%d",&pos);
    if (pos<1 || pos>count)
    {
        printf("!!Invalid Position!!");
    }
    else{
        struct node * newpos=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data for %d position :",pos);
        scanf("%d",&newpos->data);
        for (int i = 0; i < pos-2; i++)
        {
            temp=temp->next;
        }
        newpos->next=temp->next;
        temp->next=newpos;  
        return head;
    }
}
/*------------------------------------------------DELETION------------------------------------------------*/
struct node * deletionatfirst(struct node* head){
    struct node*temp=head;

    head=head->next;
    printf("\n%d is De-linked from beginning  ",temp->data);
    temp->next=NULL;
    free(temp);
    return head;

}

struct node *deletionatlast(struct node *head){
    struct node*temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    struct node*temp2=temp->next;
    temp->next=NULL;
    free(temp2);
    return head;
    
}

int main(){
    struct node *head;
    struct node *second;
    struct node *third;

    head=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));    
    third=(struct node *)malloc(sizeof(struct node));


    //link first and second node
    head->data=10;
    head->next=second;
    //link second and third node
    second->data=20;
    second->next=third;
    //terminate the list at third node
    third->data=30;
    third->next=NULL;
    linked_display(head);
    head=insertatfirst(head);
    linked_display(head);
    head=insertatlast(head);
    linked_display(head);
    head=insertatposition(head);
    linked_display(head);
    head=deletionatfirst(head);
    linked_display(head);
    head=deletionatlast(head);
    linked_display(head);

    return 0;
}