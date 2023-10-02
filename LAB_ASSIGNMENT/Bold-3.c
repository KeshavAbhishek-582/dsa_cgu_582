#include <stdio.h>
#include <stdlib.h>

struct Node1{
    int data;
    struct Node * next;
};

struct Node2{
    int data;
    struct Node * next;
};


void showLinkList(struct Node1 *ptr)
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


struct Node1 *insertFirst1(struct Node1 * head){
    struct Node1 * new = (struct Node1*)malloc(sizeof(struct Node1));
    printf("Enter value for struct 1 : ");
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

struct Node2 *insertFirst2(struct Node2 * head){
    struct Node2 * new = (struct Node2*)malloc(sizeof(struct Node2));
    printf("Enter value for struct 2 : ");
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

int main(){
    struct Node1 * head1=NULL;
    for (int i = 0; i < 5; i++)
    {
        head1 = insertFirst1(head1);
    }

    printf("\n\n");

    struct Node2 * head2=NULL;
    for (int i = 0; i < 5; i++)
    {
        head2 = insertFirst2(head2);
    }

    showLinkList(head1);
    
    printf("\n\n");
    
    // head2 = (struct Node1 *)head2;

    // showLinkList(head2);
    
    
    return 0;
}